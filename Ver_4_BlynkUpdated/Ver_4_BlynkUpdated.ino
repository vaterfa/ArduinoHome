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

  BLYNK_WRITE(V3)
{
  if(param.asInt()==0) {mesafeKontrol=0;
      Blynk.setProperty(V3, "offLabel", "PASİF");}   
  else if(param.asInt()==1) {mesafeKontrol=1;
      Blynk.setProperty(V3, "onLabel", "AKTİF");}  
}  
  
  BLYNK_WRITE(V0)
{
  if(param.asInt()==0) {motor.write(200);
      Blynk.setProperty(V0, "offLabel", "KAPALI");}   
  else if(param.asInt()==1) {motor.write(80);
      Blynk.setProperty(V0, "onLabel", "AÇIK");}
}

  BLYNK_WRITE(V4)
{
  if(param.asInt()==0) {digitalWrite(role1, HIGH);
      Blynk.setProperty(V4, "offLabel", "KAPALI");}   
  else if(param.asInt()==1) {digitalWrite(role1, LOW);
      Blynk.setProperty(V4, "onLabel", "AÇIK");} 
}

  BLYNK_WRITE(V5)
{
  if(param.asInt()==0) {digitalWrite(role2, HIGH);
      Blynk.setProperty(V5, "offLabel", "KAPALI");}   
  else if(param.asInt()==1) {digitalWrite(role2, LOW);
      Blynk.setProperty(V5, "onLabel", "AÇIK");} 
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

  if (gazDeger < 210 && gazDeger > 40) {Blynk.virtualWrite(V2, "Gaz Normal");}
  else { Blynk.virtualWrite(V2, "GAZ UYARI!!"); Blynk.notify("GAZ UYARI!!"); }
}

void setup()
{
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);

  motor.attach(5);
  motor.write(200);

  pinMode(mesafeSensor, INPUT);
  pinMode(gazSensor, INPUT);

  pinMode(role1, OUTPUT);
  pinMode(role2, OUTPUT);

  digitalWrite(role1, HIGH);
  digitalWrite(role2, HIGH);  

  Blynk.notify("Bağlantı kuruldu.");  
}

void loop()
{
  Blynk.run();
  sensorler();
}
