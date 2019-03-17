/**
 * SlashGaming Diablo II Modding API
 * Copyright (C) 2018-2019  Mir Drualga
 *
 * This file is part of SlashGaming Diablo II Modding API.
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
 *  it with any Glide wrapper (or a modified version of that library),
 *  containing parts not covered by a compatible license, the licensors of
 *  this Program grant you additional permission to convey the resulting
 *  work.
 */

#ifndef SGD2MAPI_CXX_GAME_PATCH_GAME_PATCH_BASE_HPP_
#define SGD2MAPI_CXX_GAME_PATCH_GAME_PATCH_BASE_HPP_

#include "../game_address.hpp"
#include "game_patch_interface.hpp"

#include <cstdint>
#include <cstdlib>
#include <vector>

#include "../../dllexport_define.inc"

namespace sgd2mapi {

/**
 * An interface for game patch implementations that is capable of replacing
 * game memory with that in a buffer and restoring the original state of the
 * game memory.
 */
class DLLEXPORT GamePatchBase
    : public GamePatchInterface {
 public:
  ~GamePatchBase(
      void
  ) override;

  void
  Apply(
      void
  ) final override;

  void
  Remove(
      void
  ) final override;

  /**
   * Returns the game address used by this patch.
   */
  const GameAddress&
  game_address(
      void
  ) const noexcept;

  /**
   * Returns whether or not the patch has been applied.
   */
  bool
  is_patch_applied(
      void
  ) const noexcept;

  /**
   * Returns the buffer storing the patch data.
   */
  const std::vector<std::uint8_t>&
  patch_buffer(
      void
  ) const noexcept;

  /**
   * Returns the buffer storing the original data before patching.
   */
  const std::vector<std::uint8_t>&
  old_bytes(
      void
  ) const noexcept;

  /**
   * Returns the number of bytes needed to apply this patch.
   */
  std::size_t
  patch_size(
      void
  ) const noexcept;

 protected:
  /**
   * Initializes this patch's target game address and patch buffer.
   */
  GamePatchBase(
      const GameAddress& game_address,
      const std::vector<std::uint8_t>& patch_buffer
  );

  /**
   * Initializes this patch's target game address and patch buffer.
   */
  GamePatchBase(
      GameAddress&& game_address,
      const std::vector<std::uint8_t>& patch_buffer
  );

  /**
   * Initializes this patch's target game address and patch buffer.
   */
  GamePatchBase(
      const GameAddress& game_address,
      std::vector<std::uint8_t>&& patch_buffer
  );

  /**
   * Initializes this patch's target game address and patch buffer.
   */
  GamePatchBase(
      GameAddress&& game_address,
      std::vector<std::uint8_t>&& patch_buffer
  );

  GamePatchBase(
      const GamePatchBase&
  );

  GamePatchBase(
      GamePatchBase&&
  ) noexcept;

  GamePatchBase&
  operator=(
      const GamePatchBase&
  );

  GamePatchBase&
  operator=(
      GamePatchBase&&
  ) noexcept;

 private:
  GameAddress game_address_;
  bool is_patch_applied_;
  std::vector<std::uint8_t> old_bytes_;
  std::vector<std::uint8_t> patch_buffer_;
};

} // namespace sgd2mapi

#include "../../dllexport_undefine.inc"
#endif // SGD2MAPI_CXX_GAME_PATCH_GAME_PATCH_BASE_HPP_
