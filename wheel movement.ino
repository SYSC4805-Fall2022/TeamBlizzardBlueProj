/*
*In this file, we are testing the movement of the wheels before 
*applying any adjustment to the speed of the motors
*/
//definitions for enable signal and direction
int PWMsig = 35;
int dirA = 5;

int delay_time= 2000; // how long should each wheel turn?


void setup() {
  Serial.begin(9600);

 //configures pins as outputs
  pinMode(PWMsig, OUTPUT);
  pinMode(dirA, OUTPUT);

//all pins are off at initialization
digitalWrite(PWMsig, LOW);     
digitalWrite(dirA,LOW);

}

void loop() {

Serial.println("Hello");
delay(500);

      moveforward();
      movereverse();

      Serial.println("After...");

      delay(1000);
      }

void moveforward(){
      //moving in forward
      Serial.println("Forward test");
      digitalWrite(PWMsig, HIGH);
      delay(delay_time);
      digitalWrite(dirA, LOW);
      delay(delay_time);
      digitalWrite(PWMsig, LOW);
      delay(delay_time);
}

void movereverse(){
      //moving in right reverse  
      Serial.println("Right reverse test");
      digitalWrite(PWMsig, HIGH);
      delay(delay_time);
      digitalWrite(dirA, HIGH);
      delay(delay_time);
      digitalWrite(PWMsig, LOW);
      delay(delay_time);
}
