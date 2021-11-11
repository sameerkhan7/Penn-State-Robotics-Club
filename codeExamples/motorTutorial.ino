void setup() {
  // Initialize all motor driver pins
  const int MOTOR1_FORWARD = 9; // IN 1
  const int MOTOR1_BACKWARD = 8; // IN 2
  const int MOTOR1_ENABLE = 10; // ENA
  const int MOTOR2_FORWARD = 7; // IN 3
  const int MOTOR2_BACKWARD = 6; // IN 4
  const int MOTOR2_ENABLE = 5; // ENB
  // Enable both of the motors
  digitalWrite(MOTOR1_ENABLE, HIGH);
  digitalWrite(MOTOR2_ENABLE, HIGH);
}

void moveForward(){
  // Setting the forward pin to high and backward to low will make motors rotate forward.         
  digitalWrite(MOTOR1_FORWARD, HIGH);  
  digitalWrite(MOTOR1_BACKWARD, LOW);    

  // Do the same for the right motor
  digitalWrite(MOTOR2_FORWARD, HIGH);
  digitalWrite(MOTOR2_BACKWARD, LOW);
}
void stopMoving(){
  // Setting the forward pin to low and backward to low will make motors atop rotating.         
  digitalWrite(MOTOR1_FORWARD, LOW);  
  digitalWrite(MOTOR1_BACKWARD, LOW);    

  // Do the same for the right motor
  digitalWrite(MOTOR2_FORWARD, LOW);
  digitalWrite(MOTOR2_BACKWARD, LOW);
}

void loop() {
  // Enable both of the motors
  moveForward();
  delay(3000);
  stopMoving();
  delay(3000);
}
