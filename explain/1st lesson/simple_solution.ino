#define RED D3
#define YELLOW D2
#define GREEN D1

void setup() {
  pinMode(RED, OUTPUT);
  // ...
  // ...
}


void loop() { // Silly but working solution
  digitalWrite(RED, HIGH); //Turn on red
  delay(4000);  // wait 4 sec

  digitalWrite(YELLOW, HIGH);
  delay(1000);

  digitalWrite(YELLOW, LOW); // Turn off yellow
  digitalWrite(RED, LOW); // Turn off red

  // ...
  // ...
  // ...
}
