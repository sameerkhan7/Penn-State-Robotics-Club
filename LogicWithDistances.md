# Logic with Distance Sensors

Let's learn some basic logic by working through a robot that will turn on an LED if it's ultrasonic sensor detects something in front of it. 

## Importing the NewPing Library
In order to use our distance sensor we need to import the NewPing library. 

Under `Sketch > Include Library > Manage Libraries` search for the NewPing library. Install version `1.9.1`

![Installing NewPing](https://raw.githubusercontent.com/Penn-State-Robotics-Club/tutorials/master/resources/install_newping.png)

## What is an ultrasonic sonar?
An ultrasonic sensor uses high frequency sound to measure distance. By pinging a burst of sound at an object and measuring the time it takes for the echo to be detected, we can calculate the distance. 
Read more about in detail [here](http://cmra.rec.ri.cmu.edu/content/electronics/boe/ultrasonic_sensor/1.html).
## Setting up the ultrasonic sensor
Let's first connect our sensor to the Arduino.
Here's a diagram to follow ([source](https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/)):

![Wiring Ultrasonic](https://raw.githubusercontent.com/Penn-State-Robotics-Club/tutorials/master/resources/wiring_ultrasonic.png)

 - Connect `Trig` from the Ultrasonic to `port 9` 
 - Connect `Echo` from
   the Ultrasonic to `port 10` 
  - Connect `GND` from Ultrasonic to `GND` on
   the Arduino 
  - Connect `VCC` from Ultrasonic to `5V` on the Arduino

Now that everything's wired up, lets get coding!!!

## Ultrasonic code setup
First import the NewPing library, this gives us access to  the library we just installed
```c
#include <NewPing.h>
```

Now define the pins that we connected above. `const` just means to make this variable a constant and prevent future code from changing it.
```c
const int sonarTrig = 9;
const int sonarEcho = 10;
```

Now let's create the NewPing object that we can use to get distance values. 200 is used as the max distance here, if the sonar reads something over 200cm it will return 0.

```c
NewPing sonarSensor(sonarTrig, sonarEcho, 200);
```

## Reading distances
In order to keep track of our distance in the program we should create a variable for it.
```c
int distance = 0;
```

In the loop function get the distance and store it into our distance variable. We add a small delay at the bottom so that the pings don't occur too frequently and interfere with each other.
```c
void loop() {
	distance = sonarSensor.ping_cm();
	
	delay(30);
}
```

### Printing the distance
We can use the serial monitor to print out values from our program. Add this line to `setup`
```c
void setup() {
	// ...
	Serial.begin(9600);
	// ...
}
```
Now we can use Serial to print the distance.
```c
void loop() {
	distance = sonarSensor.ping_cm();
	Serial.println("Sonar distance: " + String(distance));
	delay(30);
}
```

Here's the completed code for reference:
```c
#include <NewPing.h>

const int sonarTrig = 9;
const int sonarEcho = 10;
NewPing sonarSensor(sonarTrig, sonarEcho, 200);

int distance = 0;

void setup() {
	Serial.begin(9600);
}

void loop() {
	distance = sonarSensor.ping_cm();
	Serial.println("Sonar distance: " + String(distance));
	delay(30);
}
```

Upload and run the program on the Arduino, then click on the search icon to open the monitor:

![Opening the serial monitor](https://raw.githubusercontent.com/Penn-State-Robotics-Club/tutorials/master/resources/open_serial_monitor.png)
You should see your distances being spammed into the monitor!

## Basic logic
Let's add some more functionality to our robot. Let's use the distance value to turn  on a LED if the distance is less than 10cm.  Referencing the code from the [previous](https://github.com/Penn-State-Robotics-Club/tutorials/tree/master/Introduction.md) tutorial, we're going to use the LED attached to pin 13. 

```c
// Add a new pin variable next to the others
const int LED_PIN = 13;

void setup() {
	// ... Previous code goes here
	// Set the pin to output
	pinMode(LED_PIN, OUTPUT);
}
```

### The if and else statement
We can use an if statement to run code if a condition is met and an else statement to run code otherwise.  Read more about them [here](https://www.arduino.cc/en/Tutorial/ifStatementConditional). The basic syntax is:
```c
if (someCondition) {
	// If someCondition is true run the code inside these brackets
}
```
If with an else:
```c
if (someCondition) {
	// If someCondition is true run the code inside these brackets
} else {
	// If someCondition is false run the code inside these brackets
}
```
Here's an else-if where you check a second condition if the first condition is false:
```c
if (someCondition) {
	// If someCondition is true run the code inside these brackets.
} else if (someOtherCondition) {
	// If the someCondition is false and someOtherCondition is true
	// run the code inside these brackets.
}
```

### Updating the led
Let's use the if-else statements to turn the led off and on if the distance is less than 10:
```c

<!--stackedit_data:
eyJoaXN0b3J5IjpbLTY4ODY3Nzg4MSwtNjIyNzI1MTkyLC0xNz
cyNjgzMDIxLC0yMTIzMjM0MDgwLDE1NTg5ODA0MDYsMTE5OTU2
NzgyOSwtNDg2NzU2NDEsMTQ1MTYyNDEzNCwtMTM1MjgwMDM5My
wtMjEwMzI1ODMyOSwtMTk3ODA0ODg1NSwxMTY0MDQxODA1LDgx
Nzg5NTYyNV19
-->