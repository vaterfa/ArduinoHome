#define led 4		//led 4 nolu pine baðlandý.
#define buton 5		//buton 5 nolu pine baðlandý.

void setup() {

	pinMode(led, OUTPUT);
	pinMode(buton, INPUT);
	Serial.begin(9600);
}

void loop() {	
	
	if (digitalRead(buton)==HIGH){		//Serial.read()=='b' koþulu konsoldan "b" harfi okunursa ledi yakar.

		digitalWrite(led, HIGH);

	}

	else if(digitalRead(buton)==LOW){		//Serial.read()=='k' koþulu konsoldan "k" harfi okunursa ledi söndürür.

		digitalWrite(led, LOW);

	}
}