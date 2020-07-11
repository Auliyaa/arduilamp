#include "effects/random.h"

void random_effect_t::setup()
{
    rainbow_effect_t::setup();

    for (size_t ii = 0; ii < LED_COUNT; ++ii)
    {
        hue[ii] = random(256);
    }
    apply_leds();
}

void random_effect_t::loop()
{
    for (size_t ii = 0; ii < LED_COUNT; ++ii)
    {
        hue[ii] += random(speed);
        if (hue[ii] > 255) hue[ii] -= 255.0;
    }
    apply_leds();
}