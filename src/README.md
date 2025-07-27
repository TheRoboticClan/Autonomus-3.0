Control software
====
This folder (`/src`) contains the control software for the autonomous vehicle, developed in two stages:

---

## 1. `autonomousfree.ino` — Obstacle Avoidance Logic

This Arduino sketch is designed for the **open round** of the competition. It controls the robot car using:

- An **ultrasonic sensor** mounted on a servo to detect walls.
- A pair of **DC motors**: one for propulsion and one for steering.
- Simple logic:
  - If no obstacle is detected, the car **moves forward**.
  - If an obstacle is detected ahead (distance < threshold), the car **turns right** to avoid it.
  - After 12 laps, the car **stops**.

### Key Features:
- Obstacle detection using `pulseIn()`.
- Steering logic using PWM and digital control.
- Loop counter for laps completed.

---

## 2. `obstacle.ino` — Color-Based Navigation

This Arduino sketch is used during the **second round**, where the car's direction is based on color recognition:

- The Arduino starts by **moving forward** immediately.
- A **smartphone** detects the color of a block (either red or green) using its camera and sends the result via **USB OTG**.
- The Arduino receives the color command (`"RED"` or `"GREEN"`):
  - `"GREEN"` → Car moves **left**
  - `"RED"` → Car moves **right**

### Serial Communication:
- Commands are sent over serial using a Python script running in Termux.
- The Arduino reads the serial input and reacts accordingly.

---

## `detect_color.py` — Python Script for Smartphone

This Python script (not included here but referenced) should run in **Termux** on Android:

- Uses `cv2` (OpenCV) to detect green or red blocks in the camera feed.
- Sends either `"GREEN\n"` or `"RED\n"` over serial to the Arduino via OTG.

### Python Libraries Required:
- `opencv-python`
- `pyserial`

---

## Notes

- Both `.ino` files reuse the same motor and servo variable names to keep consistency.
- Ensure the baud rate in both Arduino and Python scripts matches (`9600` recommended).
- The car should always be connected to the smartphone via OTG during the color round.

---

## Files in This Folder

| File Name         | Purpose                                 |
|-------------------|------------------------------------------|
| `autonomusfree.ino`  | Autonomous navigation using distance     |
| `obstacle.ino` | Color-based decision control via serial  |
