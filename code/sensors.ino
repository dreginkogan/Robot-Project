#include <Wire.h>


#define trigPin 11
#define echoPin 10

#define trigPinL 9
#define echoPinL 6

#define trigPinR 5
#define echoPinR 3

float duration, distance, durationL, distanceL, durationR, distanceR;
bool light;

#define led 7

void setup() {
  // put your setup code here, to run once:

  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 

  pinMode(trigPinL, OUTPUT); 
  pinMode(echoPinL, INPUT); 

  pinMode(trigPinR, OUTPUT); 
  pinMode(echoPinR, INPUT); 


  pinMode(led, OUTPUT);
  Serial.begin(9600);

  // Start the I2C Bus as Master
  Wire.begin(); 

}

void loop() {
  
  measureDistL();
  Serial.print(distanceL);

  Serial.print(" | ");

  measureDist();
  Serial.print(distance);

  Serial.print(" | ");

  measureDistR();
  Serial.println(distanceR);

  if (distanceL < 150 && distance < 100 && distanceR < 150) {
    light = true;
  } else {
    light = false;
  }

  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(light);              // sends x 
  Wire.endTransmission();    // stop transmitting
}

void measureDist() {

  digitalWrite(trigPin, LOW); 

  delayMicroseconds(2); 

  digitalWrite(trigPin, HIGH); 

  delayMicroseconds(10); 

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH); 
  distance = (duration*.0343)/2; //duration.0343
}

void measureDistL() {

  digitalWrite(trigPinL, LOW); 

  delayMicroseconds(2); 

  digitalWrite(trigPinL, HIGH);

  delayMicroseconds(10); 

  digitalWrite(trigPinL, LOW);

  durationL = pulseIn(echoPinL, HIGH); 
  distanceL = (durationL*.0343)/2; //duration.0343

}

void measureDistR() {

  digitalWrite(trigPinR, LOW); 

  delayMicroseconds(2); 

  digitalWrite(trigPinR, HIGH);

  delayMicroseconds(10); 

  digitalWrite(trigPinR, LOW);

  durationR = pulseIn(echoPinR, HIGH); 
  distanceR = (durationR*.0343)/2; //duration.0343

}
