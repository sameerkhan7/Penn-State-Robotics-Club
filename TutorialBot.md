# TutorialBot - The Wall Detecting Car

A car that never crashes into a wall. Uses an ultrasonic distance sensor to drive forward until it senses a wall and stops right before it. Uses an LED to indicate that it detects a wall.

**What you will learn**:
 - L298N Motor Controller setup for basic movement
 - (Optional) PWM signals for speed adjustments

## How does a Motor Work?
Watch this video on how  DC motors work. 
<iframe width="700" height="394" src="https://www.youtube.com/embed/LAtPHANEfQo" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

TL;DR: DC motors take advantage of the Lorentz force to produce a torque. 

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
```c
#include <NewPing.h>

const int sonarTrig = 9;
const int sonarEcho = 10;
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

<!--stackedit_data:
eyJoaXN0b3J5IjpbLTExNTY4NDg3OTEsMjkwMTg5NjcwLDE0OD
Y4NjQwNTEsMTY5MTM4MTc4MSwtODcyNTg1MjMxLC03NDA1NzQy
MjEsMTYxNjUzNjI1NywxNTA1MzI4ODEzLDYwOTI3ODYwOSwtMT
QyMDI4MjcxOCwxOTk1NzYzMjg0LDk1MzA2MDc3MywxOTQzMDA3
NTQzLC04MDYzNDQ4MDgsOTg0OTMwMTg1XX0=
-->