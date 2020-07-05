#pragma once

struct effect_t
{
public:
    virtual void setup() = 0;
    virtual void loop() = 0;
    virtual void set_speed(int) = 0;
};