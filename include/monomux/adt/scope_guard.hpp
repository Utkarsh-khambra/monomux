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
#pragma once

#include "adt/unique_scalar.hpp"

namespace monomux
{

/// A simple scope guard that fires a callback function (in most cases, a
/// lambda passed to the constructor) when constructed, and when destructed.
///
/// Example:
///
///     scope_guard RAII{[] { enter(); }, [] { exit(); }};
template <typename EnterFunction, typename ExitFunction>
struct scope_guard // NOLINT(readability-identifier-naming)
{
  scope_guard(EnterFunction&& Enter, ExitFunction&& Exit) : Exit(Exit)
  {
    Enter();
    Alive = true;
  }

  ~scope_guard()
  {
    if (Alive)
      Exit();
  }

  scope_guard() = delete;
  scope_guard(const scope_guard&) = delete;
  scope_guard(scope_guard&&) = delete;
  scope_guard& operator=(const scope_guard&) = delete;
  scope_guard& operator=(scope_guard&&) = delete;

private:
  bool Alive;
  ExitFunction Exit;
};

} // namespace monomux
