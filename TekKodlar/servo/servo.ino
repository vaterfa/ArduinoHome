#include <Servo.h>

int butonServo0=2;
int butonServo90=4;
Servo motor;



void setup() {

pinMode(butonServo0,INPUT);
pinMode(butonServo90,INPUT);

}

void loop() {
	
if (digitalRead(butonServo0)==HIGH){  

    motor.attach(11);
    motor.write(0);
    delay(1300);
    
    }

if (digitalRead(butonServo90)==HIGH){
  
    motor.attach(11);
    motor.write(90);
    delay(1300);
    
    }
    

}
