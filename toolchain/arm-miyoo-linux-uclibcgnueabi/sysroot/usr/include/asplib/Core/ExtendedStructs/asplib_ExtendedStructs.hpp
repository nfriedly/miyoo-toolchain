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


namespace asplib
{
#define ASPLIB_EXTENDED_STRUCT(Struct)      public TExtendedStructs<Struct>
#define ASPLIB_EXTENDED_STRUCT_REGISTER(ID) TExtendedStructs(ID)


class CExtendedStructs
{
  friend class CExtendedStructContainer;
public:
  CExtendedStructs(size_t Size, int32_t StructID);

  const int32_t   ID;

private:
  const size_t    size;
  const size_t    byteOffset;
};


template<class T>
class TExtendedStructs : public CExtendedStructs
{
public:
  TExtendedStructs(int32_t StructID) : CExtendedStructs(sizeof(T), StructID) {}
};
}
