int BOOT_1 = 9;
int LED_R = 3;
int cnt=0;
int led_state = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(BOOT_1,INPUT_PULLUP);
  pinMode(LED_R,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int _boot_state = digitalRead(BOOT_1);
  if (_boot_state == HIGH){
    led_state = LOW;
  }
  if (_boot_state == LOW && led_state == LOW){
    led_state = HIGH;
    cnt++;
    for (int i=1;i<=3;i++){
      digitalWrite(LED_R,HIGH);
      delay(500);
      digitalWrite(LED_R,LOW);
      delay(500);
    }
    digitalWrite(LED_R,LOW);
    Serial.println(cnt);
  }
}
