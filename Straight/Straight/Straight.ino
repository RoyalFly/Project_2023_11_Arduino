#include "Servo.h"

Servo Turn_Servo;

int Motor_L_PWM = 6; 
int Motor_R_PWM = 5; 
int Motor_L_DIR = 7;
int Motor_R_DIR = 4;


void L_Motor(int dir,int speed)
{
  digitalWrite(Motor_L_DIR, dir);   
  analogWrite(Motor_L_PWM, speed);  
}

void R_Motor(int dir,int speed)
{
  digitalWrite(Motor_R_DIR, dir);   
  analogWrite(Motor_R_PWM, speed);  
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Turn_Servo.attach(2); //转向舵机置于9号引脚
  Turn_Servo.write(73); //初值设置
  pinMode(Motor_L_DIR, OUTPUT);  
  pinMode(Motor_L_PWM, OUTPUT);  
  pinMode(Motor_R_DIR, OUTPUT);  
  pinMode(Motor_R_PWM, OUTPUT);
  delay(10000);
}

void loop(){
  //L_Motor(HIGH,100);
  //R_Motor(HIGH,100);
}