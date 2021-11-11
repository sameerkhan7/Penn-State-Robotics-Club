void setup() {
  // Initialize all motor driver pins
  const int MOTOR1_FORWARD = 9; // IN 1
  const int MOTOR1_BACKWARD = 8; // IN 2
  const int MOTOR1_ENABLE = 10; // ENA
  const int MOTOR2_FORWARD = 7; // IN 3
  const int MOTOR2_BACKWARD = 6; // IN 4
  const int MOTOR2_ENABLE = 5; // ENB

}

void moveForward(int pwm){
  analogWrite(MOTOR1_ENABLE, pwm);
  analogWrite(MOTOR2_ENABLE, pwm);
  
  // Setting the forward pin to high and backward to low will make motors rotate forward.         
  digitalWrite(MOTOR1_FORWARD, HIGH);  
  digitalWrite(MOTOR1_BACKWARD, LOW);    

  // Do the same for the right motor
  digitalWrite(MOTOR2_FORWARD, HIGH);
  digitalWrite(MOTOR2_BACKWARD, LOW);
}
void stopMoving(){

  analogWrite(MOTOR1_ENABLE, 0);
  analogWrite(MOTOR2_ENABLE, 0);
  //analogWrite(MOTOR1_ENABLE, 255);
  //analogWrite(MOTOR2_ENABLE, 255);
  
  // Setting the forward pin to low and backward to low will make motors atop rotating.         
  digitalWrite(MOTOR1_FORWARD, LOW);  
  digitalWrite(MOTOR1_BACKWARD, LOW);    

  // Do the same for the right motor
  digitalWrite(MOTOR2_FORWARD, LOW);
  digitalWrite(MOTOR2_BACKWARD, LOW);
}

void loop() {
  // Enable both of the motors
  moveForward(200);
  delay(3000);
  stopMoving();
  delay(3000);
}
