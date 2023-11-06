int NS_LED_R = 3;
int NS_LED_Y = 4;
int NS_LED_G = 5;
 
void setup() {
  // put your setup code here, to run once:
  pinMode(NS_LED_G,OUTPUT);
  pinMode(NS_LED_R,OUTPUT);
  pinMode(NS_LED_Y,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(NS_LED_R,HIGH);
  digitalWrite(NS_LED_G,HIGH);
  delay(5000);
  for (int i=1;i<=3;i++){
    digitalWrite(NS_LED_G,LOW);
    delay(300);
    digitalWrite(NS_LED_G,HIGH);
    delay(300);
  }
  digitalWrite(NS_LED_G,LOW);
  digitalWrite(NS_LED_Y,HIGH);
  delay(3000);
  digitalWrite(NS_LED_Y,LOW);
  digitalWrite(NS_LED_R,LOW);
  delay(9000);
}
