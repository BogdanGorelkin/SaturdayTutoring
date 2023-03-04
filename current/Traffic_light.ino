//preparing stuff for next lesson
const int RED = D7;
const int YELLOW = D6;
const int GREEN = D5;
const int BUZZER = D0;
const int interrupt_btn = D4;

int DELAY_GREEN = 5000;
int DELAY_YELLOW = 2000;
int DELAY_RED = 5000;
bool interrupt_flag = false;

ICACHE_RAM_ATTR void btn_pressed() {
  digitalWrite(LED_BUILTIN, HIGH);
  interrupt_flag = true;
}


void start_traffic_light() {
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, HIGH);
  delay(3000);

  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, HIGH);
  delay(5000);

  digitalWrite(YELLOW, HIGH);
  delay(2000);

  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, HIGH);
  tone(BUZZER, 440, 1000);
  delay(1000);
  digitalWrite(GREEN, LOW);
  delay(3000);
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(interrupt_btn), btn_pressed, RISING);
  Serial.begin(115200);
}


void loop() {
  // start_traffic_light();
  if(interrupt_flag) {
    Serial.println("btn pressed!");
    digitalWrite(GREEN, HIGH);
    tone(BUZZER, 440, 1000);
    delay(1000);
    digitalWrite(GREEN, LOW);
    delay(1000);
    digitalWrite(GREEN, HIGH);
    tone(BUZZER, 440, 1000);
    delay(1000);
    digitalWrite(GREEN, LOW);
    delay(1000);
    interrupt_flag = false;
    digitalWrite(LED_BUILTIN, LOW);
  }
}

