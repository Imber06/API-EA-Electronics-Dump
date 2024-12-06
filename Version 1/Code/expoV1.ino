/*
  This is the third draft of the final code for PARMESAN.
  It toggles 1 servo using 1 Myoware Muscle Sensor 2.0 input.
  The servo controls finger contraction, and toggles between 2 states.

  The Myo Sensor controls Servo. 
  It should be placed on the inside of the forearm.
*/

#include <Servo.h>

Servo myservo; // servo
const int myoPin = A0; // pin for signal from Myoware
const int servoPin = 8; // pin for output to servo
const int threshold = 500; // threshold for triggering a switch in servo

int myoValue; // stores analogRead() value of MYO sensro
bool trigger = false; // is input > threshold?
bool lastTrigger = false; // was the last input > threshold?
int pos1 = 0; // first position of servo
int pos2 = 120; // second position of servo
int lastPos = 1; // stores the previous position of servo

void setup() {

  myservo.attach(servoPin);
  myservo.write(pos1);
  Serial.begin(9600);

}

void loop() {

  myoValue = analogRead(myoPin);

  // print values to serial monitor
  Serial.print("MYO:"); Serial.print(myoValue); Serial.print(",");
  Serial.print("Threshold:"); Serial.println(threshold);

  // read Myo sensor and adjust servo:

  // check if the muscle is flexed
  if (myoValue > threshold) {
    trigger = true;
  }
  else {
    trigger = false;
  }

  /* 
    check to see if the muscle is switching to flexed
    or switching to unflexed, then switch positions
  */
  if (trigger && !lastTrigger) {

    if(lastPos == 1) {
      myservo.write(pos2);
      lastPos = 2;
    }
    else {
      myservo.write(pos1);
      lastPos = 1;
    }

  }

  lastTrigger = trigger;

  delay(100); // can lower value for more responsiveness
  
}