#include "effects/rainbow.h"

void rainbow_effect_t::apply_leds()
{
    CHSV hsv(0,SATURATION,VALUE);
    for (size_t ii = 0; ii < LED_COUNT; ++ii)
    {
        hsv.h = hue[ii];
        hsv2rgb_rainbow(hsv, board.leds[ii]);
    }
}

void rainbow_effect_t::setup()
{
    float h = 0;
    float step = 360.0 / float(LED_COUNT);
    for (size_t ii = 0; ii < LED_COUNT; ++ii)
    {
        hue[ii] = h + float(ii) * step;
    }
    apply_leds();
}

void rainbow_effect_t::set_speed(int s, size_t, size_t)
{
    speed = float(s * 10) / 100.0;
}

void rainbow_effect_t::loop()
{
    for (size_t ii = 0; ii < LED_COUNT; ++ii)
    {
        hue[ii] += speed;
        if (hue[ii] > 255) hue[ii] -= 255.0;
    }
    apply_leds();
}