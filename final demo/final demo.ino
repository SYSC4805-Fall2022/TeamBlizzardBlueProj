#include <CytronMotorDriver.h>
#include <EZDist.h>
/*
Watchdog timer initializations
*/
#define watchDogTime 8000
#define fullspeed 255
#define halfspeed 128
#define backfullspeed -255
#define nospeed 0
#define delay_time 2000

/*
Motors initializations
*/
#define RightPwr 4
#define RightDir 3
#define LeftPwr 6
#define LeftDir 5
#define LFS_L1 A0
#define LFS_M1 A2
#define LFS_R1 A1

/*
Ultrasonic sensor initializations
*/
#define TrigPinLeft 27 // Left ultrasonic sensor
#define EchoPinLeft 23 // Left ultrasonic sensor
#define TrigPinRight 24 // Right ultrasonic sensor
#define EchoPinRight 25 // Right ultrasonic sensor
int distanceLeft = 0;
int distanceRight = 0;
EZDist USLeft(TrigPinLeft, EchoPinLeft);
EZDist USRight(TrigPinRight, EchoPinRight);


void setup() {
  //left and right direction setup
  pinMode(LeftDir, OUTPUT);
  pinMode(RightDir, OUTPUT);
  //line follower inputs
  pinMode(LFS_L1,INPUT);
  pinMode(LFS_M1,INPUT);
  pinMode(LFS_R1,INPUT);
  

}

void loop() {
  Serial.begin(9600);
  watchdogEnable(watchDogTime);
  // put your main code here, to run repeatedly:
   linefollower();
   USMotion();
  
}

void watchdogSetup(void){
  
}
void setForward(){
  
  Serial.println("Hello Forward");
  digitalWrite(RightDir, LOW);
  digitalWrite(LeftDir, LOW);
  analogWrite(RightPwr, 80);
  analogWrite(LeftPwr, 80);


}

void setBackward(){
   Serial.println("Hello Backward");
  digitalWrite(LeftDir, HIGH);
  digitalWrite(RightDir, HIGH);
  analogWrite(LeftPwr, 100);
  analogWrite(RightPwr, 100);
}

void stop(){
  analogWrite(LeftPwr, 0);
  analogWrite(RightPwr, 0);
}

void turnleft(){
 Serial.println("Turning left");
  digitalWrite(LeftDir, LOW);
  digitalWrite(RightDir, HIGH);
  analogWrite(LeftPwr, 210);
  analogWrite(RightPwr, 75);
}
void turnround(){
 Serial.println("Turning Round");
  digitalWrite(LeftDir, LOW);
  digitalWrite(RightDir, HIGH);
  analogWrite(LeftPwr, 210);
  analogWrite(RightPwr, 210);
}

void turnright(){
  Serial.println("Turning right");
  digitalWrite(LeftDir, HIGH);
  digitalWrite(RightDir, LOW);
  analogWrite(LeftPwr, 75);
  analogWrite(RightPwr, 210);
}


void USMotion()
{
   distanceRight = USRight.cm();  
   distanceLeft = USLeft.cm();
  Serial.print("Left Sensor: ");
  Serial.println(distanceLeft);
  Serial.print("Right Sensor: ");
  Serial.println(distanceRight);
  delay(1000);

  if(distanceLeft > 15 && distanceRight > 15)
  {
    setForward();   
    delay(delay_time); 
  }
  if(distanceLeft < 15 || distanceRight < 15){
     stop();
     delay(delay_time); 
     setForward();
     if(distanceLeft > 15){
       delay(delay_time);
       turnleft();
       setForward();
       exit;
     }
     else if(distanceRight > 15){
       turnright();
       setForward();
       delay(delay_time);
       exit;
     }
  }
  else{
    setForward();
  }
}

void linefollower(){

  int left = analogRead(LFS_L1);
  int middle = analogRead(LFS_M1);
  int right = analogRead(LFS_R1);
  setForward();
  delay(delay_time);
if(right < 750 && middle < 750 && left < 750){
  setForward();

}
 else if((right < 750 && middle < 750 && left > 750)){
 turnright();
 setForward();

 
}
else if((right > 900 || middle > 900 || left > 900)){
  stop();
  delay(delay_time);
  turnright();
  delay(delay_time);
  setForward();  
}

 else if(right < 750 || middle > 900 || left > 900){
  turnleft(); 
  delay(delay_time);
  setForward();  
 }

else if(right > 900 || middle > 900 || left < 750){
  turnright();
  delay(delay_time);
  setForward();
}

// else if(right > 850 && middle > 850 && left < 750){
// while(true){
//   turnleft();
//   if((right < 750 && middle > 850 && left < 750) || (right < 750 && middle > 850 && left > 85)){
//     break;    
//   }
// }
// }

else{
  setForward();
}
  Serial.print("Left Sensor: ");
  Serial.println(left);

  Serial.print("Middle Sensor: ");
  Serial.println(middle);

  Serial.print("Right Sensor: ");
  Serial.println(right);

  delay(500);

}
  
  


