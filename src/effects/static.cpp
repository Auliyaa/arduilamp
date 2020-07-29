#include "effects/static.h"

void static_effect_t::setup()
{
}

void static_effect_t::set_speed(int, size_t idx, size_t sz)
{
    hue = (idx * 255) / sz;
}

void static_effect_t::loop()
{
    CHSV hsv(hue, 255, 255);
    CRGB rgb;
    hsv2rgb_rainbow(hsv, rgb);

    for (size_t ii=0; ii < LED_COUNT; ++ii)
    {
        board.leds[ii] = rgb;
    }
}