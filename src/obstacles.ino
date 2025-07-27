// Motor and steering pin definitions
#define MOTOR_DIR 12     // Motor direction pin (forward/backward)
#define MOTOR_PWR 3      // Motor power/speed pin
#define AXLE_DIR 13      // Steering direction pin (left/right)
#define AXLE_PWR 11      // Steering power/speed pin

// Motion parameters
int speedValue = 70;            // Vehicle speed
String colorDetected = "";      // Color input from smartphone
bool colorReceived = false;     // Flag to check if color was received

void setup() {
  Serial.begin(9600);            // Serial communication with smartphone

  pinMode(MOTOR_DIR, OUTPUT);
  pinMode(MOTOR_PWR, OUTPUT);
  pinMode(AXLE_DIR, OUTPUT);
  pinMode(AXLE_PWR, OUTPUT);
}

void loop() {
  // Check for color input from the smartphone
  if (Serial.available()) {
    colorDetected = Serial.readStringUntil('\n');
    colorDetected.trim();  // Remove spaces/newlines
    colorReceived = true;  // Set flag to true after receiving input
  }

  // Act based on the color received
  if (colorReceived) {
    if (colorDetected == "GREEN") {
      driveLeftSide();     // Green block → drive left
    } else if (colorDetected == "RED") {
      driveRightSide();    // Red block → drive right
    } else {
      stopVehicle();       // Unknown input → stop
    }
  } else {
    // No color yet → move forward in a straight line
    driveForward();
  }
}

// ========== Motion Control Functions ==========

void driveForward() {
  digitalWrite(MOTOR_DIR, HIGH);
  analogWrite(MOTOR_PWR, speedValue);
  digitalWrite(AXLE_DIR, HIGH);   // Neutral direction
  analogWrite(AXLE_PWR, 0);       // No turn
}

void driveLeftSide() {
  digitalWrite(MOTOR_DIR, HIGH);
  analogWrite(MOTOR_PWR, speedValue);
  digitalWrite(AXLE_DIR, LOW);
  analogWrite(AXLE_PWR, 255);     // Steer left
}

void driveRightSide() {
  digitalWrite(MOTOR_DIR, HIGH);
  analogWrite(MOTOR_PWR, speedValue);
  digitalWrite(AXLE_DIR, HIGH);
  analogWrite(AXLE_PWR, 255);     // Steer right
}

void stopVehicle() {
  digitalWrite(MOTOR_DIR, LOW);
  analogWrite(MOTOR_PWR, 0);
  digitalWrite(AXLE_DIR, LOW);
  analogWrite(AXLE_PWR, 0);
}
