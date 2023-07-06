# Arduino Self-Driving Car with Ultrasonic Sensors

This project involves building an Arduino-based auto-driving car that utilizes ultrasonic sensors to detect obstacles and make decisions on movement. The car can be started using a push button, and it is equipped with four motors for movement control. A servo motor is used to steer the front wheels. The car is programmed to respond to sensor readings and perform actions accordingly: turning left or right, moving forward, or stopping. In specific scenarios, such as detecting obstacles from multiple directions simultaneously, the car will emit a continuous beeping sound.

## Working Mechanism

1. The car's operation is initiated by pressing a push button, which sets the "isStarted" flag to true.

2. The Arduino continuously reads the distance measurements from the three ultrasonic sensors: front, left, and right.

3. Based on the sensor readings, the car's behavior is determined using conditional statements.

4. If all sensors indicate a distance below the threshold, the car stops and emits a continuous beeping sound.

5. If the front sensor detects an obstacle, the car's response depends on the readings of the left and right sensors.
   - If the left sensor detects an obstacle while the right sensor does not, the car turns left.
   - If the right sensor detects an obstacle while the left sensor does not, the car turns right.
   - If both the left and right sensors detect obstacles, the car stops and emits a continuous beeping sound.

6. If neither the left nor right sensors detect obstacles while the front sensor does, the car moves forward.

7. The car's movement is controlled by activating the appropriate motor pins, while the servo motor steers the front wheels.

## Installation

To recreate this project, follow these steps:

1. Gather the required components:
   - Arduino board (e.g., Arduino Uno)
   - Ultrasonic sensors (3x)
   - Servo motor
   - Push button
   - Four motors
   - Buzzer
   - Jumper wires
   - Breadboard or PCB
   - Power source (e.g., battery pack)

2. Set up the hardware:
   - Connect the ultrasonic sensors to the appropriate trigger and echo pins on the Arduino.
   - Connect the servo motor to the designated pin for steering.
   - Connect the motors for movement control to the corresponding motor pins.
   - Connect the push button to a digital input pin.
   - Connect the buzzer to a digital output pin.

3. Install the required libraries:
   - Install the "Servo" library for servo motor control.
   - Install the "NewPing" library for ultrasonic sensor measurements.

4. Open the Arduino IDE and create a new sketch.

5. Copy and paste the provided code (from maincode.ino) into the Arduino IDE.

6. Verify and upload the code to the Arduino board.

7. Connect the power source to the Arduino and the motor driver.

8. Press the push button to start the car, and observe its behavior based on the sensor readings.

Note: Adjust the sensor thresholds, pin assignments, and other parameters according to your specific hardware configuration.

9. Enjoy your Arduino auto-driving car with ultrasonic sensors!

Remember to ensure proper safety precautions while working with the hardware and during testing.

## Circuit

|  Arduino pins  | Electronic component |
|----------------|:--------------------:|
| D2  |  Push Button  |
| D4  |  Ultrasonic Sensor (Front Trigger) |
| D5  |  Ultrasonic Sensor (Left Trigger) |
| D6  |  Ultrasonic Sensor (Left Echo) |
| D7  |  Ultrasonic Sensor (Right Trigger) |
| D8  |  Ultrasonic Sensor (Right Echo) |
| D9  |  Motor 1 |
| D10 |  Motor 2 |
| D11 |  Motor 3 |
| D12 |  Motor 4 |
| D13 |  Servo Motor |
| A0  |  Buzzer |


## Programming languages used
<a href="https://www.arduino.cc/" target="_blank" rel="noreferrer"> <img src="https://cdn.arduino.cc/header-footer/prod/assets/favicon-arduino/favicon.ico" alt="blender" width="40" height="40"/> </a>


## Developer
*  [abhineetraj1](http://github.com/abhineetraj1)
