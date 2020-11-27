#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#include <Servo.h>

char auth[] = "auth";

char ssid[] = "ssid";
char pass[] = "pass";

WidgetLCD lcdMesafe(V1);
WidgetLCD lcdGaz(V2);

Servo motor;

int servoTut;

#define role1 0
#define role2 4

#define mesafeSensor 2
#define gazSensor A0
int mesafeDeger;
int gazDeger;

  BLYNK_WRITE(V0)
{
  servoTut = param.asInt(); 
  motor.write(servoTut); 
}

void setup()
{
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);

  motor.attach(5);

  pinMode(mesafeSensor, INPUT);
  pinMode(gazSensor, INPUT);

  digitalWrite(role1, HIGH);
  digitalWrite(role2, HIGH);
}

void loop()
{
	Blynk.run();

	mesafeDeger = digitalRead(mesafeSensor);
	gazDeger = analogRead(gazSensor);

	if (mesafeDeger != HIGH) {Blynk.virtualWrite(V1, "Mesafe Normal"); }
	else { Blynk.virtualWrite(V1, "MESAFE UYARI!!"); Blynk.notify("MESAFE UYARI!!"); }

	if (gazDeger < 250 && gazDeger > 40) {Blynk.virtualWrite(V2, "Gaz Normal");}
	else { Blynk.virtualWrite(V2, "GAZ UYARI!!"); Blynk.notify("GAZ UYARI!!"); }
}
