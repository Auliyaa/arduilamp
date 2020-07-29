#pragma once

#include "effects/effect.h"

class sunlight_effect_t : public effect_t
{
    CRGB current;

    virtual const char *name() const { return "sunlight"; }
    virtual void setup();
    virtual void set_speed(int, size_t idx, size_t sz);
    virtual void loop();
};