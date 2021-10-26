#pragma once

/* Copyright (C) 2014-2015 Achim Turan, Achim.Turan@o2online.de
 * https://github.com/AchimTuran/asplib
 *
 * This file is part of asplib (Achim's Signal Processing LIBrary)
 *
 * asplib (Achim's Signal Processing LIBrary) is free software:
 * you can redistribute it and/or modify it under the terms of the
 * GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * asplib (Achim's Signal Processing LIBrary) is distributed
 * in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with asplib (Achim's Signal Processing LIBrary).
 * ifnot, see <http://www.gnu.org/licenses/>.
 *
 */



#include "Core/os/asplib_os.h"
#include "Core/Constants_Typedefs/asplib_Typedefs.h"
#include "Core/Exceptions/asplib_StringException.h"

#include <map>
#include <string>
#include "Core/AutoFactory/asplib_TProductStatistics.hpp"


namespace asplib
{
template <class ProductInterface, typename TypeID, typename TFmt, class MetaData>
class TAutoFactory
{
private:
  typedef ProductInterface* (*ProductCreateCallback)();
  typedef int64_t (*ProductStatisticCallback)();
  typedef struct ProductCallbacks_t
  {
    ProductCreateCallback     CreateProduct;
    ProductStatisticCallback  GetActiveProducts;
    ProductStatisticCallback  GetCreatedProducts;
    ProductStatisticCallback  GetDestroyedProducts;
  }ProductCallbacks_t;

  typedef struct ProductKey_t
  {
    TypeID  ProductID;
    TFmt    FmtIn;
    TFmt    FmtOut;

    ProductKey_t(TypeID ID, TFmt In, TFmt Out)
    {
      ProductID = ID;
      FmtIn     = In;
      FmtOut    = Out;
    }
  }ProductKey_t;

  class CProductKeyCmp
  {
  public:
    bool operator()(const ProductKey_t &Obj1, const ProductKey_t &Obj2) const
    {
      return  Obj1.ProductID < Obj2.ProductID || (Obj1.ProductID == Obj2.ProductID  && Obj1.FmtIn < Obj2.FmtIn) &&
              Obj1.FmtIn < Obj2.FmtIn         || (Obj1.FmtIn == Obj2.FmtIn          && Obj1.FmtOut < Obj2.FmtOut);
    }
  };

  typedef std::map<ProductKey_t, ProductCallbacks_t, CProductKeyCmp> ProductMap_t;

public:
  template<class Product, TypeID ID, TFmt TFmtIn, TFmt TFmtOut>
  class TRegisterProduct : public TProductStatistics<Product>
  {
    friend class TAutoFactory<ProductInterface, TypeID, TFmt, MetaData>;

  public:
    TRegisterProduct() : m_HiddenProductID(ProductID) {} // force registration by assinging ProductID to m_HiddenProductID

    static const TypeID ProductID;
    static const TFmt   FmtIn;
    static const TFmt   FmtOut;

    static ProductInterface* Create() { return dynamic_cast<ProductInterface*>(new Product); }

  private:
    const  TypeID                    m_HiddenProductID; // force initialization for m_HiddenProductID
    static ProductCallbacks_t  m_Callbacks;
  };


  static ASPLIB_ERR Create(TypeID ProductID, TFmt FmtIn, TFmt FmtOut, ProductInterface *&InterfacePtr)
  {
    ProductKey_t productKey(ProductID, FmtIn, FmtOut);
    typename ProductMap_t::iterator iter = GetProductMap().find(productKey);
    if (iter == GetProductMap().end())
    {
      InterfacePtr = NULL;
      return ASPLIB_ERR_UNKNOWN_FACTORY_PRODUCT;
    }

    InterfacePtr = (*iter).second.CreateProduct();
    return ASPLIB_ERR_NO_ERROR;
  }

  static ASPLIB_ERR Destroy(ProductInterface *&Product)
  {
    if (Product)
    {
      delete Product;
      Product = NULL;
    }

    return ASPLIB_ERR_NO_ERROR;
  }

  static TypeID RegisterProduct(TypeID ProductID, TFmt FmtIn, TFmt FmtOut, ProductCallbacks_t Callbacks)
  {
    ProductKey_t productKey(ProductID, FmtIn, FmtOut);
    typename ProductMap_t::iterator iter = GetProductMap().find(productKey);
    if (iter == GetProductMap().end())
    {// only register not yet known products
      GetProductMap()[productKey] = Callbacks;
    }

    return ProductID;
  }

  // TODO: return value should be the type ASPLIB_ERR!
  static int64_t GetActiveProducts(TypeID ProductID, TFmt FmtIn, TFmt FmtOut)
  {
    ProductKey_t productKey(ProductID, FmtIn, FmtOut);
    typename ProductMap_t::iterator iter = GetProductMap().find(productKey);
    if (iter == GetProductMap().end())
    {
      return -1;
    }

    return (*iter).second.GetActiveProducts();
  }

  // TODO: return value should be the type ASPLIB_ERR!
  static int64_t GetCreatedProducts(TypeID ProductID, TFmt FmtIn, TFmt FmtOut)
  {
    ProductKey_t productKey(ProductID, FmtIn, FmtOut);
    typename ProductMap_t::iterator iter = GetProductMap().find(productKey);
    if (iter == GetProductMap().end())
    {
      return -1;
    }

    return (*iter).second.GetCreatedProducts();
  }

  // TODO: return value should be the type ASPLIB_ERR!
  static int64_t GetDestroyedProducts(TypeID ProductID, TFmt FmtIn, TFmt FmtOut)
  {
    ProductKey_t productKey(ProductID, FmtIn, FmtOut);
    typename ProductMap_t::iterator iter = GetProductMap().find(productKey);
    if (iter == GetProductMap().end())
    {
      return -1;
    }

    return (*iter).second.GetDestroyedProducts();
  }

  static const std::string Name;

private:
  // Force initialization and creation of product map by using a static method and a std::map
  inline static ProductMap_t& GetProductMap()
  {
    static ProductMap_t s_Products;

    return s_Products;
  }
};

template <class ProductInterface, typename TypeID, typename TFmt, class MetaData>
const std::string TAutoFactory<ProductInterface, TypeID, TFmt, MetaData>::Name = MetaData::Name;

template <class ProductInterface, typename TypeID, typename TFmt, class MetaData>
template<class Product, TypeID ID, TFmt TFmtIn, TFmt TFmtOut>
const TypeID TAutoFactory<ProductInterface, TypeID, TFmt, MetaData>::TRegisterProduct<Product, ID, TFmtIn, TFmtOut>::ProductID =
TAutoFactory<ProductInterface, TypeID, TFmt, MetaData>::RegisterProduct(ID, TFmtIn, TFmtOut, TAutoFactory<ProductInterface, TypeID, TFmt, MetaData>::TRegisterProduct<Product, ID, TFmtIn, TFmtOut>::m_Callbacks);

template <class ProductInterface, typename TypeID, typename TFmt, class MetaData>
template<class Product, TypeID ID, TFmt TFmtIn, TFmt TFmtOut>
const TFmt TAutoFactory<ProductInterface, TypeID, TFmt, MetaData>::TRegisterProduct<Product, ID, TFmtIn, TFmtOut>::FmtIn = TFmtIn;

template <class ProductInterface, typename TypeID, typename TFmt, class MetaData>
template<class Product, TypeID ID, TFmt TFmtIn, TFmt TFmtOut>
const TFmt TAutoFactory<ProductInterface, TypeID, TFmt, MetaData>::TRegisterProduct<Product, ID, TFmtIn, TFmtOut>::FmtOut = TFmtOut;

template <class ProductInterface, typename TypeID, typename TFmt, class MetaData>
template<class Product, TypeID ID, TFmt TFmtIn, TFmt TFmtOut>
typename TAutoFactory<ProductInterface, TypeID, TFmt, MetaData>::ProductCallbacks_t
TAutoFactory<ProductInterface, TypeID, TFmt, MetaData>::TRegisterProduct<Product, ID, TFmtIn, TFmtOut>::m_Callbacks =
{
  TAutoFactory<ProductInterface, TypeID, TFmt, MetaData>::TRegisterProduct<Product, ID, TFmtIn, TFmtOut>::Create,
  TAutoFactory<ProductInterface, TypeID, TFmt, MetaData>::TRegisterProduct<Product, ID, TFmtIn, TFmtOut>::GetActiveProducts,
  TAutoFactory<ProductInterface, TypeID, TFmt, MetaData>::TRegisterProduct<Product, ID, TFmtIn, TFmtOut>::GetCreatedProducts,
  TAutoFactory<ProductInterface, TypeID, TFmt, MetaData>::TRegisterProduct<Product, ID, TFmtIn, TFmtOut>::GetDestroyedProducts
};
}
