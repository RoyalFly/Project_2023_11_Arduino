int LED = 9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(A0);
  value = constrain(value, 580, 850);
  int aim = map(value, 580,850,0,255);
  analogWrite(LED,255-aim);
}
