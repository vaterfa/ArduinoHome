#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#include <Servo.h>

char auth[] = "auth";

char ssid[] = "ssid";
char pass[] = "pass";

WidgetLCD lcdMesafe(V1);
WidgetLCD lcdGaz(V2);

int mesafeKontrol;
int gazDeger;
int mesafeDeger;

Servo motor;

#define role1 12
#define role2 14

#define mesafeSensor 4
#define gazSensor A0

BLYNK_CONNECTED() 
{
  Blynk.syncAll();
}

  BLYNK_WRITE(V0)
{
  motor.write(param.asInt());
}

  BLYNK_WRITE(V3)
{
  mesafeKontrol = param.asInt(); 
}

void sensorler()
{
  gazDeger = analogRead(gazSensor);
  mesafeDeger = digitalRead(mesafeSensor);
  
  if(mesafeKontrol==1){ 
    if (mesafeDeger != HIGH) {Blynk.virtualWrite(V1, "Mesafe Normal"); }
    else { Blynk.virtualWrite(V1, "MESAFE UYARI!!"); Blynk.notify("MESAFE UYARI!!"); }
  }
  else { Blynk.virtualWrite(V1, "M. Tespit Kapalı");}

  if (gazDeger < 150 && gazDeger > 40) {Blynk.virtualWrite(V2, "Gaz Normal");}
  else { Blynk.virtualWrite(V2, "GAZ UYARI!!"); Blynk.notify("GAZ UYARI!!"); }
}

void setup()
{
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);

  motor.attach(5);

  pinMode(mesafeSensor, INPUT);
  pinMode(gazSensor, INPUT);

  Blynk.notify("Bağlantı kuruldu.");  
}

void loop()
{
  Blynk.run();
  sensorler();
}
