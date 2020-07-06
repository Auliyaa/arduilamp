#include "button.h"

void btn_t::set_pin(uint8_t p)
{
    pin = p;
    pinMode(pin, INPUT);
}

bool btn_t::read()
{
    int s = digitalRead(pin);
    bool r = state == LOW && s == HIGH;
    state = s;
    return r;
}