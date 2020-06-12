#include<Servo.h>
Servo servomotor;
int angle;

int const trigpin=12;
int const echopin=5;

int motorleft1=2;
int motorleft2=4;
int motorright1=7;
int motorright2=8;

int dis;
int tim;


void setup() {
  Serial.begin(9600);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(motorleft1,OUTPUT);
  pinMode(motorleft2,OUTPUT);
  pinMode(motorright1,OUTPUT);
  pinMode(motorright2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(6,OUTPUT);
 servomotor.attach(9); 
}

void loop()
{
analogWrite(3,255);
analogWrite(6,255);

  servomotor.write(90);
  delay(500);
Serial.println("intial front with 90");
  digitalWrite(trigpin,HIGH);
  delay(10);
  digitalWrite(trigpin,LOW);
  tim=pulseIn(echopin,HIGH);
  dis=tim/58;
  Serial.println(dis);
  if(dis<20 && dis>=0)
  {  
     digitalWrite(motorleft1,LOW);
        digitalWrite(motorleft2,LOW);
        digitalWrite(motorright1,LOW);
        digitalWrite(motorright2,LOW);
    servomotor.write(180);
    delay(500);
    Serial.println("right turn servo");
    digitalWrite(trigpin,HIGH);
    delay(10);
    digitalWrite(trigpin,LOW);
    tim=pulseIn(echopin,HIGH);
    dis=tim/58;
    Serial.println(dis);
    if(dis<20 && dis>=0)
    {
       digitalWrite(motorleft1,LOW);
        digitalWrite(motorleft2,LOW);
        digitalWrite(motorright1,LOW);
        digitalWrite(motorright2,LOW);
      servomotor.write(0);
      delay(500);
      Serial.println("left turn");
      digitalWrite(trigpin,HIGH);
    delay(10);
    digitalWrite(trigpin,LOW);
    tim=pulseIn(echopin,HIGH);
    dis=tim/58;
    Serial.println(dis);
      if(dis<20 && dis>=0)
      
      {
        servomotor.write(90);
        delay(500);
        Serial.println("servo front");
        Serial.println("motor reverse");
        digitalWrite(motorleft1,HIGH);
        digitalWrite(motorleft2,LOW);
        digitalWrite(motorright1,HIGH);
        digitalWrite(motorright2,LOW);
       
      }
      else
      {
        Serial.println("motorleft");
        digitalWrite(motorleft1,LOW);
  digitalWrite(motorleft2,HIGH);
  digitalWrite(motorright1,HIGH);
  digitalWrite(motorright2,LOW);
      
      }
      }
      else
      { Serial.println("motorright");
        digitalWrite(motorleft1,HIGH);
  digitalWrite(motorleft2,LOW);
  digitalWrite(motorright1,LOW);
  digitalWrite(motorright2,HIGH);
  }
      }
      else
      {
        Serial.println("motor front");
        digitalWrite(motorleft1,LOW);
        digitalWrite(motorleft2,HIGH);
        digitalWrite(motorright1,LOW);
         digitalWrite(motorright2,HIGH);
       }
        
      }
 

