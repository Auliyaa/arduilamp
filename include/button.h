#pragma once

#include <Arduino.h>

template<uint8_t P>
struct btn_t
{
    uint8_t state;

    void setup()
    {
        pinMode(P, INPUT);
    }

    bool read()
    {
        int s = digitalRead(P);
        bool r = state == LOW && s == HIGH;
        state = s;
        return r;
    }
};