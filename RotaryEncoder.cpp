#include "RotaryEncoder.h"

namespace RotaryEncoder
{
    bool buttonPressed = false;
    volatile bool dtFlag = 0, clkFlag = 0;
    volatile byte encoderPosition = 0, oldEncoderPosition = 0;
    volatile byte reading = 0;
    volatile byte direction = 0;

    constexpr int dtPin = 2;
    constexpr int clkPin = 3;
    constexpr int swPin = 4;

    void dtPinInterrupt() {
        cli();

        if ((PORTA.IN & PIN0_bm) && (PORTF.IN & PIN5_bm) && dtFlag) {
            --encoderPosition;
            dtFlag = clkFlag = 0;
            direction = 0;
        }
        else if (PORTA.IN & PIN0_bm) {
            clkFlag = 1;
        }

        sei();
    }

    void clkPinInterrupt() {
        cli();

        if ((PORTA.IN & PIN0_bm) && (PORTF.IN & PIN5_bm) && clkFlag) {
            ++encoderPosition;
            dtFlag = clkFlag = 0;
            direction = 1;
        }
        else if (PORTB.IN & PIN5_bm) {
            dtFlag = 1;
        }

        sei();
    }

    void init() {
        pinMode(dtPin, INPUT_PULLUP);
        pinMode(clkPin, INPUT_PULLUP);
        pinMode(swPin, INPUT_PULLUP);
        attachInterrupt(digitalPinToInterrupt(dtPin), dtPinInterrupt, RISING);
        attachInterrupt(digitalPinToInterrupt(clkPin), clkPinInterrupt, RISING);
    }

    // Updates the rotary encoder, returns whether there was an action or not
    bool update(Menu& menu) {
        if (oldEncoderPosition != encoderPosition) {
            if (direction) {
                menu.up();
            }
            else {
                menu.down();
            }

            oldEncoderPosition = encoderPosition;

            return true;
        }

        if (digitalRead(swPin) == buttonPressed) {
            buttonPressed = !buttonPressed;

            if (buttonPressed) {
                menu.clicked();

                return true;
            }
        }

        return false;
    }
}