#include <Arduino.h>

const int tempSensorPin = A0;
const float baselineTemp = 35.0;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(9600);

  for (int i = 0; i < 5; i++)
  {
    for (int pinNo = 3; pinNo <= 5; pinNo++)
    {
      pinMode(pinNo, OUTPUT);
      digitalWrite(pinNo, HIGH);
      delay(100);
      digitalWrite(pinNo, LOW);
    }
  }
}

void loop()
{
  int tempSensorVal = analogRead(tempSensorPin);
  delay(2000);
  float voltage = tempSensorVal * (5.0 / 1023.0);
  float temperature = (voltage - 0.5f) * 100.0f; // MCP9700: 10 mV/°C, 0.5 V @ 0°C

  Serial.print("Sensor value: ");
  Serial.println(tempSensorVal);
  Serial.print("Voltage: ");
  Serial.println(voltage, 3);
  Serial.print("Temperature: ");
  Serial.println(temperature, 1);
  Serial.println();

  if (temperature < 34)
  {

    digitalWrite(3, HIGH);
    delay(200);
    digitalWrite(3, LOW);
  }
  else if (temperature > 36)
  {

    digitalWrite(5, HIGH);
    delay(200);
    digitalWrite(5, LOW);
  }
  else
  {

    digitalWrite(4, HIGH);
    delay(200);
    digitalWrite(4, LOW);
  }
}
