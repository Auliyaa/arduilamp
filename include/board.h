#pragma once

#include <FastLED.h>
#include <Arduino.h>

#include "button.h"

// global definitions for the RGB strip
#define LED_COUNT 20

// group leds by color (groups) all leds in the same group will share the same color
#define LED_GROUP_SZ 1
#define LED_GROUP_COUNT (LED_COUNT/LED_GROUP_SZ)

// pin allocation
#define PIN_LED 13
#define PIN_BTN_SPEED 10
#define PIN_BTN_BRIGHTNESS 11
#define PIN_BTN_MODE 12

// start location for EEPROM writing
#define EEADDR 166

struct board_t
{
    CRGB leds[LED_COUNT];

    btn_t<PIN_BTN_SPEED> btn_speed;
    btn_t<PIN_BTN_BRIGHTNESS> btn_brightness;
    btn_t<PIN_BTN_MODE> btn_mode;
};

extern board_t board;