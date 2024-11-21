/*
  This is the second draft of the final code for PARMESAN.
  It toggles 2 servos using 2 Myoware Muscle Sensor 2.0 inputs.
  Servo 1 controls finger contraction, and toggles between 2 states.
  Servo 2 controls wrist flexion, and toggles between 3 states.

  Myo Sensor 1 controls Servo 1. 
  It should be placed on the inside of the forearm.
  Myo Sensor 2 controls Servo 2.
  It should be placed on the outside of the forearm.
*/

#include <Servo.h>

// Variables for Servo 1 and Myo Sensor 1:
Servo myservo1; // servo 1
const int myoPin1 = A0; // pin for signal from Myoware 1
const int servoPin1 = 8; // pin for output to servo 1
const int threshold1 = 500; // threshold for triggering a switch in servo 1

int myo1Value; // stores analogRead() value of Myo Sensor 1
bool trigger1 = false; // is input > threshold?
bool lastTrigger1 = false; // was the last input > threshold?
int s1pos1 = 0; // first position of servo 1
int s1pos2 = 120; // second position of servo 1
int s1lastPos = 1; // stores the previous position of servo 1

// Variables for Servo 2 and Myo Sensor 2:
Servo myservo2; // servo 2
const int myoPin2 = A1; // pin for signal from Myoware 2
const int servoPin2 = 9; // pin for output to servo 2
const int threshold2 = 350; // threshold for triggering a switch in servo 2

int myo2Value; // stores analogRead() value of Myo Sensor 2
bool trigger2 = false; // is input > threshold?
bool lastTrigger2 = false; // was the last input > threshold?
int s2pos1 = 0; // first position of servo 2
int s2pos2 = 60; // second position of servo 2
int s2pos3 = 120; // third position of servo 2
int s2lastPos = 1; // stores int value for servo pos

void setup() {

  myservo1.attach(servoPin1);
  myservo2.attach(servoPin2);

  Serial.begin(9600);

  myservo1.write(s1pos1);
  myservo2.write(s2pos1);

}

void loop() {

  myo1Value = analogRead(myoPin1);
  myo2Value = analogRead(myoPin2);

  // print values to serial monitor
  Serial.print("MYO_1:"); Serial.print(myo1Value); Serial.print(",");
  Serial.print("MYO_2:"); Serial.print(myo2Value); Serial.print(",");
  Serial.print("Threshold_1:"); Serial.print(threshold1); Serial.print(",");
  Serial.print("Threshold_2:"); Serial.println(threshold2);

  // read Myo Sensor 1 and adjust Servo 1:

  // check if the muscle is flexed
  if (myo1Value > threshold1) {
    trigger1 = true;
  }
  else {
    trigger1 = false;
  }

  /* 
    check to see if the muscle is switching to flexed
    or switching to unflexed, then switch positions
  */
  if (trigger1 && !lastTrigger1) {

    if(s1lastPos == 1) {
      myservo1.write(s1pos2);
      s1lastPos = 2;
    }
    else {
      myservo1.write(s1pos1);
      s1lastPos = 1;
    }

  }

  lastTrigger1 = trigger1;

  // read Myo Sensor 2 and adjust Servo 2:

  // check if the muscle is flexed
  if (myo2Value > threshold2) {
    trigger2 = true;
  }
  else {
    trigger2 = false;
  }

  /* 
    check to see if the muscle is switching to flexed
    or switching to unflexed, then switch positions
  */
  if (trigger2 && !lastTrigger2) {

    if(s2lastPos == 1) {
      myservo2.write(s2pos2);
      s2lastPos = 2;
    }
    else if (s2lastPos == 2) {
      myservo2.write(s2pos3);
      s2lastPos = 3;
    } 
    else if (s2lastPos == 3) {
      myservo2.write(s2pos2);
      s2lastPos = 4;
    } else {
      myservo2.write(s2pos1);
      s2lastPos = 1;
    }

  }

  lastTrigger2 = trigger2;

  delay(100); // can lower value for more responsiveness
  
}
