#include "Servo.h"

Servo Door;

void setup() {
  // put your setup code here, to run once:
  Door.attach(9);
  Door.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  int Light = analogRead(A0);
  if (Light > 750){
    if (Door.read() != 0){
      for (int pos = Door.read(); pos >= 0; pos--){
        Door.write(pos);
        delay(15);
      }
    }
  }else{
    if (Door.read() != 180){
      for (int pos = Door.read(); pos <= 180; pos++){
        Door.write(pos);
        delay(15);
      }
    }
  }
}
