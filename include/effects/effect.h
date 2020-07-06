#pragma once

struct effect_t
{
public:
    virtual const char* name() const=0;
    virtual void setup() = 0;
    virtual void loop() = 0;
    virtual void set_speed(int) = 0;
};