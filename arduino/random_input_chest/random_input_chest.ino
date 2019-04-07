#include <Servo.h>

Servo motor;

const int min_gsr = 15;
const int opening_speed = 3;
const int closing_speed = 2;
int pos;
int gsr;

bool readData()
{
  gsr += random(-3,4);
  if(gsr < 0)
  {
    gsr = random(5);
  }
  if(gsr > 30)
  {
    gsr = random(25,31);
  }
  return true;
}

void update_position()
{
  if(gsr > min_gsr)
  {
    pos += opening_speed;
  }
  else
  {
    pos -= closing_speed;
  }
  if(pos < 0)
  {
    pos = 0;
  }
  if(pos >= 180)
  {
    pos = 180;
  }
}

void setup() {
  motor.attach(9);
  motor.write(0);
  pos = 0;
  Serial.begin(9600);
  randomSeed(analogRead(0));
  gsr = random(31);
}

void loop() {
  // print a random number from 0 to 30
  Serial.println(gsr);
  if(readData())
  {
    update_position();
    motor.write(pos);
    delay(15);
    if(pos == 180)
    {
      Serial.println("CHEST IS OPEN!\n");
      gsr = 0;
    }
  }
}
