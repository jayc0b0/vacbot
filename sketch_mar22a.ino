// VacBot Movement Prototype 1

#include <AFMotor.h>

// Motor Initialization
AF_DCMotor motorL(1, MOTOR12_64KHZ);
AF_DCMotor motorR(2, MOTOR12_64KHZ);
//AF_DCMotor vac(3);
//AF_DCMotor exhaust(4);

// Bumper Initialization
const int bumpPinF = 7;
const int bumpPinB = 7; // Set this to 10 in production
int bumpState = 0;

const int motorPin = 11;

void setup() {
  // Bumper setup
  pinMode(bumpPinF, INPUT);
  pinMode(bumpPinB, INPUT);

  // Motor setup
  motorL.setSpeed(255);
  motorR.setSpeed(255);
  //vac.setSpeed(255);
  //exhaust.setSpeed(255);
  pinMode(motorPin, INPUT);
  digitalWrite(motorPin, HIGH);

  // Corner finding
  // findHome();

  // Turn on vac
  //vac.run(FORWARD);
  //delay(10000);
  //vac.run(RELEASE);
  //delay(3000);
}

void loop() {
  motorL.run(FORWARD);
  delay(5000);
  
  // TESTING
  stepF();
  stepB();
  turnL();
  turnR();
  
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(100);              // wait for a second
}

void findHome() {

  // First collision
  while (bumpState != LOW) {
  //  bumpState = stepF();
  }

  bumpState = 0;
  turnR();

  // Second collision
  while (bumpState != LOW) {
  //  bumpState = stepF();
  }
  
  bumpState = 0;
  turnR();

  // Back up to wall
  while (bumpState != LOW) {
  //  bumpState = stepB();
  }

  bumpState = 0;
}

void stepF() {
    motorL.run(FORWARD);
    motorR.run(FORWARD);
    delay(1000);
    //bumpState = digitalRead(bumpPinF);
    motorL.run(RELEASE);
    motorR.run(RELEASE);
    //return bumpState;
}

void stepB() {
    motorL.run(BACKWARD);
    motorR.run(BACKWARD);
    delay(1000);
    //bumpState = digitalRead(bumpPinB);
    motorL.run(RELEASE);
    motorR.run(RELEASE);
    //return bumpState;
}

void turnR() {
  motorL.run(FORWARD);
  motorR.run(BACKWARD);
  delay(1000);
  motorL.run(RELEASE);
  motorR.run(RELEASE);
}

void turnL() {
  motorL.run(BACKWARD);
  motorR.run(FORWARD);
  delay(1000);
  motorL.run(RELEASE);
  motorR.run(RELEASE);
}
