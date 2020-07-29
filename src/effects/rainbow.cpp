#include "effects/rainbow.h"

void rainbow_effect_t::apply_leds()
{
    CHSV hsv(0,SATURATION,VALUE);
    for (size_t ii = 0; ii < LED_GROUP_COUNT; ++ii)
    {
        hsv.h = hue[ii];
        for (size_t jj=0; jj < LED_GROUP_SZ; ++jj)
        {
            hsv2rgb_rainbow(hsv, board.leds[ii*LED_GROUP_SZ + jj]);
        }
    }
}

void rainbow_effect_t::setup()
{
    float h = 0;
    float step = 360.0 / float(LED_GROUP_COUNT);
    for (size_t ii = 0; ii < LED_GROUP_COUNT; ++ii)
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
    for (size_t ii = 0; ii < LED_GROUP_COUNT; ++ii)
    {
        hue[ii] += speed;
        if (hue[ii] > 255) hue[ii] -= 255.0;
    }
    apply_leds();
}