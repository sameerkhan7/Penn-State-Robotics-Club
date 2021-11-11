//Turns motors on and off
int motorRight = P3_6;
int motorLeft = P3_7;

//Changes motor speed
int PWMRight = P2_6;
int PWMLeft = P2_7;

//Changes direction
int reverseRight = P5_4;
int reverseLeft = P5_5;

void moveForward(int power = 100,int time = 0){
  analogWrite(PWMRight, power);
  analogWrite(PWMLeft, power);
  digitalWrite(motorRight, HIGH);
  digitalWrite(motorLeft, HIGH);
  sleep(time);
  digitalWrite(motorRight, LOW);
  digitalWrite(motorLeft, LOW);
}
void moveBackward(int power = 100,int time = 0){
  analogWrite(PWMRight, power);
  analogWrite(PWMLeft, power);
  digitalWrite(reverseRight, HIGH);
  digitalWrite(reverseLeft, HIGH);
  digitalWrite(motorRight, HIGH);
  digitalWrite(motorLeft, HIGH);
  sleep(time);
  digitalWrite(reverseRight, LOW);
  digitalWrite(reverseLeft, LOW);
  digitalWrite(motorRight, LOW);
  digitalWrite(motorLeft, LOW);
}
void turnLeft(int power = 100,int time = 0){
  analogWrite(PWMRight, power);
  analogWrite(PWMLeft, power);
  digitalWrite(reverseLeft, HIGH);
  digitalWrite(motorRight, HIGH);
  digitalWrite(motorLeft, HIGH);
  sleep(time);
  digitalWrite(motorRight, LOW);
  digitalWrite(motorLeft, LOW);
  digitalWrite(reverseLeft, LOW);
}
void turnRight(int power = 100,int time = 0){
  analogWrite(PWMRight, power);
  analogWrite(PWMLeft, power);
  digitalWrite(reverseRight, HIGH);
  digitalWrite(motorRight, HIGH);
  digitalWrite(motorLeft, HIGH);
  sleep(time);
  digitalWrite(motorRight, LOW);
  digitalWrite(motorLeft, LOW);
  digitalWrite(reverseRight, LOW);
}
void stop(time = 0){
  digitalWrite(motorRight, LOW);
  digitalWrite(motorLeft, LOW);
  digitalWrite(reverseRight, LOW);
  digitalWrite(reverseLeft, LOW);
  sleep(time);
}
void setup() {
  //motor board pins
  pinMode(motorRight,OUTPUT);
  pinMode(motorLeft,OUTPUT);

  pinMode(PWMRight,OUTPUT);
  pinMode(PWMLeft,OUTPUT);

  pinMode(reverseRight,OUTPUT);
  pinMode(reverseLeft,OUTPUT);

  Serial.println(9600);
}

void loop() {
  moveForward(100,500);
}
