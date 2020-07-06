#pragma once

#include <Arduino.h>

struct btn_t
{
    uint8_t pin;
    uint8_t state;

    void set_pin(uint8_t);
    bool read();
};