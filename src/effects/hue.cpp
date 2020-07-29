#include "effects/hue.h"

void hue_effect_t::apply_leds()
{
    CRGB rgb(0,0,0);
    CHSV hsv(hue, SATURATION, VALUE);
    hsv2rgb_rainbow(hsv, rgb);
    for (size_t ii = 0; ii < LED_COUNT; ++ii)
    {
        board.leds[ii] = rgb;
    }
}

void hue_effect_t::setup()
{
    hue = 0;
    apply_leds();
}

void hue_effect_t::set_speed(int s, size_t, size_t)
{
    speed = float(s * 0.8) / 100.;
}

void hue_effect_t::loop()
{
    hue += speed;
    if (hue > 255) hue -= 255.0;
    apply_leds();
}