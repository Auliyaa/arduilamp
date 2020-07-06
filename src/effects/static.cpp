#include "effects/static.h"

#include "defs.h"

void static_effect_t::setup()
{
}

void static_effect_t::set_speed(int s)
{
    hue = (s * 255) / 100;
    hue=0;
}

void static_effect_t::loop()
{
    CHSV hsv(hue, 255, 255);
    CRGB rgb;
    hsv2rgb_rainbow(hsv, rgb);

    for (size_t ii=0; ii < LED_COUNT; ++ii)
    {
        leds[ii] = rgb;
    }
}