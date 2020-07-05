#pragma once

#include "defs.h"
#include "effects/effect.h"

// rainbow effect
struct rainbow_effect_t : public effect_t
{
    static constexpr const int SATURATION = 255;
    static constexpr const int VALUE = 255;
    static constexpr const int HSTEP = 1;

    CHSV hsv_leds[LED_COUNT];
    int speed;

    void apply_leds();

    virtual void setup();

    virtual void set_speed(int s);

    virtual void loop();
};