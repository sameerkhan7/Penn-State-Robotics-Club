# Logic with Distance Sensors

Let's learn some basic logic by working through a robot that will turn on an LED if it's ultrasonic sensor detects something in front of it.

## Importing the NewPing Library
In order to use our distance sensor we need to import the NewPing library. 

Under `Sketch > Include Library > Manage Libraries` search for the NewPing library. Install version `1.9.1`

![Installing NewPing](https://raw.githubusercontent.com/Penn-State-Robotics-Club/tutorials/master/resources/install_newping.png)

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

## Writing the program
First import the NewPing library, this gives us access to  the library we just installed
```c
#include <NewPing.h>
```

Now define the pins that we connected above
```c
const int 
```

<!--stackedit_data:
eyJoaXN0b3J5IjpbLTE4MDkwMDk0NDUsMTE5OTU2NzgyOSwtND
g2NzU2NDEsMTQ1MTYyNDEzNCwtMTM1MjgwMDM5MywtMjEwMzI1
ODMyOSwtMTk3ODA0ODg1NSwxMTY0MDQxODA1LDgxNzg5NTYyNV
19
-->