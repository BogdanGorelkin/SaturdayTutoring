#define RED D3
#define YELLOW D2
#define GREEN D1

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT); 
  pinMode(GREEN, OUTPUT); 
}


void loop() { // Silly but working solution
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

  digitalWrite(YELLOW, LOW);
}
