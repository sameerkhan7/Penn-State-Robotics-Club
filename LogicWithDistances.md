# Logic with Distance Sensors

Let's learn some basic logic by working through a robot that will turn on an LED if it's ultrasonic sensor detects something in front of it. 

## Importing the NewPing Library
In order to use our distance sensor we need to import the NewPing library. 

Under `Sketch > Include Library > Manage Libraries` search for the NewPing library. Install version `1.9.1`

![Installing NewPing](https://raw.githubusercontent.com/Penn-State-Robotics-Club/tutorials/master/resources/install_newping.png)

## What is ultrasonic sonar?
An ultrasonic sensor uses high frequency sound to measure distance. By pinging a burst of sound at an object and measuring the time it takes for the echo to be detected, we can calculate the distance. 
Read more about in detail [here](http://cmra.rec.ri.cmu.edu/content/electronics/boe/ultrasonic_sensor/1.html).
## Setting up the Ultrasonic sensor
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

## Setting up the ultrasonic sensor
First import the NewPing library, this gives us access to  the library we just installed
```c
#include <NewPing.h>
```

Now define the pins that we connected above
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

Now in the loop function let's get the distance and store it into our distance variable.
```c
void loop() {
	
}
```

<!--stackedit_data:
eyJoaXN0b3J5IjpbLTQyMTM4NjQ4MiwxMTk5NTY3ODI5LC00OD
Y3NTY0MSwxNDUxNjI0MTM0LC0xMzUyODAwMzkzLC0yMTAzMjU4
MzI5LC0xOTc4MDQ4ODU1LDExNjQwNDE4MDUsODE3ODk1NjI1XX
0=
-->