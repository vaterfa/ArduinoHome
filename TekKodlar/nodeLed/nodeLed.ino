#define led 4		
#define buton 5		

void setup() {

	pinMode(led, OUTPUT);
	pinMode(buton, INPUT);
	Serial.begin(9600);
}

void loop() {	
	
	if (digitalRead(buton)==HIGH){		
	//Serial.read()=='s' ko�ulu konsoldan 
	//"b" harfi okunursa ledi yakar.

		digitalWrite(led, HIGH);

	}

	else if(digitalRead(buton)==LOW){		
	//Serial.read()=='b' ko�ulu konsoldan 
	//"k" harfi okunursa ledi s�nd�r�r.

		digitalWrite(led, LOW);

	}
}