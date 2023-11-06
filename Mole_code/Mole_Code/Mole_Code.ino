int BOOT = 9;
int LED = 3;
int cnt = 0;
int last_time = -1;
unsigned long debounce_time = 50;
int last_boot_state;
int boot_state = LOW;
unsigned long last_debounce= 0;
bool if_start_timing = false;
unsigned long start_time = 0;
bool if_OUTPUT[4];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(BOOT, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = digitalRead(BOOT);
  if (reading != last_boot_state){
    last_debounce = millis();
  }
  if ((millis() - last_debounce) > debounce_time){
    if (reading != boot_state){
      boot_state = reading;
      if (boot_state == LOW){
        if (!if_start_timing){
          cnt = 0;
          start_time = millis();
          if_start_timing = true;
          if_OUTPUT[0]=false;
          if_OUTPUT[1]=false;
          if_OUTPUT[2]=false;
          if_OUTPUT[3]=false;
        }
        cnt++;
        Serial.println(cnt);
      }
    }
  }
  last_boot_state = reading;
  if (millis() - start_time > 1000 && !if_OUTPUT[0]){
    Serial.println("1s passed...");
    if_OUTPUT[0]=true;
  }
  if (millis() - start_time > 2000 && !if_OUTPUT[1]){
    Serial.println("2s passed...");
    if_OUTPUT[1]=true;
  }
  if (millis() - start_time > 3000 && !if_OUTPUT[2]){
    Serial.println("3s passed...");
    if_OUTPUT[2]=true;
  }
  if (millis() - start_time > 4000 && !if_OUTPUT[3]){
    Serial.println("4s passed...");
    if_OUTPUT[3]=true;
  }
  if (millis() - start_time > 5000 && if_start_timing){
    if_start_timing = !if_start_timing;
    if (cnt == 1){
      digitalWrite(LED, HIGH);
      delay(5000);
      digitalWrite(LED, LOW);
    }else
    if (cnt == 2){
      digitalWrite(LED, HIGH);
      delay(500);
      digitalWrite(LED,LOW);
      delay(500);
      digitalWrite(LED, HIGH);
      delay(500);
      digitalWrite(LED,LOW);
      delay(500);
    }else{
      digitalWrite(LED, HIGH);
      delay(1000);
      digitalWrite(LED, HIGH);
      delay(200);
      digitalWrite(LED,LOW);
      delay(200);digitalWrite(LED, HIGH);
      delay(200);
      digitalWrite(LED,LOW);
      delay(200);
    }
  }
}
