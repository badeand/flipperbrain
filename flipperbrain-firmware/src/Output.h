#include <limits.h>

#ifndef OUTPUT_H
#define OUTPUT_H

class Output
{
public:
  Output(int _pin);
  void turnOnFor(unsigned long onInterval);
  void update();
  void setState(bool _state);

private:
  int pin;
  bool state;
  unsigned long lastTurnedOn = INT_MAX;
  unsigned long onInterval = 0;
};

#endif