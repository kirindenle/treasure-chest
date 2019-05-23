#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  randomSeed(analogRead(0));
}

void loop() {
  pos += (random(2)*2 - 1) * 45;
  if (pos < 0)
  {
    pos = 90;
  }
  if (pos > 180)
  {
    pos = 90;
  }
  myservo.write(pos);             // tell servo to go to position in variable 'pos'
  delay(1000);                       // waits 15ms for the servo to reach the position
}
