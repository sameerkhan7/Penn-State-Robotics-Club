#include <NewPing.h>
#include <Servo.h> 

const int sonarTrig = 9; 
const int sonarEcho = 10;
int servoPin = 3;

NewPing sonarSensor(sonarTrig, sonarEcho, 200); 
Servo Servo1;


int getDistance(){
  int d = 0;
  d = sonarSensor.ping_cm();
  Serial.println("Sonar distance: " + String(d));
  delay(300);
  return d;
}

void setup() {
  Serial.begin(9600);
  Servo1.attach(servoPin);
}

void loop() {
  if(getDistance() <= 50){
    Servo1.write(Servo1.read()+1);
    Serial.println("Servo postition: " + String(Servo1.read()));
    if(Servo1.read() == 180){
      Servo1.write(0);
    }
    delay(500);
  }
  
}
