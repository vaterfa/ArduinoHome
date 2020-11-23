#define sensor A0
#define gaz A1
int sensorDeger;
int gazDeger;
#define led 2

void setup() {

pinMode(led,OUTPUT);
Serial.begin(9600);

}

void loop() {

sensorDeger=analogRead(sensor);
if (sensorDeger>=35){digitalWrite(led,HIGH);}
else {digitalWrite(led,LOW);}
//Serial.println(sensorDeger);

gazDeger=analogRead(gaz);
if (gazDeger>=35){digitalWrite(led,HIGH);}
else {digitalWrite(led,LOW);}
Serial.println(gazDeger);
delay(500);

}
