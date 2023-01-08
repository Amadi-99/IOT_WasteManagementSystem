#include <Servo.h>
Servo servo;

// define variables
int pos = 0;
const int trigPin = 4;
const int echoPin = 3;
int orange = 5;
int red =6;
const int trigPin2 = 8;
const int echoPin2 = 9;

long duration;
long duration2;
float distance;
float distance2;

// define pinmode
void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(orange, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  servo.write(pos);
  servo.attach(2);
}

void loop()
{
  Serial.begin(9600);

//sensor1
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = 0.034*(duration/2);

  digitalWrite(red, LOW);
  digitalWrite(orange, LOW);

// led
  if (distance < 10){
    digitalWrite(red, HIGH);

    digitalWrite(orange, LOW);
  }
  else if ((distance <= 30) && (distance >= 10)){

    digitalWrite(red, LOW);
    digitalWrite(orange, HIGH);
    delay(500);
  }
  else {
    digitalWrite(red, LOW);
    digitalWrite(orange,LOW );
    delay(500);
  }

//sensor2
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = 0.034*(duration2/2);
  Serial.println(distance2);

//servo
  if (distance2 < 50)
  {
    servo.write(pos+45);
    delay(2000);
  }
  else 
  {
    servo.write(pos);
  }
  delay(60);

//output
  Serial.print ("Space left: ");
  Serial.println(distance);
  Serial.print ("Distabce from trashcan: ");
  Serial.println(distance2);
  
}
