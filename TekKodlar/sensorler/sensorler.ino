#define mesafe A0
//#define gaz A1
#define led 2

void setup() {

pinMode(led,OUTPUT);
Serial.begin(9600);

}

void loop() {

/*if (analogRead(mesafe>=35)){digitalWrite(led,HIGH);}
else {digitalWrite(led,LOW);}
Serial.print("Mesafe değeri :");
Serial.println(analogRead(mesafe));
delay(500);*/

Serial.print("Gaz değeri :");
Serial.println(analogRead(A0));
delay(500);

}
