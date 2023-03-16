#include <Servo.h> //inclusão do servo

Servo servoMotor;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2); 
  
  
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW); 
  pinMode(echoPin, INPUT);
  
  
  return pulseIn(echoPin, HIGH);
}

void setup(){
  
  Serial.begin(9600); 
  
  pinMode(10, OUTPUT); 
  pinMode(8, OUTPUT); 
  
  servoMotor.attach(9);
  
}
int X;
void loop(){

  digitalWrite(8,LOW);
  Serial.println(0.1723 * readUltrasonicDistance(5,4));

  X =0.1723 * readUltrasonicDistance(5,4); 
  
  if (X > 3000){
  servoMotor.write(0);   
  }
  
   if (X <1000){
 
  tone(10, 440, 100); 
  servoMotor.write(90);
  }
   if (X <2000){
  digitalWrite(8,HIGH);
   delay(50);
  }
  
  else{
    digitalWrite(8,LOW);}
  
    }