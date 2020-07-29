#pragma once

#include "effects/effect.h"

// hue effect
struct hue_effect_t : public effect_t
{
    virtual const char *name() const { return "hue"; }

    static constexpr const int SATURATION = 255;
    static constexpr const int VALUE = 255;
    static constexpr const int HSTEP = 1;

    float hue;
    float speed;

    void apply_leds();

    virtual void setup();
    virtual void set_speed(int s, size_t, size_t);
    virtual void loop();
};