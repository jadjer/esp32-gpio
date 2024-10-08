// Copyright 2024 Pavel Suprunov
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

//
// Created by jadjer on 30.08.22.
//

#pragma once

#include <cstdint>

#include "gpio/PinLevel.hpp"
#include "gpio/interface/InputPin.hpp"

/**
 * @namespace gpio
 */
namespace gpio {

/**
 * @class Pin
 * @brief
 */
class InputPin : public interface::InputPin<PinLevel> {
public:
  explicit InputPin(std::uint8_t numberOfPin, PinLevel defaultLevel = PIN_LEVEL_LOW);
  ~InputPin() override = default;

public:
  [[nodiscard]] PinLevel getLevel() const override;
  [[nodiscard]] std::uint32_t getCount() const override;
  [[nodiscard]] std::uint32_t getDelay() const override;

private:
  void process();

private:
  static void isr(void *arg);

private:
  std::uint8_t const m_numberOfPin;

private:
  PinLevel const m_defaultLevel;

private:
  PinLevel m_level;

private:
  std::uint32_t m_count;
  std::uint32_t m_lastUpdate_InMicroseconds;
};

}// namespace gpio
