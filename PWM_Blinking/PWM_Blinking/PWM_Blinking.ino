int led = 9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Serial.print("Hello World");
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led,LOW);
  int val;
  if (Serial.available()>0){
      val = Serial.read();
      val-=48;
      //Serial.println(val);
      if (val !=0){
        digitalWrite(led,HIGH);
        delay(val*500);
        digitalWrite(led,LOW);
      }
  }
}
