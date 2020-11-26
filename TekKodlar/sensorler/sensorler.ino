#define mesafe A0
#define gaz A1
int mesafeDeger;
int gazDeger;
#define led 2

void setup() {

pinMode(led,OUTPUT);
Serial.begin(9600);

}

void loop() {

mesafeDeger=analogRead(mesafe);
if (mesafeDeger>=35){digitalWrite(led,HIGH);}
else {digitalWrite(led,LOW);}
Serial.print("Mesafe değeri :");
Serial.println(mesafeDeger);
delay(500);

gazDeger=analogRead(gaz);
if (gazDeger>=35){digitalWrite(led,HIGH);}
else {digitalWrite(led,LOW);}
Serial.print("Gaz değeri :");
Serial.println(gazDeger);
delay(500);

}
