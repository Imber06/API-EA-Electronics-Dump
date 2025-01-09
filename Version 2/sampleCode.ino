/* 
  This code serves as a sample of how our arm might operate.
  We're hoping to control the arm with this code via an Arduino 
  or a similar device.
*/

#include <Servo.h>

/*
  This is where the variables for our EMG, button, and servos 
  will go. Our current idea incorporates 5 servos, 1 to 2 EMGs,
  and 2 buttons.
*/

Servo myservo; // sample servo
const int servoPin = 8; // sample servo output pin
const int emgPin = A0; // sample EMG input pin
const int threshold = 500; // sample EMG threshold for controlling the servo

void setup() {
  // Initialize our servos here
  myservo.attach(servoPin);
  myservo.write(0); // write a default position to our servos
  Serial.begin(9600);
}

void loop() {
  
}
