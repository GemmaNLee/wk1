/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/


// defines pins numbers
const int trigPin = 13;
const int echoPin = 12;

// defines variables
long duration;
int distance;

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int potpin = 13;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

void setup() {

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication


  myservo.attach(6);  // attaches the servo on pin 9 to the servo object
}


void loop() {
  // Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(10);

  // Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
distance= duration*0.034/2;

  // Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);

  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 100, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(5);                           // waits for the servo to get there
}
