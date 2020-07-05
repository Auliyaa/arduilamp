#include <FastLED.h>
#include <Arduino.h>
#include <EEPROM.h>

#include "effects/rainbow.h"

// current board mode
#define EFFECTS_CNT 1
effect_t* effects[EFFECTS_CNT] = {
  new rainbow_effect_t()
};
int current_effect = 0; // [0,EFFECTS_CNT-1]
void current_effect_changed()
{
  if (current_effect < 0) current_effect = 0;
  if (current_effect >= EFFECTS_CNT) current_effect = EFFECTS_CNT-1;

  effects[current_effect]->setup();
  FastLED.show();
}

// current board brightness
int current_brightness = 255; // [0-255]
void current_brightness_changed()
{
  if (current_brightness < 0) current_brightness = 0;
  if (current_brightness > 255) current_brightness = 255;

  FastLED.setBrightness(current_brightness);
}

// current board speed
int current_speed = 30; // [0-100]
void current_speed_changed()
{
  if (current_speed < 0) current_speed = 0;
  if (current_speed > 100) current_speed = 100;

  effects[current_effect]->set_speed(current_speed);
}

void setup()
{
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, LED_COUNT);
  Serial.begin(9600);

  // TODO: load EEPROM settings.

  current_effect_changed();
  current_speed_changed();
  current_brightness_changed();
}

void loop()
{
  effects[current_effect]->loop();
  FastLED.show();

  // TODO: check for button state change

  delay(50);
}