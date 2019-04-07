long randNumber;

void setup() {
  Serial.begin(9600);

  // if analog input pin 0 is unconnected, random analog
  // noise will cause the call to randomSeed() to generate
  // different seed numbers each time the sketch runs.
  // randomSeed() will then shuffle the random function.
  randomSeed(analogRead(0));
  randNumber = random(31);
}

void loop() {
  // print a random number from 0 to 30
  randNumber += random(-3,4);
  if(randNumber < 0)
  {
    randNumber = random(5);
  }
  if(randNumber > 30)
  {
    randNumber = random(25,31);
  }
  Serial.println(randNumber);

  delay(50);
}
