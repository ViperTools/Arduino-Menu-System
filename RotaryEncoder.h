#pragma once

#include "Arduino.h"
#include "Menu.h"

namespace RotaryEncoder {
    extern bool buttonPressed;
    extern volatile byte encoderPosition, oldEncoderPosition;

    extern void init();
    extern bool update(Menu& menu);
};