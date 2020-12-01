#include <Servo.h>
Servo motor;

#define role1 	5
#define role2 	6
#define servo1	11

#define mesafeSensor A0
#define gazSensor A1

void setup() {  
  pinMode(role1, OUTPUT);
  pinMode(role2, OUTPUT);
  Serial.begin(115200);
}

void loop() {

    if (analogRead(gazSensor)>=80&&analogRead(mesafeSensor)>=45){Serial.println("ikiHata");}
    else if (analogRead(gazSensor)<=100&&analogRead(mesafeSensor)>=45){Serial.println("mesafe");}
    else if (analogRead(gazSensor)>=100&&analogRead(mesafeSensor)<=45){Serial.println("gaz");}
    else {Serial.println("hataYok");}
  
  while(Serial.available()){
    char c = Serial.read();
    if(c == '0')
    {
        motor.attach(servo1); 
        motor.write(0);   
        delay(1000);
    }
    else if(c == '1')
    {
        motor.attach(servo1); 
        motor.write(90);  
        delay(1000);
    }
    else if(c == '2')
    {
        digitalWrite(role1,HIGH);
        delay(1000);
    }
     else if(c == '3')
    {
        digitalWrite(role1,LOW); 
        delay(1000);
    }
    else if(c == '4')
    {
        digitalWrite(role2,HIGH);
        delay(1000);
    }
    else if(c == '5')
    {
        digitalWrite(role2,LOW); 
        delay(1000);
    }  
    }
}
