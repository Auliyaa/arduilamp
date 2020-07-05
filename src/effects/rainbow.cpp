#include "effects/rainbow.h"

void rainbow_effect_t::apply_leds()
{
    for (size_t ii = 0; ii < LED_COUNT; ++ii)
    {
        hsv2rgb_rainbow(hsv_leds[ii], leds[ii]);
    }
}

void rainbow_effect_t::setup()
{
    const int s = 360 / LED_COUNT;
    CHSV hsv(0, SATURATION, VALUE);
    for (size_t ii = 0; ii < LED_COUNT; ++ii)
    {
        hsv_leds[ii] = hsv;
        hsv.h += s;
        hsv.h %= 360;
    }

    apply_leds();
}

void rainbow_effect_t::set_speed(int s)
{
    speed = s / 10;
}

void rainbow_effect_t::loop()
{
    for (size_t ii = 0; ii < LED_COUNT; ++ii)
    {
        hsv_leds[ii].h += speed;
        hsv_leds[ii].h %= 360;
    }
    apply_leds();
}