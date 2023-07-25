#include <Arduino.h>
#include <Bounce2.h>

Bounce2::Button btn2;

Bounce2::Button initButton(int pin)
{
  Bounce2::Button button = Bounce2::Button();
  button.attach(pin, INPUT_PULLUP); // USE EXTERNAL PULL-UP
  button.interval(5);
  button.setPressedState(LOW);
  return button;
}

void setup()
{
  Serial.begin(9600);

  btn2 = initButton(2);
}

void loop()
{
  btn2.update();
  if (btn2.pressed())
  {
    Serial.println("Button pressed!");
  }
}
