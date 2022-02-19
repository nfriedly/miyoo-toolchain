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
template<typename Fmt>
class TFirstOrderFeeback
{
public:
  TFirstOrderFeeback()
  {
    m_Coe = 0.0;
    m_Old = 0.0;
  }

  void SetCoefficient(Fmt Coe)
  {
    m_Coe = Coe;
  }

  void Reset()
  {
    m_Old = 0.0;
  }

  inline Fmt Filter(Fmt In)
  {
    Fmt out = In - m_Old*m_Coe;
    m_Old = out;

    return out;
  }

private:
  Fmt m_Old;
  Fmt m_Coe;
};
}
