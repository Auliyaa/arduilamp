#include "effects/rainbow.h"

struct random_effect_t: public rainbow_effect_t
{
    virtual const char *name() const { return "random"; }

    virtual void setup();
    virtual void loop();
};