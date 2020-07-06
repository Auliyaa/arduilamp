#pragma once

#include "effects/effect.h"

class comet_effect_t : public effect_t
{
    size_t pos;
    size_t speed;

    virtual const char *name() const { return "comet"; }
    virtual void setup();
    virtual void set_speed(int, size_t, size_t);
    virtual void loop();
};