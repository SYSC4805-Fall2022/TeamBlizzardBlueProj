/*
*In this file, we are testing the movement of the wheels before 
*applying any adjustment to the speed of the motors
*/
//definitions for enable signal and direction

#include <avr/wdt.h>

int PWMsigA = 35;
int dirA = 5;
int PWMsigB = 37;
int dirB = 6;

int delay_time= 2000; // how long should each wheel turn?
//watchdog timer with 4 seconds timeout
wdt_enable(WDTO_4S);


void setup() {
  Serial.begin(9600);

 //configures pins as outputs
  pinMode(PWMsigA, OUTPUT);
  pinMode(dirA, OUTPUT);
  pinMode(PWMsigB, OUTPUT);
  pinMode(dirB, OUTPUT);

//all pins are off at initialization
digitalWrite(PWMsigA, LOW);     
digitalWrite(dirA,LOW);
digitalWrite(PWMsigB, LOW);     
digitalWrite(dirB,LOW);

}

void loop() {

Serial.println("Hello");
delay(500);

      moveforwardright();
      movereverseright();

      Serial.println("After...");

      delay(1000);
      wdt_reset();
      }

void moveforwardright(){
      //moving in right forward
      Serial.println("Right Forward test");
      digitalWrite(PWMsig, HIGH);
      delay(delay_time);
      digitalWrite(dirA, HIGH);
      delay(delay_time);
      digitalWrite(PWMsig, LOW);
      delay(delay_time);
}

void movereverseright(){
      //moving in right reverse  
      Serial.println("Right reverse test");
      digitalWrite(PWMsig, HIGH);
      delay(delay_time);
      digitalWrite(dirA, LOW);
      delay(delay_time);
      digitalWrite(PWMsig, LOW);
      delay(delay_time);
}

void moveforwardleft(){
      //moving in left forward
      Serial.println("Left Forward test");
      digitalWrite(PWMsig, HIGH);
      delay(delay_time);
      digitalWrite(dirA, HIGH);
      delay(delay_time);
      digitalWrite(PWMsig, LOW);
      delay(delay_time);
}

void movereverseleft(){
      //moving in left reverse  
      Serial.println("Left reverse test");
      digitalWrite(PWMsig, HIGH);
      delay(delay_time);
      digitalWrite(dirA, LOW);
      delay(delay_time);
      digitalWrite(PWMsig, LOW);
      delay(delay_time);
}
