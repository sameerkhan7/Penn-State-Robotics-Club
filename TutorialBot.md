# TutorialBot - The Wall Detecting Car

A car that never crashes into a wall. Uses an ultrasonic distance sensor to drive forward until it senses a wall and stops right before it. Uses an LED to indicate that it detects a wall.

**What you will learn**:
 - L298N Motor Controller setup for basic movement
 - (Optional) PWM signals for speed adjustments

## How does a Motor Work?
Watch this video on how  DC motors work:
<iframe width="560" height="315" src="https://www.youtube.com/embed/LAtPHANEfQo" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

TL;DW: DC motors take advantage of the [Lorentz force](https://en.wikipedia.org/wiki/Lorentz_force) to produce a torque. By manipulating a magnetic field along a permanent magnet, we can continuously generate a Lorentz force that drives our motor.

But don't worry if this looks complicated, because it's super simple for us. All we have to do is power the positive and negative ends and the motor's design will do all the work for us.

## Motor Setup
Follow the club instructions on building the actual robot. Here's a diagram for how the L298N motor controller should be hooked up to the Arduino:
![Wiring Diagram](https://raw.githubusercontent.com/Penn-State-Robotics-Club/tutorials/master/resources/l298_motor_wiring.png)
Connect `IN1` from L298N to `pin 7` on the Arduino
`IN2` -> `pin 6`
`IN3` -> `pin 5`
`IN4` -> `pin 4`
Connect `ENA` to `pin 9` and `ENB` to `pin 3`

## Motor Control
Start with the completed program from the last tutorial. Make sure to [import](https://github.com/Penn-State-Robotics-Club/tutorials/blob/master/LogicWithDistances.md#importing-the-newping-library) the NewPing library if you haven't already.  
Also move `trig` from the distance sensor to `pin 10` and `echo` to `pin 11`.
```c
#include <NewPing.h>

const int sonarTrig = 10;
const int sonarEcho = 11;
NewPing sonarSensor(sonarTrig, sonarEcho, 200);

int distance = 0;

void setup() {
	// Startup the Serial communication for the Serial Monitor
	Serial.begin(9600);
}

void loop() {
	// Get distance value from sensor
	distance = sonarSensor.ping_cm();
	// Print it out to the serial monitor
	Serial.println("Sonar distance: " + String(distance));

	// If-else statement
	if (distance < 10) {
		// Turn on the LED, if the distance is < 10cm
		digitalWrite(LED_PIN, HIGH);
	} else {
		// Turn off the LED, if the distance is not < 10cm
		digitalWrite(LED_PIN, LOW);
	}

	delay(30);
}
```
### Testing out the motors
Add the following code to their respective locations:
```c
// Add these pin assignments near the others
const int MOTOR1_FORWARD = 7; // IN 1
const int MOTOR1_BACKWARD = 6; // IN 2
const int MOTOR1_ENABLE = 9; // ENA
const int MOTOR2_FORWARD = 5; // IN 3
const int MOTOR2_BACKWARD = 4; // IN 4
const int MOTOR2_ENABLE = 3; // ENB

// Add these lines to the bottom of setup
// Enable both of the motors
digitalWrite(MOTOR1_ENABLE, HIGH);
digitalWrite(MOTOR2_ENABLE, HIGH);

// Edit the if-else statement to look like this:
// Setting forward pin to high and backward to low will make motors rotate forward .         
    digitalWrite(MOTOR1_FORWARD, HIGH);  
    digitalWrite(MOTOR1_BACKWARD, LOW);
    // PWM pin can range from 0 (no speed) to 255 (full speed). Here it is set to full speed.
    analogWrite(MOTOR1_PWM, 255);        

    // Do the same for the right motor
    digitalWrite(MOTOR2_FORWARD, HIGH);
    digitalWrite(MOTOR2_BACKWARD, LOW);
    analogWrite(MOTOR2_PWM, 255);
  } else {
    // If distance is not greater than 10, execute the following code:
    // Turn on LED.                                 
    digitalWrite(LED_PIN, HIGH);
    // Setting forward pin to low and backward to low will make the motors stop.        
    digitalWrite(MOTOR1_FORWARD, LOW);
    digitalWrite(MOTOR1_BACKWARD, LOW);
    // The motors will stop if both FORWARD & BACKWARD pin are set to zero, regardless of PWM input.
    // But setting it to zero is good convention.
    analogWrite(MOTOR1_PWM, 0);

    // Do the same for the right motor.
    digitalWrite(MOTOR2_FORWARD, LOW);
    digitalWrite(MOTOR2_BACKWARD, LOW);
    analogWrite(MOTOR2_PWM, 0);         
  }

```
<!--stackedit_data:
eyJoaXN0b3J5IjpbMjA1OTExNTM2OCwyOTAxODk2NzAsMTQ4Nj
g2NDA1MSwxNjkxMzgxNzgxLC04NzI1ODUyMzEsLTc0MDU3NDIy
MSwxNjE2NTM2MjU3LDE1MDUzMjg4MTMsNjA5Mjc4NjA5LC0xND
IwMjgyNzE4LDE5OTU3NjMyODQsOTUzMDYwNzczLDE5NDMwMDc1
NDMsLTgwNjM0NDgwOCw5ODQ5MzAxODVdfQ==
-->