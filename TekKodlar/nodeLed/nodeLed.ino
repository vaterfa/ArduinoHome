#define led 4		
#define buton 5		

void setup() {

	pinMode(led, OUTPUT);
	pinMode(buton, INPUT);
	Serial.begin(9600);
}

void loop() {	
	
	if (digitalRead(buton)==HIGH){		
	//Serial.read()=='s' koþulu konsoldan 
	//"b" harfi okunursa ledi yakar.

		digitalWrite(led, HIGH);

	}

	else if(digitalRead(buton)==LOW){		
	//Serial.read()=='b' koþulu konsoldan 
	//"k" harfi okunursa ledi söndürür.

		digitalWrite(led, LOW);

	}
}