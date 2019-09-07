# Introduction to Basic Programming with Arduino's
Learning to program may seem like a daunting task, but we're going to keep it simple and avoid anything you don't need to build a simple robot. 

Let's get into the basics!

## What is a variable?
A variable is a place to store a piece of data. It has a name, a value, and a type.
Learn how to create and use a variable on the Arduino [site](https://www.arduino.cc/en/Tutorial/Variables) before moving on.

## Setup and Loop
There are 2 important sections (functions) in the Arduino program (called a Sketch), `setup` and `loop`. 

```c
void setup() {
	// Some code goes here
}

void loop() {
	// Some other code goes here
}
```

The `setup` function runs once when the Arduino first turns on. When the `setup` function finishes running all of its code, the `loop` function then runs for forever.  Each time that `loop` finishes it runs again, hence the name loop!

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
## LED Toggle Sketch Breakdown
Let's go through the above code step-by-step and try to understand it.
```c
int LED_PIN = 13;
```
Creates a variable of type `int` called `LED_PIN` and sets it equal to 13. Integers (int) can hold whole numbers either positive or negative.

```c
pinMode(LED_PIN, OUTPUT);
```

Tells the Arduino to configure pin LED_PIN as an output. Since `LED_PIN` equals 13, pin #13 is set as an output.

The modes you can set for a digital pin are: 

 - `INPUT` - Allows the Arduino to read either a 5V "HIGH" voltage or 0V "LOW" voltage
 - `OUTPUT` - Allows the Arduino to output either a 5V "HIGH" voltage or 0V "LOW" voltage
 - `INPUT_PULLUP` - Ignore [this](https://www.arduino.cc/en/Tutorial/DigitalPins) for now

*Side Note: Arduino's also have pins called Analog pins which can read or output voltages between 5V - 0V instead of just 5V or 0V*

```c
digitalWrite(LED_PIN, HIGH);
```
Sets the LED_PIN to HIGH (5V), this will deliver power to the LED and turn it on.

```c
delay(1000);
```
Tells the Arduino to pause and wait for 1000 milliseconds before moving on.

```c
digitalWrite(LED_PIN, LOW);
```
Sets the LED_PIN to LOW (0V), this will disable power to the LED and turn it off.

Phew that was a lot right? It gets easier from here trust us. Let's try and run the above code on our Arduino's now.

## Uploading a Sketch to an Arduino
Once you've written your program wouldn't it be nice to actually run it? 

Follow these directions to get going:
1. Open up the Arduino IDE and hit:
`File > New`

2. Then, copy paste the LED sketch from above into the text editor clearing all of the old code.

3. Under `Tools > Board`, make sure `Arduino/Genuino Uno` is selected

4. Connect your Arduino to your laptop
5. In `Tools > Port` select the port that you think is your Arduino. For windows it will say something like `COM{number}` on Mac it will look like `/dev/cu.{something}`
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTU1MTY2NTE2Myw1NjIyOTg1ODMsNzMwOT
k4MTE2XX0=
-->