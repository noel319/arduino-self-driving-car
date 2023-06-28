#include <Servo.h>
#include <NewPing.h>

// Pin Definitions
#define BUTTON_PIN 2
#define FRONT_SENSOR_TRIGGER_PIN 3
#define FRONT_SENSOR_ECHO_PIN 4
#define LEFT_SENSOR_TRIGGER_PIN 5
#define LEFT_SENSOR_ECHO_PIN 6
#define RIGHT_SENSOR_TRIGGER_PIN 7
#define RIGHT_SENSOR_ECHO_PIN 8
#define MOTOR1_PIN 9
#define MOTOR2_PIN 10
#define MOTOR3_PIN 11
#define MOTOR4_PIN 12
#define SERVO_PIN 13
#define BUZZER_PIN A0

// Constants
#define SENSOR_THRESHOLD 20 // Distance in centimeters
#define TURN_DURATION 1000
#define BEEP_DURATION 200

// Variables
Servo servo;
bool isStarted = false;
NewPing frontSensor(FRONT_SENSOR_TRIGGER_PIN, FRONT_SENSOR_ECHO_PIN);
NewPing leftSensor(LEFT_SENSOR_TRIGGER_PIN, LEFT_SENSOR_ECHO_PIN);
NewPing rightSensor(RIGHT_SENSOR_TRIGGER_PIN, RIGHT_SENSOR_ECHO_PIN);

void setup() {
  // Set the pin modes
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(MOTOR1_PIN, OUTPUT);
  pinMode(MOTOR2_PIN, OUTPUT);
  pinMode(MOTOR3_PIN, OUTPUT);
  pinMode(MOTOR4_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // Attach the servo to the appropriate pin
  servo.attach(SERVO_PIN);
}

void loop() {
  // Check if the button is pressed to start the car
  if (digitalRead(BUTTON_PIN) == LOW) {
    isStarted = true;
    delay(500); // Button debounce delay
  }

  // Check if the car is started
  if (isStarted) {
    // Read sensor values
    int frontDistance = frontSensor.ping_cm();
    int leftDistance = leftSensor.ping_cm();
    int rightDistance = rightSensor.ping_cm();

    // Check the sensor conditions
    if (frontDistance < SENSOR_THRESHOLD && leftDistance < SENSOR_THRESHOLD && rightDistance < SENSOR_THRESHOLD) {
      // Stop the car and beep continuously
      stopCar();
      beepContinuously();
    } else if (frontDistance < SENSOR_THRESHOLD) {
      if (leftDistance < SENSOR_THRESHOLD && rightDistance >= SENSOR_THRESHOLD) {
        // Turn left
        turnLeft();
      } else if (leftDistance >= SENSOR_THRESHOLD && rightDistance < SENSOR_THRESHOLD) {
        // Turn right
        turnRight();
      } else if (leftDistance >= SENSOR_THRESHOLD && rightDistance >= SENSOR_THRESHOLD) {
        // Stop the car and beep continuously
        stopCar();
        beepContinuously();
      }
    } else if (leftDistance < SENSOR_THRESHOLD && rightDistance < SENSOR_THRESHOLD) {
      // Move forward
      moveForward();
    } else {
      // Stop the car and beep continuously
      stopCar();
      beepContinuously();
    }
  } else {
    // Stop the car if not started
    stopCar();
  }
}

void moveForward() {
  digitalWrite(MOTOR1_PIN, HIGH);
  digitalWrite(MOTOR2_PIN, LOW);
  digitalWrite(MOTOR3_PIN, HIGH);
  digitalWrite(MOTOR4_PIN, LOW);
}

void turnLeft() {
  digitalWrite(MOTOR1_PIN, LOW);
  digitalWrite(MOTOR2_PIN, LOW);
  digitalWrite(MOTOR3_PIN, HIGH);
  digitalWrite(MOTOR4_PIN, LOW);
  servo.write(90); // Turn the servo to the left
  delay(TURN_DURATION);
}

void turnRight() {
  digitalWrite(MOTOR1_PIN, HIGH);
  digitalWrite(MOTOR2_PIN, LOW);
  digitalWrite(MOTOR3_PIN, LOW);
  digitalWrite(MOTOR4_PIN, LOW);
  servo.write(0); // Turn the servo to the right
  delay(TURN_DURATION);
}

void stopCar() {
  digitalWrite(MOTOR1_PIN, LOW);
  digitalWrite(MOTOR2_PIN, LOW);
  digitalWrite(MOTOR3_PIN, LOW);
  digitalWrite(MOTOR4_PIN, LOW);
  servo.write(45); // Reset the servo to the center position
}

void beepContinuously() {
  while (true) {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(BEEP_DURATION);
    digitalWrite(BUZZER_PIN, LOW);
    delay(BEEP_DURATION);
  }
}
