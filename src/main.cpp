#include <FastLED.h>
#include <Arduino.h>
#include <EEPROM.h>

#include "board.h"

#include "effects/rainbow.h"
#include "effects/random.h"
#include "effects/hue.h"
#include "effects/static.h"

// current board mode
#define MODES_CNT 4
effect_t* mode_values[MODES_CNT] = {
  new rainbow_effect_t(),
  new hue_effect_t(),
  new static_effect_t(),
  new random_effect_t()
};
int current_mode = 0;
void current_mode_changed()
{
  mode_values[current_mode]->setup();
  FastLED.show();
}

// current board brightness
#define BRIGHTNESS_CNT 6
int brightness_values[BRIGHTNESS_CNT] = { 0, 50, 100, 150, 200, 255 };
int current_brightness = 0;
void current_brightness_changed()
{
  FastLED.setBrightness(brightness_values[current_brightness]);
}

// current board speed
#define SPEED_CNT 8
int speed_values[SPEED_CNT] = { 0, 1, 5, 10, 25, 50, 75, 100 };
int current_speed = 3;
void current_speed_changed()
{
  mode_values[current_mode]->set_speed(speed_values[current_speed], current_speed, SPEED_CNT);
}

// load/save from/to EEPROM
bool save_eeprom = false; // set to true each time an EEPROM value needs to be updated

void dump_settings()
{
  Serial.print("brightness=");
  Serial.println(brightness_values[current_brightness]);
  Serial.print("speed=");
  Serial.println(speed_values[current_speed]);
  Serial.print("mode=");
  Serial.println(mode_values[current_mode]->name());
}

void save_settings()
{
  int addr = EEADDR;
  EEPROM.put(addr, current_brightness);
  addr += sizeof(current_brightness);
  EEPROM.put(addr, current_speed);
  addr += sizeof(current_speed);
  EEPROM.put(addr, current_mode);

  dump_settings();
}

void load_settings()
{
  int addr = EEADDR;
  EEPROM.get(addr, current_brightness);
  addr += sizeof(current_brightness);
  EEPROM.get(addr, current_speed);
  addr += sizeof(current_speed);
  EEPROM.get(addr, current_mode);

  dump_settings();
}

void init_settings()
{
  for (uint16_t ii=0; ii < EEPROM.length(); ++ii)
  {
    EEPROM.write(ii, 0);
  }
  save_settings();
}

void setup()
{
  FastLED.addLeds<WS2812B, PIN_LED, GRB>(board.leds, LED_COUNT);
  Serial.begin(9600);

  board.btn_brightness.setup();
  board.btn_mode.setup();
  board.btn_speed.setup();

  // uncomment for the first time the board is executed so that the EEPROM is initialized
  //init_settings();

  load_settings();

  current_mode_changed();
  current_speed_changed();
  current_brightness_changed();
}

void loop()
{
  mode_values[current_mode]->loop();
  FastLED.show();

  if (board.btn_brightness.read())
  {
    ++current_brightness;
    current_brightness %= BRIGHTNESS_CNT;
    current_brightness_changed();
    save_eeprom = true;
  }
  if (board.btn_mode.read())
  {
    ++current_mode;
    current_mode %= MODES_CNT;
    current_mode_changed();
    save_eeprom = true;
  }
  if (board.btn_speed.read())
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