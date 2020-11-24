#define led 4		//led 4 nolu pine ba�land�.
#define buton 5		//buton 5 nolu pine ba�land�.

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
	
	if (butonGirdi==HIGH){		//girdi=='b' ko�ulu konsoldan "b" harfi okunursa ledi yakar.

		digitalWrite(led, HIGH);

	}

	else if(butonGirdi==LOW){		//girdi=='k' ko�ulu konsoldan "k" harfi okunursa ledi s�nd�r�r.

		digitalWrite(led, LOW);

	}
}