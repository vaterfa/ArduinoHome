#define led 4		//led 4 nolu pine ba�land�.
#define buton 5		//buton 5 nolu pine ba�land�.

void setup() {

	pinMode(led, OUTPUT);
	pinMode(buton, INPUT);
	Serial.begin(9600);
}

void loop() {	
	
	if (digitalRead(buton)==HIGH){		//Serial.read()=='b' ko�ulu konsoldan "b" harfi okunursa ledi yakar.

		digitalWrite(led, HIGH);

	}

	else if(digitalRead(buton)==LOW){		//Serial.read()=='k' ko�ulu konsoldan "k" harfi okunursa ledi s�nd�r�r.

		digitalWrite(led, LOW);

	}
}