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

#include "../../../../include/cxx/game_struct/d2_belt_record/d2_belt_record_wrapper.hpp"

namespace d2 {

BeltRecord_Wrapper::BeltRecord_Wrapper(BeltRecord* belt_record) noexcept :
    belt_record_(CreateVariant(belt_record)) {
}

BeltRecord_Wrapper::BeltRecord_Wrapper(
    const BeltRecord_Wrapper& other
) noexcept = default;

BeltRecord_Wrapper::BeltRecord_Wrapper(
    BeltRecord_Wrapper&& other
) noexcept = default;

BeltRecord_Wrapper::~BeltRecord_Wrapper() noexcept = default;

BeltRecord_Wrapper& BeltRecord_Wrapper::operator=(
    const BeltRecord_Wrapper& other
) noexcept = default;

BeltRecord_Wrapper& BeltRecord_Wrapper::operator=(
    BeltRecord_Wrapper&& other
) noexcept = default;

BeltRecord_View BeltRecord_Wrapper::operator[](
    std::size_t index
) const noexcept {
  BeltRecord_View view(this->Get());

  return view[index];
}

BeltRecord_Wrapper BeltRecord_Wrapper::operator[](
    std::size_t index
) noexcept {
  const auto* const_this = this;

  return const_cast<BeltRecord*>((*const_this)[index].Get());
}

BeltRecord_Wrapper::operator BeltRecord_View() const noexcept {
  return BeltRecord_View(this->Get());
}

BeltRecord* BeltRecord_Wrapper::Get() noexcept {
  const auto* const_this = this;

  return const_cast<BeltRecord*>(const_this->Get());
}

const BeltRecord* BeltRecord_Wrapper::Get() const noexcept {
  return std::visit(
      [](const auto& actual_belt_record) {
        return reinterpret_cast<const BeltRecord*>(actual_belt_record);
      },
      this->belt_record_
  );
}

void BeltRecord_Wrapper::Assign(BeltRecord_View src) noexcept {
  std::visit(
      [&src](auto& actual_dest) {
        using Dest_T = decltype(actual_dest);
        using ActualSrc_T = const std::remove_pointer_t<
            std::remove_reference_t<Dest_T>
        >*;

        const auto* actual_src = reinterpret_cast<ActualSrc_T>(src.Get());

        *actual_dest = *actual_src;
      },
      this->belt_record_
  );
}

unsigned char BeltRecord_Wrapper::GetNumSlots() const noexcept {
  BeltRecord_View view(this->Get());

  return view.GetNumSlots();
}

void BeltRecord_Wrapper::SetNumSlots(unsigned char num_slots) noexcept {
  std::visit(
      [num_slots](auto& actual_positional_rectangle) {
        actual_positional_rectangle->num_slots = num_slots;
      },
      this->belt_record_
  );
}

PositionalRectangle_View
BeltRecord_Wrapper::GetSlotPositions() const noexcept {
  BeltRecord_View view(this->Get());

  return view.GetSlotPositions();
}

PositionalRectangle_Wrapper BeltRecord_Wrapper::GetSlotPositions() noexcept {
  const auto* const_this = this;

  return const_cast<PositionalRectangle*>(
      const_this->GetSlotPositions().Get()
  );
}

BeltRecord_Wrapper::WrapperVariant BeltRecord_Wrapper::CreateVariant(
    BeltRecord* belt_record
) {
  return reinterpret_cast<BeltRecord_1_00*>(belt_record);
}

} // namespace d2
