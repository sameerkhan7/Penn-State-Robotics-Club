const int LEDPin = A0;
int value = 0;

void setup() {
  Serial.begin(9600);
}


void loop() {
  value = analogRead(LEDPin);
  Serial.println("Analog value : ");
  Serial.println(value);
  delay(250);
}
