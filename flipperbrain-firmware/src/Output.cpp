#include "Output.h"
#include <Arduino.h>

Output::Output(int _pin)
{

    pin = _pin;
    pinMode(pin, OUTPUT);
    state = LOW;
}

void Output::turnOnFor(unsigned long _onInterval)
{
    onInterval = _onInterval;
    lastTurnedOn = millis();
    setState(HIGH);
}

void Output::setState(bool _state)
{
    if (state != _state)
    {
        state = _state;
        digitalWrite(pin, state);
    }
}

void Output::update()
{

    if (millis() > lastTurnedOn + onInterval)
    {
        setState(LOW);
        lastTurnedOn = 0;
    }
}