//preparing stuff for next lesson
const int BTN = D4;
const int RED = D7;
const int YELLOW = D6;
const int GREEN = D5;
bool interrupt_flag = false;

ICACHE_RAM_ATTR void btn_pressed() {
  Serial.println("btn pressed!");
  interrupt_flag = true;
}

void start_traffic_light() {
  Serial.println("Start traffic light");
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(RED, HIGH); //Turn on red
  delay(4000);  // wait 4 sec

  digitalWrite(YELLOW, HIGH);
  delay(1000);

  digitalWrite(YELLOW, LOW); // Turn off yellow
  digitalWrite(RED, LOW); // Turn off red

  digitalWrite(GREEN, HIGH);
  delay(5000);
  
  // Start blinking
  digitalWrite(GREEN, LOW);
  delay(500);
  digitalWrite(GREEN, HIGH);
  delay(500);
  digitalWrite(GREEN, LOW);
  delay(500);
  digitalWrite(GREEN, HIGH);
  delay(500);
  digitalWrite(GREEN, LOW);


  digitalWrite(YELLOW, HIGH);
  delay(2000);
  Serial.println("End traffic light");
}

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT); 
  pinMode(GREEN, OUTPUT); 
  pinMode(BTN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BTN), btn_pressed, RISING);
  Serial.begin(115200);
}


void loop() {
  while(!interrupt_flag){
    Serial.println("Start traffic light");
    digitalWrite(RED, LOW);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(RED, HIGH); //Turn on red
    delay(4000);  // wait 4 sec

    digitalWrite(YELLOW, HIGH);
    delay(1000);

    digitalWrite(YELLOW, LOW); // Turn off yellow
    digitalWrite(RED, LOW); // Turn off red

    digitalWrite(GREEN, HIGH);
    delay(5000);
    
    // Start blinking
    digitalWrite(GREEN, LOW);
    delay(500);
    digitalWrite(GREEN, HIGH);
    delay(500);
    digitalWrite(GREEN, LOW);
    delay(500);
    digitalWrite(GREEN, HIGH);
    delay(500);
    digitalWrite(GREEN, LOW);


    digitalWrite(YELLOW, HIGH);
    delay(2000);
    Serial.println("End traffic light");
  }
  Serial.println("set flag to false");
  interrupt_flag = false;
}
