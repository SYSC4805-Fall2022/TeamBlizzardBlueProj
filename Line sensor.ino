
int LFS_L = 8;
  int LFS_M = 6;
  int LFS_R = 7;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  

  // pinMode(A10,INPUT);
  pinMode(LFS_L,INPUT);
  pinMode(LFS_M,INPUT);
  pinMode(LFS_R,INPUT);
  //pinMode(13, OUTPUT);
}

void loop() {
  
   Serial.println("Hi");
  String left = "W";
  String middle = "W";
  String right = "W";
  if(digitalRead(LFS_L))
  {
    left = "B";
  }
  if(digitalRead(LFS_M)){
    middle = "B";
  }
  if(digitalRead(LFS_R)){
    right = "B";
  }
  delay(500);
 Serial.print("Hello world!");
 Serial.println("Group 3, Left Sensor: " + left + ", Middle Sensor: "+middle+", Right Sensor: "+right);

//  double input = analogRead(A10); 

//  double result = (input/1023)*3.3;

//  Serial.println(result);

//  int distance = 0;

//  if(result>1.5){
//    distance = 2;
//  }else if(result > 0.98){
//   distance = 4;
//  }else if(result > 0.72){
//    distance = 6;
//  }else if(result > 0.6){
//    distance = 8;
//  }else if(result > 0.53){
//    distance = 10;
//  }else if(result > 0.5){
//    distance = 12;
//  }else if(result > 0.48){
//    distance = 14;
//  }else{
//   distance = 999;
//  }

  // if(distance==999){
  //   Serial.println("Too far, or too close");
  // }else{
  //   Serial.print("Group 3, the Distance is: ");
  //   Serial.print(distance);
  //   Serial.println(" cm");

  // }
  // distance = -0.047*result + 1.37;

  //Serial.print("Group1, Section L2, Result ");
  //Serial.print(result);
  //Serial.print("Distance ");
  //Serial.println(distance);

}

