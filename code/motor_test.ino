#define in1 2
#define in2 4
#define enA 5
#define enB 6
#define in3 7
#define in4 8
#define trigPin 9
#define echoPin 10

float duration, distance;
int speed;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);

  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);

  speed = 0;
}

void loop() {
  measureDist();
  Serial.print("Distance: ");
  Serial.println(distance);

  findSpeed();
  analogWrite(enA, speed);
    analogWrite(enB, speed);

  if (distance >= 12) {
    forward();
  } else {
    stop();
  }
}

void forward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
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

void findSpeed() {
  if (distance>100) {
    speed = 255/2; //255 is too fast for the motors
  } else {
    speed = ((2.45 * distance) + 10)/2;
  }
}