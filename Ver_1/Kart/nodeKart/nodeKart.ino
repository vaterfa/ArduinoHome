#include <Servo.h>
Servo motor;

#define role1 4
#define role2 0
#define servo1 5
int roleONDurum;
int roleOFFDurum;

#define mesafeSensor 2
#define gazSensor A0
int mesafeDeger;  
int gazDeger;

void setup() {  
  pinMode(role1, OUTPUT);
  pinMode(role2, OUTPUT);
  pinMode(mesafeSensor, INPUT);
  pinMode(gazSensor, INPUT);
  Serial.begin(115200);
}

void loop() {

    mesafeDeger=digitalRead(mesafeSensor);  
    gazDeger = analogRead(gazSensor);

    if (mesafeDeger == HIGH && gazDeger>250) { Serial.println("ikiHata"); }
    else if (mesafeDeger == HIGH && gazDeger < 250) { Serial.println("mesafe"); }
    else if (mesafeDeger == LOW && gazDeger > 250) { Serial.println("gaz"); }
    else { Serial.println("hataYok"); }
  
  while(Serial.available()){
    char c = Serial.read();
    if(c == '0')
    {
        motor.attach(servo1); //servonun 11 numaralı pinde olduğu tanıtıldı.
        motor.write(0);   //motorun 0 dereceye hareketi sağlandı.
        delay(1000);
    }
    else if(c == '1')
    {
        motor.attach(servo1); //servonun 11 numaralı pinde olduğu tanıtıldı.
        motor.write(90);  //motorun 90 dereceye hareketi sağlandı.
        delay(1000);
    }
    else if(c == '2')
    {
        digitalWrite(role1,HIGH);
    }
     else if(c == '3')
    {
        digitalWrite(role1,LOW); 
    }
    else if(c == '4')
    {
        digitalWrite(role2,HIGH);
    }
    else if(c == '5')
    {
        digitalWrite(role2,LOW); 
    }  
    }
}
