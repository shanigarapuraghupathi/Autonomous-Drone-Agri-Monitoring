// Autonomous Agricultural Drone for Crop Monitoring
// Developed in Embedded C/C++
// Microcontroller: Arduino Uno or Mega

// Include Libraries
#include <Servo.h>

// Motor Pins
#define MOTOR1_PIN 3
#define MOTOR2_PIN 5
#define MOTOR3_PIN 6
#define MOTOR4_PIN 9

// Sensors
#define ALTITUDE_TRIG_PIN 7
#define ALTITUDE_ECHO_PIN 8
#define OBSTACLE_TRIG_PIN 10
#define OBSTACLE_ECHO_PIN 11

// Servo for Camera Stabilization
Servo cameraServo;

// Altitude Setpoint (meters converted to cm)
#define TARGET_ALTITUDE 200  // 2 meters

// Variables
long duration;
int altitude;
int obstacleDistance;

void setup() {
  // Motor pins as OUTPUT
  pinMode(MOTOR1_PIN, OUTPUT);
  pinMode(MOTOR2_PIN, OUTPUT);
  pinMode(MOTOR3_PIN, OUTPUT);
  pinMode(MOTOR4_PIN, OUTPUT);

  // Sensor pins
  pinMode(ALTITUDE_TRIG_PIN, OUTPUT);
  pinMode(ALTITUDE_ECHO_PIN, INPUT);
  pinMode(OBSTACLE_TRIG_PIN, OUTPUT);
  pinMode(OBSTACLE_ECHO_PIN, INPUT);

  // Initialize Servo
  cameraServo.attach(12);

  // Serial Monitor
  Serial.begin(9600);
}

void loop() {
  altitude = measureDistance(ALTITUDE_TRIG_PIN, ALTITUDE_ECHO_PIN);
  obstacleDistance = measureDistance(OBSTACLE_TRIG_PIN, OBSTACLE_ECHO_PIN);

  Serial.print("Current Altitude: ");
  Serial.print(altitude);
  Serial.println(" cm");

  Serial.print("Obstacle Distance: ");
  Serial.print(obstacleDistance);
  Serial.println(" cm");

  maintainAltitude(altitude);
  obstacleAvoidance(obstacleDistance);

  stabilizeCamera();

  delay(500); // Refresh every half second
}

// Function to Measure Distance
int measureDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  return distance;
}

// Function to Maintain Altitude
void maintainAltitude(int currentAltitude) {
  if (currentAltitude < TARGET_ALTITUDE - 20) {
    // Ascend - Increase motor speed
    analogWrite(MOTOR1_PIN, 200);
    analogWrite(MOTOR2_PIN, 200);
    analogWrite(MOTOR3_PIN, 200);
    analogWrite(MOTOR4_PIN, 200);
  } else if (currentAltitude > TARGET_ALTITUDE + 20) {
    // Descend - Decrease motor speed
    analogWrite(MOTOR1_PIN, 100);
    analogWrite(MOTOR2_PIN, 100);
    analogWrite(MOTOR3_PIN, 100);
    analogWrite(MOTOR4_PIN, 100);
  } else {
    // Stable Hover
    analogWrite(MOTOR1_PIN, 150);
    analogWrite(MOTOR2_PIN, 150);
    analogWrite(MOTOR3_PIN, 150);
    analogWrite(MOTOR4_PIN, 150);
  }
}

// Function for Obstacle Avoidance
void obstacleAvoidance(int obstacleDistance) {
  if (obstacleDistance < 100) {
    // Stop motors immediately if obstacle detected
    analogWrite(MOTOR1_PIN, 0);
    analogWrite(MOTOR2_PIN, 0);
    analogWrite(MOTOR3_PIN, 0);
    analogWrite(MOTOR4_PIN, 0);

    Serial.println("Obstacle detected! Hovering...");
    delay(2000); // Wait for obstacle to clear
  }
}

// Function to Stabilize Camera Servo
void stabilizeCamera() {
  static int angle = 90;
  cameraServo.write(angle);
}
