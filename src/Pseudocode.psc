BEGIN

  DEFINE constants for motor direction and power pins
  DEFINE constants for steering direction and power pins
  DEFINE constants for ultrasonic sensor TRIG and ECHO pins
  DEFINE constant for servo control pin

  FUNCTION measureDistance():
    Trigger the ultrasonic sensor
    Measure the duration of the echo signal
    Convert the duration to distance in centimeters
    RETURN the measured distance

  FUNCTION moveForward():
    Set motor direction to forward
    Apply power to rear motor
    Keep front axle straight

  FUNCTION moveBackward():
    Set motor direction to reverse
    Apply power to rear motor
    Keep front axle straight

  FUNCTION turnLeft():
    Set motor direction to forward
    Apply power to rear motor
    Turn front axle to the left (max power)

  FUNCTION turnRight():
    Set motor direction to forward
    Apply power to rear motor
    Turn front axle to the right (max power)

  FUNCTION stopVehicle():
    Stop rear motor
    Stop front axle motor
    Delay indefinitely

  FUNCTION setup():
    Set pin modes (input/output) for all components
    Attach servo to its pin
    Start serial communication

  FUNCTION loop():
    CALL measureDistance() and store result in variable `distance`

    IF lap count >= max laps THEN
      CALL stopVehicle()
      Wait for 10 seconds
    ELSE IF distance > threshold THEN
      CALL moveForward()
      Wait for short delay
    ELSE
      CALL turnRight()
      Wait for short delay

    // Note: Lap counting logic should be added if lap sensor is available

END
