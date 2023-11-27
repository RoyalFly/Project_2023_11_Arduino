#include "Servo.h"

Servo Turn_Servo;

int sensor[5] = {A0, A1, A2, A3, A4}; //灰度传感器的5个模拟信号输入引脚
int raw_data[5] = {0, 0, 0, 0, 0};
const int error_bit[5] = {-2, -1, 0, 1, 2};
int Motor_L = 11; //11号为左电机
int Motor_R = 12; //12号为右电机

const float kp_ = 0; //要调的pid参数
const float ki_ = 0;
const float kd_ = 0;

float pout_,iout_,dout_,output_; 
int err = 0, err_sum = 0, last_err_ = 0, i_max_ = 7, output_max_ = 30; //i_max_和output_max_要调
int servo_ang_ = 90;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Turn_Servo.attach(9); //转向舵机置于9号引脚
  Turn_Servo.write(90); //初值设置
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 5; i++){ //读传感器值并且二值化,1 -> black
    raw_data[i] = analogRead(sensor[i]);
    if (raw_data[i] > 200){ //ToDo: 具体测定白线的灰度，此处200待定
      raw_data[i] = 1;
    }else{
      raw_data[i] = 0;
    }
  }

  //舵机控制
  bool Error_State = false;
  if (raw_data[0] == 0 && raw_data[1] == 0 && raw_data[2] == 0 && raw_data[3] == 0 && raw_data[4] == 0
    || raw_data[0] == 1 && raw_data[1] == 1 && raw_data[2] == 1 && raw_data[3] == 1 && raw_data[4] == 1){ //五路白和五路黑，位置错误，直接停机
    Error_State = true;
    err = 0; //跑成这样要么是寄了，要么没在场地上，重置状态
    last_err_ = 0;
    err_sum_ = 0;
    servo_ang_ = 90;
  } else 
  if (raw_data[0] == 1){
    err = -2;
  } else 
  if (raw_data[4] == 1){
    err = 2;
  } else
  if (raw_data[1] == 1){
    err = -1;
  } else
  if (raw_data[3] == 1){
    err = 1;
  }

  //PID计算，具体怎么做自行百度PID算法
  err_sum_ += err;
  if (err_sum_ > i_max_ ){ //积分限幅
    err_sum_ = i_max_;
  }
  if (err_sum_ < (-1)*i_max_ ){
    err_sum_ = (-1) * i_max_;
  }

  pout_ = kp_ * err_;
  iout_ = ki_ * err_sum_;
  dout_ = kd_ * (err_ - last_err_);
  output_ = pout_ + iout_ + dout_;
  if (output_ > output_max_){
    output_ = output_max_;
  }
  if (output_ < (-1)*output_max_){
    output_ = (-1) * output_max_;
  }
  last_err_ = err_;

  int ctrl = (int)output_;
  servo_ang_ += ctrl;
  Turn_Servo.write(servo_ang_);

  //电机控制
  if (!Error_State){
    analogWrite(Motor_L,100);
    analogWrite(Motor_R,100);
  } else {
    analogWrite(Motor_L,0);
    analogWrite(Motor_R,0);
  }
}
