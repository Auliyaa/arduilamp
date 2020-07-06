#include <FastLED.h>
#include <Arduino.h>
#include <EEPROM.h>

#include "button.h"

#include "effects/rainbow.h"
#include "effects/hue.h"
#include "effects/static.h"

#define EEADDR 166 // start location for EEPROM writing

// current board mode
#define EFFECTS_CNT 3
effect_t* effects[EFFECTS_CNT] = {
  new rainbow_effect_t(),
  new hue_effect_t(),
  new static_effect_t()
};
int current_effect = 0;
void current_effect_changed()
{
  effects[current_effect]->setup();
  FastLED.show();
}

// current board brightness
#define BRIGHTNESS_CNT 6
int brightness[BRIGHTNESS_CNT] = { 0, 50, 100, 150, 200, 255 };
int current_brightness = 10;
void current_brightness_changed()
{
  FastLED.setBrightness(brightness[current_brightness]);
}

// current board speed
#define SPEED_CNT 8
int speed[] = { 0, 1, 5, 10, 25, 50, 75, 100 };
int current_speed = 3;
void current_speed_changed()
{
  effects[current_effect]->set_speed(speed[current_speed]);
}

// load/save from/to EEPROM
void dump_settings()
{
  Serial.print("brightness=");
  Serial.println(brightness[current_brightness]);
  Serial.print("speed=");
  Serial.println(speed[current_speed]);
  Serial.print("effect=");
  Serial.println(effects[current_effect]->name());
}

void save_settings()
{
  int addr = EEADDR;
  EEPROM.put(addr, current_brightness);
  addr += sizeof(current_brightness);
  EEPROM.put(addr, current_speed);
  addr += sizeof(current_speed);
  EEPROM.put(addr, current_effect);

  dump_settings();
}

void load_settings()
{
  int addr = EEADDR;
  EEPROM.get(addr, current_brightness);
  addr += sizeof(current_brightness);
  EEPROM.get(addr, current_speed);
  addr += sizeof(current_speed);
  EEPROM.get(addr, current_effect);

  dump_settings();
}

btn_t btn_brightness;
btn_t btn_effect;
btn_t btn_speed;

void setup()
{
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, LED_COUNT);
  Serial.begin(9600);

  btn_brightness.set_pin(BTN_BRIGHTNESS_PIN);
  btn_effect.set_pin(BTN_EFFECT_PIN);
  btn_speed.set_pin(BTN_SPEED_PIN);

  load_settings();

  current_effect_changed();
  current_speed_changed();
  current_brightness_changed();
}

bool save_eeprom = false;

void loop()
{
  effects[current_effect]->loop();
  FastLED.show();

  if (btn_brightness.read())
  {
    ++current_brightness;
    current_brightness %= BRIGHTNESS_CNT;
    current_brightness_changed();
    save_eeprom = true;
  }
  if (btn_effect.read())
  {
    ++current_effect;
    current_effect %= EFFECTS_CNT;
    current_effect_changed();
    save_eeprom = true;
  }
  if (btn_speed.read())
  {
    ++current_speed;
    current_speed %= SPEED_CNT;
    current_speed_changed();
    save_eeprom = true;
  }

  if (save_eeprom)
  {
    save_settings();
    save_eeprom = false;
  }

  delay(50);
}