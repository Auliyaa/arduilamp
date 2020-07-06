#include "effects/comet.h"

void comet_effect_t::setup()
{
    pos = 0;
}

void comet_effect_t::set_speed(int, size_t idx, size_t sz)
{
    speed = (idx * LED_COUNT) / sz;
}

void comet_effect_t::loop()
{
    for (size_t ii = 0; ii < LED_COUNT; ++ii)
    {
        board.leds[ii] = CRGB(0,0,0);
    }
    board.leds[pos] = CRGB::White;
    pos += speed;
    pos %= LED_COUNT;
}