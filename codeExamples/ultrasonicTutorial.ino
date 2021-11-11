#include <NewPing.h>
const int sonarTrig = 9; // Initialize pins for ultrasonic
const int sonarEcho = 10;
NewPing sonarSensor(sonarTrig, sonarEcho, 200); // Creates a NewPing object used to get the values from the sensor
// 200 is the max value in cm that it will read, anything passed 200cm that it detects will return 0
int distance = 0; // Initialize variable to hold our detected distance

void setup() {
  Serial.begin(9600);
  
}

void loop() {
  distance = sonarSensor.ping_cm(); // Function from NewPing library that returns the ultrasonic distance read in cm
  Serial.println("Sonar distance: " + String(distance)); // prints distance to console so we can see it
  delay(300); // Delay so no pings interfere with each other or occur to often
}
