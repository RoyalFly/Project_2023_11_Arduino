#include "EEPROM.h"

int adds_val = 0;
int adds_cnt = 1;
byte tot_cnt = 0;
byte value = 0;
int BOOT_1 = 9;
int boot_state = HIGH;

void setup() {
  // put your setup code here, to run once:
  pinMode(BOOT_1,INPUT_PULLUP);
  Serial.begin(9600);
  value = EEPROM.read(adds_val);
  tot_cnt = EEPROM.read(adds_cnt);
  Serial.print("power on times:");
  Serial.print(value,DEC);
  Serial.println();
  value+=1;
  EEPROM.write(adds_val,value);
}

void loop() {
  // put your main code here, to run repeatedly:
  int _boot_state = digitalRead(BOOT_1);
  if (_boot_state == HIGH){
    boot_state = HIGH;
  }
  if (_boot_state == LOW && boot_state == HIGH){
    delay(100);
    boot_state = !boot_state;
    tot_cnt++;
    EEPROM.write(adds_cnt,tot_cnt);
    Serial.print("Pressing times:");
    Serial.print(tot_cnt,DEC);
    Serial.println();
    delay(100);
  }
}
