// Include the Servo library 
#include <Servo.h> 
// Declare the Servo pin 
int servoPin = 3; 
// Create a servo object 
Servo Servo1; 
void setup() {  
   Servo1.attach(servoPin); // We need to attach the servo to the used pin number 
}
void loop(){ 
   // Make servo go to 0 degrees 
   Servo1.write(0); 
   delay(2000); 
   // Make servo go to 90 degrees 
   Servo1.write(90); 
   delay(2000); 
   // Make servo go to 180 degrees 
   //Servo1.write(179); 
   //delay(2000);
}
