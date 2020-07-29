#pragma once

#include "effects/effect.h"

class static_effect_t: public effect_t
{
    int hue;

    virtual const char* name() const { return "static"; }
    virtual void setup();
    virtual void set_speed(int, size_t idx, size_t sz);
    virtual void loop();
};