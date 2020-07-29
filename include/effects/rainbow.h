#pragma once

#include "effects/effect.h"

// rainbow effect
struct rainbow_effect_t : public effect_t
{
    virtual const char* name() const { return "rainbow"; }

    static constexpr const int SATURATION = 255;
    static constexpr const int VALUE = 255;

    float hue[LED_GROUP_COUNT];
    float speed;

    void apply_leds();

    virtual void setup();
    virtual void set_speed(int s, size_t, size_t);
    virtual void loop();
};