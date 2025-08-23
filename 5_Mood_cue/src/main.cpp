#include <Arduino.h>
#include <Servo.h>

const int potPin = A0;
const int servoPin = 3;
Servo myServo;
int potValue;
int servoAngle;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  myServo.attach(servoPin);
}

void loop()
{
  potValue = analogRead(potPin);
  servoAngle = map(potValue, 0, 1023, 0, 179);

  Serial.print("Potentiometer value: ");
  Serial.print(potValue);
  Serial.print(" | Servo angle: ");
  Serial.println(servoAngle);

  myServo.write(servoAngle);
  delay(15);
}
