int LED = 9;
int buzzer = 6;
int TrigPin = 2;
int EchoPin = 3;
int Motor = 11;
float dis;
bool flag = false;
int Light_state;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(TrigPin,OUTPUT);
  pinMode(EchoPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(TrigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin,LOW);
  
  dis = pulseIn(EchoPin, HIGH) / 58.0;
  dis = ((int)(dis * 100.0)) / 100.0;
   
    Serial.println(dis);
    
  if (dis > 40){
    noTone(buzzer);
    flag = false;
    digitalWrite(LED, LOW);
    Light_state = 0;
  }else
  if (dis <= 40 && dis >= 20){
    noTone(buzzer);
    flag = false;
    digitalWrite(LED, LOW);
    int p=(int)(dis*100);
    p=map(p,2000,4000,0,255);
    Light_state = 0;
    analogWrite(Motor,p);
  }else
  if (dis >= 10 && dis <= 20){
    flag = false;
    noTone(buzzer);
    Light_state = 0;
    digitalWrite(LED, LOW);
  }else
  if (dis <= 10){
    tone(buzzer, 784);
    flag = true;
  }
  if (flag){
    if (Light_state == 0){
      digitalWrite(LED, HIGH);
    }
    if (Light_state == 1){
      digitalWrite(LED,LOW);
    }
    Light_state = 1 - Light_state;
  }
  delay(70);
}
