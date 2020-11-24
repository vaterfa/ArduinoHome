#include <SoftwareSerial.h>
#define led 7

int konsolGirdi;

SoftwareSerial al(1, 0);



void setup()
{
	Serial.begin(9600);

	al.begin(9600);

	pinMode(led, OUTPUT);
}

void loop()
{
	konsolGirdi = al.read();

	Serial.println(konsolGirdi);
	delay(1000);

	if (konsolGirdi == 123) {

		digitalWrite(led, HIGH);

	}

	else if (konsolGirdi == 124) {


		digitalWrite(led, LOW);
	}

}
