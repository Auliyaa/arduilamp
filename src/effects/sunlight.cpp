#include "effects/sunlight.h"

// see http://planetpixelemporium.com/tutorialpages/light.html
#define SUNGLIGHT_VALUE_CNT 6
const CRGB sunlight_values[] = {
    CRGB(255, 147, 41),  // candle
    CRGB(255, 197, 143), // 40W tungsten
    CRGB(255, 214, 170), // 100W tungsten
    CRGB(255, 241, 244), // halogen
    CRGB(255, 250, 244), // carbon arc
    CRGB(255, 255, 255)  // direct sunglight
};

void sunlight_effect_t::setup()
{
    current = sunlight_values[0];
}

void sunlight_effect_t::set_speed(int, size_t idx, size_t)
{
    if (idx >= SUNGLIGHT_VALUE_CNT) idx = 0;
    current = sunlight_values[idx];
}

void sunlight_effect_t::loop()
{
    for (size_t ii = 0; ii < LED_COUNT; ++ii)
    {
        board.leds[ii] = current;
    }
}