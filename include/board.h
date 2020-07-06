#pragma once

#include <FastLED.h>
#include <Arduino.h>

#include "button.h"

// global definitions for the RGB strip
#define LED_COUNT 20

// pin allocation
#define PIN_LED 3
#define PIN_BTN_SPEED 11
#define PIN_BTN_BRIGHTNESS 12
#define PIN_BTN_MODE 13

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