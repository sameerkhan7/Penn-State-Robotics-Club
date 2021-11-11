int IRSensor = 2; // connect ir sensor to arduino pin 3
int LED = 13; // conect Led to arduino pin 13

void setup() 
{
  pinMode (IRSensor, INPUT); // sensor pin is an input. Sends values to the Arduino
  pinMode (LED, OUTPUT); // Led pin is an output. Arduno outputs values to LED
}

void loop()
{
  int statusSensor = digitalRead (IRSensor); // Creates a variable that will constantly hold the value of IR sensor ( 1 or 0)
  
  if (statusSensor == 1){// Sensor detects something
    digitalWrite(LED, LOW); // LED LOW
  }
  
  else{// Sensor does not detect anything (statusSensor == 0)
    digitalWrite(LED, HIGH); // LED High
  }
}
