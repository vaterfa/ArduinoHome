#include <Servo.h>
Servo motor;

#define role1 5
#define role2 6
int roleONDurum;
int roleOFFDurum;

#define mesafeSensor A0
#define gazSensor A1
int mesafeDeger;  
int gazDeger;

void setup() {  
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
}

void loop() {

    mesafeDeger=analogRead(mesafeSensor);  
    gazDeger=analogRead(gazSensor);  
    if (gazDeger>=80&&mesafeDeger>=45){Serial.println("ikiHata");}
    else if (gazDeger<=100&&mesafeDeger>=45){Serial.println("mesafe");}
    else if (gazDeger>=100&&mesafeDeger<=45){Serial.println("gaz");}
    else {Serial.println("hataYok");}
  
  while(Serial.available()){
    char c = Serial.read();
    if(c == '0')
    {
        motor.attach(11); //servonun 11 numaralı pinde olduğu tanıtıldı.
        motor.write(0);   //motorun 0 dereceye hareketi sağlandı.
        delay(1000);
    }
    else if(c == '1')
    {
        motor.attach(11); //servonun 11 numaralı pinde olduğu tanıtıldı.
        motor.write(90);  //motorun 90 dereceye hareketi sağlandı.
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
