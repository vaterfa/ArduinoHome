#define led 4		//led 4 nolu pine baðlandý.
#define buton 5		//buton 5 nolu pine baðlandý.

int butonGirdi;
char konsolGirdi;


void setup() {

	pinMode(led, OUTPUT);
	pinMode(buton, INPUT);
	Serial.begin(9600);
}

void loop() {	

	konsolGirdi = Serial.read();
	butonGirdi = digitalRead(buton);
	
	if (butonGirdi==HIGH){		//girdi=='b' koþulu konsoldan "b" harfi okunursa ledi yakar.

		digitalWrite(led, HIGH);

	}

	else if(butonGirdi==LOW){		//girdi=='k' koþulu konsoldan "k" harfi okunursa ledi söndürür.

		digitalWrite(led, LOW);

	}
}