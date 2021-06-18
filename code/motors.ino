#include <Wire.h>

#define in1L 2
#define in2L 4
#define enAL 5
#define enBL 6
#define in3L 7
#define in4L 8

#define in1R 0
#define in2R 1
#define enAR 11
#define enBR 9
#define in3R 10
#define in4R 3


//#define LED = 13


int LED = 13;
bool x = false;

int speed = 255;

void setup() {
  pinMode(in1L, OUTPUT);
  pinMode(in2L, OUTPUT);
  pinMode(enAL, OUTPUT);
  pinMode(in3L, OUTPUT);
  pinMode(in4L, OUTPUT);
  pinMode(enBL, OUTPUT);

  pinMode(in1R, OUTPUT);
  pinMode(in2R, OUTPUT);
  pinMode(enAR, OUTPUT);
  pinMode(in3R, OUTPUT);
  pinMode(in4R, OUTPUT);
  pinMode(enBR, OUTPUT);

  // Define the LED pin as Output
  pinMode (LED, OUTPUT);
  // Start the I2C Bus as Slave on address 9
  Wire.begin(9); 
  // Attach a function to trigger when something is received.
  Wire.onReceive(receiveEvent);
}
void receiveEvent(int bytes) {
  x = Wire.read();    // read one character from the I2C
}
void loop() {

  analogWrite(enAL, speed);
  analogWrite(enBL, speed);

  analogWrite(enAR, speed);
  analogWrite(enBR, speed);
  
  if (x == true) {
    digitalWrite(LED, HIGH);
    stop();
  } else {
    digitalWrite(LED, LOW);
    forward();
  }

}

void forward() {
  digitalWrite(in1L, LOW); //back left
  digitalWrite(in2L, HIGH);

  digitalWrite(in3L, HIGH); //front left
  digitalWrite(in4L, LOW);

  digitalWrite(in1R, HIGH); //back right
  digitalWrite(in2R, LOW);

  digitalWrite(in3R, LOW); //front right
  digitalWrite(in4R, HIGH);
}

void stop() {
  digitalWrite(in1L, LOW);
  digitalWrite(in2L, LOW);
  digitalWrite(in3L, LOW);
  digitalWrite(in4L, LOW);

  digitalWrite(in1R, LOW);
  digitalWrite(in2R, LOW);
  digitalWrite(in3R, LOW);
  digitalWrite(in4R, LOW);
}