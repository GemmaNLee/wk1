/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

int currentValue = 0;  // global variables are retained on each iteration of loop()
int previousValue = 0;

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}

void loop() {
  previousValue = currentValue;  // store what was read last time
  currentValue = analogRead(potpin); 
   if (previousValue > currentValue) {  // compare them
    Serial.println("left");
    val = map(currentValue, 0, 1023, 0, 88);
  } else if (previousValue < currentValue){
  Serial.println("right");
   val = map(currentValue, 1023, 0, 180, 90);
 }else if (previousValue = currentValue){
  Serial.println("fart");
  }

  if (millis() % 20 < 2){
    myservo.write(val);// sets the servo position according to the scaled value
  }
 
  //delay(20);  // waits for the servo to get there
  Serial.println(val);
}
