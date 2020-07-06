#pragma once

#include <FastLED.h>
#include <Arduino.h>

// global definition for the RGB strip
#define LED_COUNT 20
#define LED_PIN 3

extern CRGB leds[LED_COUNT];

// global definitions for button pins
#define BTN_SPEED_PIN 11
#define BTN_BRIGHTNESS_PIN 12
#define BTN_EFFECT_PIN 13