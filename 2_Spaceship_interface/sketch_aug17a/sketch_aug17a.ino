
int stateOfSwitch = 0;


void setup() {

  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {

  stateOfSwitch = digitalRead(2);


  if (stateOfSwitch == LOW) 
  {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
  else
  {
    digitalWrite(3, LOW);

    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    delay(1000);

    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(1000);
  }
}
