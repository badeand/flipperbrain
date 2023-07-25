#include <Arduino.h>
#include <Bounce2.h>
#include <Output.h>

Bounce2::Button btn2;

Output *led8;
Output *led9;

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

  Output i = Output(8);
  led8 = &i;
  Output y = Output(9);
  led9 = &y;

  pinMode(3, INPUT_PULLUP);
}

void loop()
{
  led8->update();
  led9->update();
  btn2.update();

  if (btn2.pressed())
  {
    led8->turnOnFor(500);
  }

  led9->setState(!digitalRead(3));
}
