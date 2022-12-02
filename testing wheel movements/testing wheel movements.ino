#include <CytronMotorDriver.h>
#include <EZDist.h>
#define watchDogTime 8000
#define fullspeed 255
#define halfspeed 128
#define backfullspeed -255
#define nospeed 0
#define delay_time 2000


#define RightPwr 4
#define RightDir 3
#define LeftPwr 6
#define LeftDir 5




void setup() {
  // put your setup code here, to run once:
  //start();
  //pinMode(LeftPwr, OUTPUT);
  pinMode(LeftDir, OUTPUT);
  //pinMode(RightPwr, OUTPUT);
  pinMode(RightDir, OUTPUT);


}

void loop() {
  Serial.begin(9600);
  watchdogEnable(watchDogTime);
  // put your main code here, to run repeatedly:
    setForward();
    delay(delay_time);
  //  stop();
  //  delay(delay_time);
  //  setBackward();
  //  delay(delay_time);
  //  stop();
  //  delay(delay_time);
  //  turnright();
  //  delay(delay_time);
  //  stop();
  //  delay(delay_time);
  //  turnleft();
  //  delay(delay_time);
  //  stop();
 
  
}

void watchdogSetup(void){
  
}
void setForward(){
  
  Serial.println("Hello Forward");
  // motor1A.setSpeed(fullspeed);  // Run backward at 50% speed. 
  // motor2A.setSpeed(fullspeed);  // Run backward at 50% speed.
  digitalWrite(RightDir, LOW);
  digitalWrite(LeftDir, LOW);
  analogWrite(RightPwr, 200);
  analogWrite(LeftPwr, 200);


}

void setBackward(){
   Serial.println("Hello Backward");
  digitalWrite(LeftDir, HIGH);
  digitalWrite(RightDir, HIGH);
  analogWrite(LeftPwr, 150);
  analogWrite(RightPwr, 150);
}

void stop(){
  analogWrite(LeftPwr, 0);
  analogWrite(RightPwr, 0);
}

void turnright(){
 Serial.println("Turning right");
  digitalWrite(LeftDir, LOW);
  digitalWrite(RightDir, LOW);
  analogWrite(LeftPwr, 250);
  analogWrite(RightPwr, 100);
}

void turnleft(){
  Serial.println("Turning left");
  digitalWrite(LeftDir, HIGH);
  digitalWrite(RightDir, HIGH);
  analogWrite(LeftPwr, 100);
  analogWrite(RightPwr, 250);
}


  
  


