
#include <Servo.h>
#define trigPin 13
#define echoPin 12
Servo servo;
int sound = 250;


void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servo.attach(9);
}


void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(100);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  
  if (distance < 50) {
    Serial.println("the distance is less than 50");
    servo.write(80);
  }else {
    // change number smaller for twitching higher for smooth
    servo.write(10);
  }
}
