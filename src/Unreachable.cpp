/**
 * Copyright (C) 2022 Whisperity
 *
 * SPDX-License-Identifier: GPL-3.0
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <iostream>

#include "monomux/unreachable.hpp"

[[noreturn]] void
unreachable_impl(const char* Msg, const char* File, std::size_t LineNo)
{
  std::cerr << "FATAL! UNREACHABLE executed";
  if (File)
    std::cerr << " at " << File << ':' << LineNo;

  if (Msg)
    std::cerr << ": " << Msg << '\n';
  else
    std::cerr << '\n';

  // [[noreturn]]
  std::abort();
  std::_Exit(-1);
}
