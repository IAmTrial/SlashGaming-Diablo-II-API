/**
 * SlashGaming Diablo II Modding API for C++
 * Copyright (C) 2018-2020  Mir Drualga
 *
 * This file is part of SlashGaming Diablo II Modding API for C++.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as published
 *  by the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Additional permissions under GNU Affero General Public License version 3
 *  section 7
 *
 *  If you modify this Program, or any covered work, by linking or combining
 *  it with Diablo II (or a modified version of that game and its
 *  libraries), containing parts covered by the terms of Blizzard End User
 *  License Agreement, the licensors of this Program grant you additional
 *  permission to convey the resulting work. This additional permission is
 *  also extended to any combination of expansions, mods, and remasters of
 *  the game.
 *
 *  If you modify this Program, or any covered work, by linking or combining
 *  it with any Graphics Device Interface (GDI), DirectDraw, Direct3D,
 *  Glide, OpenGL, or Rave wrapper (or modified versions of those
 *  libraries), containing parts not covered by a compatible license, the
 *  licensors of this Program grant you additional permission to convey the
 *  resulting work.
 *
 *  If you modify this Program, or any covered work, by linking or combining
 *  it with any library (or a modified version of that library) that links
 *  to Diablo II (or a modified version of that game and its libraries),
 *  containing parts not covered by a compatible license, the licensors of
 *  this Program grant you additional permission to convey the resulting
 *  work.
 */

#ifndef SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_FILE_D2_CEL_FILE_STRUCT_HPP_
#define SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_FILE_D2_CEL_FILE_STRUCT_HPP_

#include <cstddef>
#include <cstdint>
#include <type_traits>
#include <variant>

#include "../../game_undefined.hpp"
#include "../d2_cel/d2_cel_struct.hpp"

#include "../../../dllexport_define.inc"

namespace d2 {

/**
 * Generic struct declaration
 */

struct CelFile;

/**
 * Version-specific struct definitions
 */

#pragma pack(push, 1)

/* sizeof: 0x18 + sizeof(cels) */ struct CelFile_1_00 {
  /* 0x00 */ std::uint32_t version;
  /* 0x04 */ std::uint32_t flags;
  /* 0x08 */ mapi::UndefinedByte unknown_0x08[0x10 - 0x08];
  /* 0x10 */ std::uint32_t num_directions;
  /* 0x14 */ std::uint32_t num_frames;

  // This field has variable length.
  /* 0x18 */ Cel_1_00* cels[1];
};

static_assert(std::is_standard_layout_v<CelFile_1_00>);
static_assert(std::is_trivial_v<CelFile_1_00>);
static_assert(sizeof(CelFile_1_00) >= 0x18);
static_assert(offsetof(CelFile_1_00, version) == 0x00);
static_assert(offsetof(CelFile_1_00, flags) == 0x04);
static_assert(offsetof(CelFile_1_00, num_directions) == 0x10);
static_assert(offsetof(CelFile_1_00, num_frames) == 0x14);

#pragma pack(pop)

/**
 * STL DLL interface
 */

DLL_TEMPL_EXTERN template class DLLEXPORT std::variant<
    CelFile_1_00
>;

DLL_TEMPL_EXTERN template class DLLEXPORT std::variant<
    CelFile_1_00*
>;

DLL_TEMPL_EXTERN template class DLLEXPORT std::variant<
    const CelFile_1_00*
>;

} // namespace d2

#include "../../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_STRUCT_D2_CEL_FILE_D2_CEL_FILE_STRUCT_HPP_
