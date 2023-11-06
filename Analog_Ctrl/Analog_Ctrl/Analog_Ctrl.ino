int LED_R = 9;
int LED_G = 10;
int LED_B = 11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_R,OUTPUT);
  pinMode(LED_G,OUTPUT);
  pinMode(LED_B,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(A0);
  Serial.println(value);
  if (value < 200){
    digitalWrite(LED_R,LOW);
    digitalWrite(LED_G,HIGH);
    digitalWrite(LED_B,HIGH);
  }else
  if (value < 400){
    digitalWrite(LED_R,HIGH);
    digitalWrite(LED_G,LOW);
    digitalWrite(LED_B,HIGH);
  }else
  if (value < 600){
    digitalWrite(LED_R,HIGH);
    digitalWrite(LED_G,HIGH);
    digitalWrite(LED_B,LOW);
  }else
  if (value < 800){
    digitalWrite(LED_R,LOW);
    digitalWrite(LED_G,LOW);
    digitalWrite(LED_B,HIGH);
  }else
  if (value < 1000){
    digitalWrite(LED_R,HIGH);
    digitalWrite(LED_G,LOW);
    digitalWrite(LED_B,LOW);
  }else{
    digitalWrite(LED_R,LOW);
    digitalWrite(LED_G,LOW);
    digitalWrite(LED_B,LOW);
  }
}
