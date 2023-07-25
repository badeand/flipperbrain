#include <Arduino.h>
#include <Bounce2.h>

Bounce2::Button btn2;
Bounce2::Button btn3;

Bounce2::Button initButton(int pin)
{
  Bounce2::Button button = Bounce2::Button();
  button.attach(pin, INPUT_PULLUP);
  button.interval(5);
  button.setPressedState(LOW);
  return button;
}

void setup()
{
  Serial.begin(9600);
  btn2 = initButton(2);
  btn3 = initButton(3);
}

void loop()
{
  btn2.update();
  btn3.update();
  if (btn2.pressed())
  {
    Serial.println("Button 2 pressed!");
  }

  if (btn3.pressed())
  {
    Serial.println("Button 3 pressed!");
  }
}
