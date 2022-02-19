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
class CExtendedStructContainer
{
public:
  CExtendedStructContainer();
  CExtendedStructContainer(const CExtendedStructContainer &Container);
  ~CExtendedStructContainer();

  CExtendedStructContainer& operator= (const CExtendedStructContainer &Container);

  ASPLIB_ERR SaveStruct(void *Data);
  ASPLIB_ERR RestoreStruct(void *Options);
  operator void*(); // return the saved data and the extended struct information

private:
  uint8_t   *m_Data;
  size_t    m_StructSize;
  size_t    m_ReservedSize;
  
  int32_t  m_StructID;
};
}
