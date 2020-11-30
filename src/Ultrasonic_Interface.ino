
// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int rouge = 3;
const int jaune = 4;
const int vert = 5;
// defines variables
long duration;
int distance;
void setup() {
pinMode(rouge, OUTPUT);
pinMode(jaune, OUTPUT);
pinMode(vert, OUTPUT);
digitalWrite(rouge, LOW);
digitalWrite(jaune, LOW);
digitalWrite(vert, HIGH);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
}
void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
delay(200);
if(distance>20){
  digitalWrite(rouge, LOW);
  digitalWrite(jaune, LOW);
  digitalWrite(vert, HIGH);
}
else if (distance>10){
  digitalWrite(rouge, LOW);
  digitalWrite(jaune, HIGH);
  digitalWrite(vert, LOW);
}
else {
  digitalWrite(rouge, HIGH);
  digitalWrite(jaune, LOW);
  digitalWrite(vert, LOW);
}
delay(200);

}
