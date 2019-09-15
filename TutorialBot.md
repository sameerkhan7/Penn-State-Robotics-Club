# TutorialBot - The Wall Detecting Car

A car that never crashes into a wall. Uses an ultrasonic distance sensor to drive forward until it senses a wall and stops right before it. Uses an LED to indicate that it detects a wall.

**What you will learn**:
 - L298N Motor Controller setup for basic movement
 - (Optional) PWM signals for speed adjustments

## How does a Motor Work?
Watch this [video](https://youtu.be/LAtPHANEfQo) on how DC motors work.

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
Let's add our motors in such a way that the robot will move when the distance is greater than 10, and stop when they are closer than 10.

Add these pin assignments near the others
```c
const int MOTOR1_FORWARD = 7; // IN 1
const int MOTOR1_BACKWARD = 6; // IN 2
const int MOTOR1_ENABLE = 9; // ENA
const int MOTOR2_FORWARD = 5; // IN 3
const int MOTOR2_BACKWARD = 4; // IN 4
const int MOTOR2_ENABLE = 3; // ENB
```
Add these lines to the bottom of `setup`:
```c
// Enable both of the motors
digitalWrite(MOTOR1_ENABLE, HIGH);
digitalWrite(MOTOR2_ENABLE, HIGH);
```
And edit the if-else statement to look like this:
```c
if (distance < 10) {
	// Turn on the LED
	digitalWrite(LED_PIN, HIGH);
	
	// Turn off the left motor by setting both pins to low.     
    digitalWrite(MOTOR1_FORWARD, LOW);
    digitalWrite(MOTOR1_BACKWARD, LOW;

    // Do the same for the right motor.
    digitalWrite(MOTOR2_FORWARD, LOW);
    digitalWrite(MOTOR2_BACKWARD, LOW);     
  } else {
    // Turn off the LED.                                 
    digitalWrite(LED_PIN, LOW);
    
    // Setting the forward pin to high and backward to low will make motors rotate forward.         
    digitalWrite(MOTOR1_FORWARD, HIGH);  
    digitalWrite(MOTOR1_BACKWARD, LOW);    

    // Do the same for the right motor
    digitalWrite(MOTOR2_FORWARD, HIGH);
    digitalWrite(MOTOR2_BACKWARD, LOW);
 }
```

If your motors are spinning in the wrong direction, either flip the wiring on the motor controller or flip the pin numbers in the pin assignment variables. Ex: If motor 1 is spinning backwards when it should be moving forwards, set `MOTOR1_FORWARDS = 6` and `MOTOR1_BACKWARDS = 7`.

Your robot should now be moving pretty fast towards the wall and should stop moving when it gets close enough. But isn't it kinda too fast? But how do we slow the motors down? We can't control the voltage of the battery which is hooked into our motor controller.

## Pulse Width Modulation Theory
Instead of varying the voltage connected to our motors we can adjust the speed by turning them on and off really quickly. Take a look at this signal graph ([Source](https://learn.sparkfun.com/tutorials/pulse-width-modulation/duty-cycle)):

![enter image description here](https://cdn.sparkfun.com/assets/f/9/c/8/a/512e869bce395fbc64000002.JPG)
When the signal is in the up position we provide power to the motor and when it's down we turn off the power. The higher the percentage of the duty cycle the longer the signal is in the on state. If the signal is on for longer then so is the motor! This is called Pulse-Width-Modulation or PWM, we are changing the "width" of the on signal to increase or decrease the motor speed. Read more [here](https://www.analogictips.com/pulse-width-modulation-pwm/).

## Applying PWM control to our Sketch
Arduino gives us 256 different PWM values from 0 - 255 that we can use to create varying duty cycles. 0 means completely off and 255 means completely on. 128 would give us a duty cycle of around 50%.

First, **remove** the following lines from setup:
```c
digitalWrite(MOTOR1_ENABLE, HIGH);
digitalWrite(MOTOR2_ENABLE, HIGH);
```

Then add these lines right after we turn the motor on:
```c
// Set the duty cycle to ~78%.
// Aka turn our motor on for 78% of the time
// and off for 22% of the time.
analogWrite(MOTOR1_ENABLE, 200);
analogWrite(MOTOR2_ENABLE, 200);
```

And  add these lines right after we turn the motor off:
```c
// Set the duty cycle to 0%.
// Technically this is uneccessary to cut motor power
// since we already set the forward and backward pins to LOW.
analogWrite(MOTOR1_ENABLE, 0);
analogWrite(MOTOR2_ENABLE, 0);
```

Upload and try it out. You should notice the motors are a little slower than last time. Play with the value `200` and see how increasing or decreasing it affects the motor speed.

## Improving the braking distance
You might observe that the robot moves quite a bit when we turn the motors off. This is because the momentum of the robot keeps it moving even when the power is off. In order to apply some braking force we can leave the enable pins on.

Change the analogWrite lines when we turn the motors off to this:
```c
// Leave the enable pin HIGH to create a braking force
analogWrite(MOTOR1_ENABLE, 255);
analogWrite(MOTOR2_ENABLE, 255);
```

By leaving the `ENA` and `ENB` pins `HIGH` while the `FORWARD` and `BACKWARD` pins are `LOW` we effectively apply a large load to the motors. The topic of how this works is complicated and so I've left the [read](https://circuitglobe.com/induction-motor-braking.html) for the curious. Basically think of this like regenerative braking on a Tesla.

Try to compare the braking distance between the old code and the new code! See if you can find a noticeable difference or not.

## Congrats!
You've reached the end of the Penn State Robotics introductory tutorials! Now it's time to build some robots.
<!--stackedit_data:
eyJoaXN0b3J5IjpbMjEwOTA1MTcyOCw2NTM4MjYyNDYsODA2ND
g2MDM0LC05OTY3MjczMjUsMTY3OTc4NDg4OCwtMTgyOTkyNTgz
LC01ODQ2NDg0MDYsMjkwMTg5NjcwLDE0ODY4NjQwNTEsMTY5MT
M4MTc4MSwtODcyNTg1MjMxLC03NDA1NzQyMjEsMTYxNjUzNjI1
NywxNTA1MzI4ODEzLDYwOTI3ODYwOSwtMTQyMDI4MjcxOCwxOT
k1NzYzMjg0LDk1MzA2MDc3MywxOTQzMDA3NTQzLC04MDYzNDQ4
MDhdfQ==
-->