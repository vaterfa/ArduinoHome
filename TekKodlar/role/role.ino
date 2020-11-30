#define role1ON 8
#define role1OFF 9
#define role1 5

void setup() {

pinMode(role1ON,INPUT);
pinMode(role1OFF,INPUT);
pinMode(role1,OUTPUT);

}

void loop() {

if (digitalRead(role1ON)){digitalWrite(role1,HIGH);}
if (digitalRead(role1OFF)){digitalWrite(role1,LOW);}

}
