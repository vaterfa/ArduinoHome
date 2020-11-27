#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#include <Servo.h>

Servo motor;

char auth[] = "m4SR4ubeivA8CkJCzhPxy7WkEhAbTux-";

char ssid[] = "N0D3M";
char pass[] = "456852789123";

BlynkTimer timer;

  BLYNK_WRITE(V1)
{
  int servoTut = param.asInt(); 
  motor.write(servoTut); 
}



void setup()
{
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
  timer.run();
  motor.attach(5);
  

  
}
