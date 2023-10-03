#include <Arduino.h>
#include <Bounce2.h>
#include <Output.h>

Bounce2::Button btn2;
Bounce2::Button btn3;
Bounce2::Button btn4;

Bounce2::Button bumper1;
Bounce2::Button bumper2;

Output *led8;
Output *led9;
Output *led10;

int score = 0;

char sprintfbuffer[40];


Bounce2::Button initButton(int pin)
{
  Bounce2::Button button = Bounce2::Button();
  button.attach(pin, INPUT_PULLUP);
  button.interval(5);
  button.setPressedState(LOW);
  return button;
}

void increaseScore(int points) {
    score += points;
  /*
    Serial.print("Score: ");
    Serial.print(score);
    Serial.print(" (+");
    Serial.print(points);
    Serial.print(")");
    Serial.println();
*/
  sprintf(sprintfbuffer, "Score: %05d (+%01d)", score, points);
  Serial.println(sprintfbuffer);
}

void setScore(int _score) {
  score = _score;
  sprintf(sprintfbuffer, "Score: %05d (set to %05d)", score, score);
  Serial.println(sprintfbuffer);
}

void setup()
{
  Serial.begin(9600);
  btn2 = initButton(2);
  btn3 = initButton(3);
  btn4 = initButton(4);

  bumper1 = initButton(5);
  bumper2 = initButton(6);

  Output _led8 = Output(8);
  led8 = &_led8;
  Output _led9 = Output(9);
  led9 = &_led9;
  Output _led10 = Output(10);
  led10 = &_led10;

  Serial.println("Setup DONE.");
  setScore(0);
}

void loop()
{
  btn2.update();
  btn3.update();
  btn4.update();
  
  bumper1.update();
  bumper2.update();

  led8->update();
  led9->update();
  led10->update();

  if( btn2.isPressed() && btn3.isPressed() && btn4.isPressed()  ) {
    setScore(0);
    delay(500);
  }

  if (btn2.pressed() )
  {
    led8->turnOnFor(50);
  }

  if (btn3.pressed()){
    led9->turnOnFor(50);
  }

  if (btn4.pressed()){
    led10->turnOnFor(50);
  }

  if (bumper1.pressed()){
    increaseScore(1);
  }

  if (bumper2.pressed()){
    increaseScore(3);
  }


}
