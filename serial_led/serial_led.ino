/*

QuantumLight
SISINTY SASMITA PATRA
SMITA KUNDARGI
JEANNE VICTOR

This program lit the led if the temp is high and 
it turns off the led if temp is low

*/

int pin = 13;

void setup()
{
    Serial.begin(9600);
    pinMode(pin, OUTPUT);
}

void loop()
{
  while (Serial.available() > 0) {
    int input = Serial.parseInt(); 
    if(input == 1)
    {
      digitalWrite(pin, HIGH); //if temp is high led is on
    }
    else
    {
      digitalWrite(pin, LOW);//If temp is low, led is off
    }
  }
}
