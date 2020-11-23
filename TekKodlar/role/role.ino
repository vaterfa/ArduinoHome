int role1ON=8;
int role1OFF=9;
int role1=5;
int roleONDurum;
int roleOFFDurum;

void setup() {

pinMode(role1ON,INPUT);
pinMode(role1OFF,INPUT);
pinMode(role1,OUTPUT);

}

void loop() {

roleONDurum = digitalRead(role1ON);
roleOFFDurum = digitalRead(role1OFF);

if (roleONDurum==HIGH){digitalWrite(role1,HIGH);}
else if (roleOFFDurum==HIGH){digitalWrite(role1,LOW);}

}
