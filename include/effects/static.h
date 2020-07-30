#pragma once

#include "effects/effect.h"

template<int OFFSET>
class static_effect_t: public effect_t
{
    int hue;

    virtual const char* name() const { return "static"; }
    virtual void setup() {}

    virtual void set_speed(int, size_t idx, size_t sz)
    {
        hue = ((idx * 255) / sz) + OFFSET;
        if (hue > 255) hue -= 255;
    }

    virtual void loop()
    {
        CHSV hsv(hue, 255, 255);
        CRGB rgb;
        hsv2rgb_rainbow(hsv, rgb);

        for (size_t ii = 0; ii < LED_COUNT; ++ii)
        {
            board.leds[ii] = rgb;
        }
    }
};