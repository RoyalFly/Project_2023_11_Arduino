#include "Servo.h"

Servo Door;

int buzzer = 6;
long long Start_Time = -1;
int pos = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer, OUTPUT);
  Door.attach(9);
  Door.write(0);
}

void Open_(){
  while (millis()-Start_Time < 250){
    tone(buzzer,659);
    delay(10);
    //if ((millis()-Start_Time) % 15 == 0){
      pos++;
      if (pos <= 180){
        Door.write(pos);
      }else{
        pos = 180;
      }
    //}
  }
  while (millis()-Start_Time < 500){
    tone(buzzer,523);
    delay(10);
    //if ((millis()-Start_Time) % 15 == 0){
      pos++;
      if (pos <= 180){
        Door.write(pos);
      }else{
        pos = 180;
      }
    //}
  }
  while (millis()-Start_Time < 750){
    tone(buzzer,392);
    delay(10);
    //if ((millis()-Start_Time) % 15 == 0){
      pos++;
      if (pos <= 180){
        Door.write(pos);
      }else{
        pos = 180;
      }
    //}
  }
  while (millis()-Start_Time < 1000){
    tone(buzzer,523);
    delay(10);
    //if ((millis()-Start_Time) % 15 == 0){
      pos++;
      if (pos <= 180){
        Door.write(pos);
      }else{
        pos = 180;
      }
    //}
  }
  while (millis()-Start_Time < 1250){
    tone(buzzer,587);
    delay(10);
    //if ((millis()-Start_Time) % 15 == 0){
      pos++;
      if (pos <= 180){
        Door.write(pos);
      }else{
        pos = 180;
      }
    //}
  }
  while (millis()-Start_Time < 2000){
    tone(buzzer,784);
    delay(10);
    //if ((millis()-Start_Time) % 15 == 0){
      pos++;
      if (pos <= 180){
        Door.write(pos);
      }else{
        pos = 180;
      }
    //}
  }
  while (millis()-Start_Time < 2250){
    tone(buzzer,587);
    delay(10);
    //if ((millis()-Start_Time) % 15 == 0){
      pos++;
      if (pos <= 180){
        Door.write(pos);
      }else{
        pos = 180;
      }
    //}
  }
  while (millis()-Start_Time < 2500){
    tone(buzzer,659);
    delay(10);
    //if ((millis()-Start_Time) % 15 == 0){
      pos++;
      if (pos <= 180){
        Door.write(pos);
      }else{
        pos = 180;
      }
    //}
  }
  while (millis()-Start_Time < 2750){
    tone(buzzer,587);
    delay(10);
    //if ((millis()-Start_Time) % 15 == 0){
      pos++;
      if (pos <= 180){
        Door.write(pos);
      }else{
        pos = 180;
      }
   // }
  }
  while (millis()-Start_Time < 3000){
    tone(buzzer,392);
    delay(10);
    //if ((millis()-Start_Time) % 15 == 0){
      pos++;
      if (pos <= 180){
        Door.write(pos);
      }else{
        pos = 180;
      }
    //}
  }
  while (millis()-Start_Time < 3500){
    tone(buzzer,523);
    delay(10);
    //if ((millis()-Start_Time) % 15 == 0){
      pos++;
      if (pos <= 180){
        Door.write(pos);
      }else{
        pos = 180;
      }
    //}
  }
  noTone(buzzer);
}

void Close_(){
  while (pos > 0){
    pos--;
    Door.write(pos);
    delay(15);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int Light = analogRead(A0);
  if (Light < 750){
    if (Start_Time == -1){
      Start_Time = millis();
      Open_();
    }
  } else {
    if (Start_Time != -1){
      Start_Time = -1;
      Close_();
    }
  }
}
