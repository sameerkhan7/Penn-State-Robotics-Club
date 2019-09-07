# The Wall Detecting Car

The car that never crashes into a wall. Uses an ultrasonic distance sensor to drive forward until it senses a wall and stops right before it. Uses an LED to indicate that it detects a wall.

**What you will learn**:
 - Basic C Programming
 - Basic electronic circuits
 - Arduino IO (Input-Output)
 - PWM Motor Speed Control
 - Sensing distances with an Ultrasonic sensor

**Requirements**:
- The Arduino IDE 
- Robot materials from the club

## Setup the Arduino IDE
The first step is to download and install the Arduino IDE. IDE stands for integrated development environment and the program contains all the tools you need to develop, build, and install your program on the Arduino board. Download it [here](https://www.arduino.cc/en/main/software).

## Introduction to Basic Programming Logic with Arduinos
Programming can look hard at first but we're going to keep it simple and avoid anything you don't need to build a simple robot. Let's look at some basics:

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

The setup function runs once when the 
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTEzODM1MjY3NDEsOTUzMDYwNzczLDE5ND
MwMDc1NDMsLTgwNjM0NDgwOCw5ODQ5MzAxODVdfQ==
-->