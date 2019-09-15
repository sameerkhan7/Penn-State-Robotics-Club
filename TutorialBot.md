# TutorialBot - The Wall Detecting Car

A car that never crashes into a wall. Uses an ultrasonic distance sensor to drive forward until it senses a wall and stops right before it. Uses an LED to indicate that it detects a wall.

**What you will learn**:
 - L298N Motor Controller setup for basic movement
 - (Optional) PWM signals for speed adjustments

## Motor Setup
Follow the club instructions on building the actual robot. Here's a diagram for how the L298N motor controller should be hooked up to the Arduino:
![Wiring Diagram](https://raw.githubusercontent.com/Penn-State-Robotics-Club/tutorials/master/resources/l298_motor_wiring.png)
Connect `IN1` from L298N to `pin 7` on the Arduino
`IN2` -> `pin 6`
`IN3` -> `pin 5`
`IN4` -> `pin 4`
Connect `ENA` to `pin 9` and `ENB` to `pin 3`

## Motor Control
St
<!--stackedit_data:
eyJoaXN0b3J5IjpbNDE1OTEyOTI1LDE2OTEzODE3ODEsLTg3Mj
U4NTIzMSwtNzQwNTc0MjIxLDE2MTY1MzYyNTcsMTUwNTMyODgx
Myw2MDkyNzg2MDksLTE0MjAyODI3MTgsMTk5NTc2MzI4NCw5NT
MwNjA3NzMsMTk0MzAwNzU0MywtODA2MzQ0ODA4LDk4NDkzMDE4
NV19
-->