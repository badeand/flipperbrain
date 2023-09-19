#include <Arduino.h>
#include <Bounce2.h>
#include <Output.h>

Bounce2::Button btn2;
Bounce2::Button btn3;
Bounce2::Button btn4;

Output *led8;
Output *led9;
Output *led10;

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
  btn4 = initButton(4);

  Output _led8 = Output(8);
  led8 = &_led8;
  Output _led9 = Output(9);
  led9 = &_led9;
  Output _led10 = Output(10);
  led10 = &_led10;

  Serial.println("Setup DONE.");
}

void loop()
{
  led8->update();
  led9->update();
  led10->update();
  btn2.update();
  btn3.update();
  btn4.update();

  if (btn2.pressed())
  {
    led8->turnOnFor(500);
  }

  if (btn3.pressed()){
    led9->turnOnFor(500);
  }

  if (btn4.pressed()){
    led10->turnOnFor(500);
  }


}
