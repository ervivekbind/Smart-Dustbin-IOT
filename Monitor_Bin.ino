#include <Servo.h>
Servo Servo1;
Servo Servo2;

const int trigPin1 = 3;
const int echoPin1 = 4;
const int trigPin2 = 5;
const int echoPin2 = 6;

int servoPin1 = 11;
int servoPin2 = 12;

long duration1;
int distance1;
long duration2;
int distance2;

void setup() 
 {
  Servo1.attach(servoPin1);
   
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT); 

  
  Servo2.attach(servoPin2);
   
  pinMode(trigPin2, OUTPUT); 
  pinMode(echoPin2, INPUT); 

  
  Serial.begin(9600); 
}


void loop(){

digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
digitalWrite(trigPin2, LOW);
delayMicroseconds(2);

digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);

duration1 = pulseIn(echoPin1, HIGH);

digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);

duration2 = pulseIn(echoPin2, HIGH);

distance1= duration1*0.034/2;
distance2= duration2*0.034/2;

Serial.print("Distance 1: ");
Serial.println(distance1);

Serial.print("Distance2: ");
Serial.println(distance2);

if(distance1 <= 20){
   Servo1.write(0); 
   delay(1000); 
   Servo1.write(180);
}

if(distance2 <= 20){
   Servo2.write(0); 
   delay(1000);
   Servo1.write(180 );
}
}
