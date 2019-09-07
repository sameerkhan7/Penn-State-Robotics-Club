# TutorialBot - The Wall Detecting Car

A car that never crashes into a wall. Uses an ultrasonic distance sensor to drive forward until it senses a wall and stops right before it. Uses an LED to indicate that it detects a wall.

**What you will learn**:
 - Basic C Programming
 - Basic electronic circuits
 - Arduino IO (Input-Output)
 - Sensing distances with an Ultrasonic sensor
 - (Optional) PWM Motor Speed Control

**Requirements**:
- The Arduino IDE 
- Robot materials from the club

## Setup the Arduino IDE
The first step is to download and install the Arduino IDE. IDE stands for integrated development environment and the program contains all the tools you need to develop, build, and install your program on the Arduino board. Download it [here](https://www.arduino.cc/en/main/software).

## Introduction to Basic Programming Logic with Arduinos
Programming can look hard at first but we're going to keep it simple and avoid anything you don't need to build a simple robot. Let's look at the basics.

### What is a variable?
A variable is a place to store a piece of data. It has a name, a value, and a type.
Learn how to create and use a variable on the Arduino [site](https://www.arduino.cc/en/Tutorial/Variables) before moving on.

### Setup and Loop
There are 2 important sections (functions) in the Arduino program (called a Sketch), `setup` and `loop`. 

```c
void setup() {
	// Some code goes here
}

void loop() {
	// Some other code goes here
}
```

The `setup` function runs once when the Arduino first turns on. When the `setup` function finishes running all of its code, the `loop` function then runs for forever.  Each time that `loop` finishes it is run again, hence the name loop!

**Why do we need setup and loop?**
```c
void setup() {
	pinMode(13, OUTPUT);
}
```
`setup` is useful for running one time code that configures Arduino pins so we can do things like add an LED or attach a Servo motor. For example, if we want to configure one of the pins on the Arduino as an output, we would do that in setup.

On the other hand, `loop` is where most of our program actually runs. Having a function that is continually called up to 117,000 times / second ([source](https://learn.sparkfun.com/blog/1687)) is really useful! We can do things like update a distance variable from our sensors or even use delays to slow down the program and toggle an LED.

Putting `setup` and `loop` together lets us a build an Arduino Sketch to do whatever we want!

For example, the code below cycles an LED on and off after every 1 second. Don't worry we'll be breaking it down more next.

```c
// Create a variable that stores
// the pin number where our LED is.
int LED_PIN = 13;

void setup() {
	// Set the LED_PIN as an OUTPUT
	pinMode(LED_PIN, OUTPUT);
}

void loop() {
	// Turn on the LED
	digitalWrite(LED_PIN, HIGH);
	// Wait 1000ms = 1s
	delay(1000);
	// Turn off the LED
	digitalWrite(LED_PIN, LOW);
	// Wait 1000ms = 1s
	delay(1000);
}
```
### LED Toggle Sketch Breakdown
```cint LED_PIN = 13;`

<!--stackedit_data:
eyJoaXN0b3J5IjpbLTE3MTY5MjA1MzAsMTUwNTMyODgxMyw2MD
kyNzg2MDksLTE0MjAyODI3MTgsMTk5NTc2MzI4NCw5NTMwNjA3
NzMsMTk0MzAwNzU0MywtODA2MzQ0ODA4LDk4NDkzMDE4NV19
-->