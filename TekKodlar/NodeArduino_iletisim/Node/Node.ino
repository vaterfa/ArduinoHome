#include <SoftwareSerial.h>
#define buton 5
#define led 14

int butonGirdi;

SoftwareSerial gonder(3, 1);

void setup()
{
	Serial.begin(9600);
	gonder.begin(9600);

	pinMode(led, OUTPUT);
	pinMode(buton, INPUT);
}

void loop()
{
	butonGirdi = digitalRead(buton);

	if (butonGirdi == HIGH) {

		gonder.write(123);
		delay(200);
		digitalWrite(led, HIGH);
	}

	else if (butonGirdi == LOW) {

		gonder.write(124);
		delay(200);
		digitalWrite(led, LOW);
	}


}
