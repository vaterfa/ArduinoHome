#include <Servo.h>

int butonServo0=2;
int butonServo90=4;
int butSerTut0=0;
int butSerTut90=0;
Servo motor;



void setup() {

pinMode(butonServo0,INPUT);
pinMode(butonServo90,INPUT);


}

void loop() {



butSerTut0 = digitalRead(butonServo0);
butSerTut90 = digitalRead(butonServo90);

if (butSerTut0==HIGH){  

    motor.attach(11);
    motor.write(0);
    delay(1300);
    
    }

if (butSerTut90==HIGH){
  
    motor.attach(11);
    motor.write(90);
    delay(1300);
    
    }
    

}
