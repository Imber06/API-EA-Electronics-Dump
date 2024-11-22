/*
  This is the code for testing servos.
  It toggles 2 servos on a timer.
  Servo 1 controls finger contraction, and toggles between 2 states.
  Servo 2 controls wrist flexion, and toggles between 3 states.
*/

#include <Servo.h>

Servo myservo1; // servo 1
const int servoPin1 = 8; // pin for output to servo 1
int s1pos1 = 0; // first position of servo 1
int s1pos2 = 120; // second position of servo 1

Servo myservo2; // servo 2
const int servoPin2 = 9; // pin for output to servo 2
int s2pos1 = 0; // first position of servo 2
int s2pos2 = 60; // second position of servo 2
int s2pos3 = 120; // third position of servo 2

const int timeDelay = 2000; //time delay between rotation

void setup() {

  myservo1.attach(servoPin1);
  myservo2.attach(servoPin2);

}

void loop() {

  myservo1.write(s1pos1);
  myservo2.write(s2pos1);
  delay(timeDelay);

  myservo1.write(s1pos2);
  myservo2.write(s2pos2);
  delay(timeDelay);

  myservo1.write(s1pos1);
  myservo2.write(s2pos3);
  delay(timeDelay);

  myservo1.write(s1pos2);
  myservo2.write(s2pos2);
  delay(timeDelay);
  
}
