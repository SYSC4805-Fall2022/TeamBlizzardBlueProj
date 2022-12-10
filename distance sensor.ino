int trigPin = 7;
int echoPin = 8;
float duration;
float distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= 0.0343 * duration/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Section L2, Group 3: ");
  Serial.print(distance);
  Serial.println("cm");
}
