// === Pin Definitions ===
#define MOTOR_DIR 12     // Controls the direction of the main motor (forward/backward)
#define MOTOR_PWR 3      // Controls the speed (PWM) of the main motor
#define AXIS_DIR 13      // Controls the direction of the front axle (left/right)
#define AXIS_PWR 11      // Controls the power (PWM) of the front axle
#define TRIG_PIN A1      // TRIG pin of the ultrasonic sensor
#define ECHO_PIN A0      // ECHO pin of the ultrasonic sensor

// === Global Variables ===
int laps = 0;            // Lap counter
int speed = 70;          // Vehicle speed (PWM: 0–255)
const int MAX_LAPS = 12;
const int DISTANCE_THRESHOLD = 100; // Minimum distance to move forward (cm)

// === Measure distance using the ultrasonic sensor ===
float measureDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  float distance = pulseIn(ECHO_PIN, HIGH) / 58.0;  // Convert to cm
  delay(10);
  return distance;
}

void setup() {
  // Initialize ultrasonic sensor pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Initialize motor and steering pins
  pinMode(MOTOR_DIR, OUTPUT);
  pinMode(MOTOR_PWR, OUTPUT);
  pinMode(AXIS_DIR, OUTPUT);
  pinMode(AXIS_PWR, OUTPUT);

  // Start serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  float distance = measureDistance();  // Get the current distance

  Serial.print("Distance: ");
  Serial.println(distance);

  if (laps >= MAX_LAPS) {
    stopVehicle();
    delay(10000);  // Pause for 10 seconds
  } else if (distance > DISTANCE_THRESHOLD) {
    moveForward();
    delay(10);
  } else {
    turnRight();
    delay(10);
  }

  // NOTE: Add lap-counting logic here if a sensor is available
}

// === Vehicle Movement Functions ===

void moveForward() {
  digitalWrite(MOTOR_DIR, HIGH);       // Forward direction
  analogWrite(MOTOR_PWR, speed);
  digitalWrite(AXIS_DIR, HIGH);        // Keep front axle straight
  analogWrite(AXIS_PWR, 0);
}

void moveBackward() {
  digitalWrite(MOTOR_DIR, LOW);        // Reverse direction
  analogWrite(MOTOR_PWR, speed);
  digitalWrite(AXIS_DIR, HIGH);
  analogWrite(AXIS_PWR, 0);
}

void turnLeft() {
  digitalWrite(MOTOR_DIR, HIGH);
  analogWrite(MOTOR_PWR, speed);
  digitalWrite(AXIS_DIR, LOW);         // Turn left
  analogWrite(AXIS_PWR, 255);          // Full turn power
}

void turnRight() {
  digitalWrite(MOTOR_DIR, HIGH);
  analogWrite(MOTOR_PWR, speed);
  digitalWrite(AXIS_DIR, HIGH);        // Turn right
  analogWrite(AXIS_PWR, 255);
}

void stopVehicle() {
  digitalWrite(MOTOR_DIR, LOW);
  analogWrite(MOTOR_PWR, 0);
  digitalWrite(AXIS_DIR, LOW);
  analogWrite(AXIS_PWR, 0);
