//preparing stuff for next lesson

#define BTN D4
#define RED D3
#define YELLOW D2
#define GREEN D1


int currentState;
unsigned long previousMillis = 0;
const long interval = 1000;
int ledState = LOW;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT); 
  pinMode(GREEN, OUTPUT); 
  pinMode(BTN, INPUT_PULLUP);
  
  Serial.begin(115200);
}


void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    digitalWrite(RED, ledState);   
    digitalWrite(YELLOW, ledState);
    digitalWrite(GREEN, ledState);
  }
  
  currentState = digitalRead(BTN);
  Serial.println(currentState);
}
