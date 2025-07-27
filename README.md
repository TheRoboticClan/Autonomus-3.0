# The Robotic Clan

### Welcome!

*Our team is made up of Nathan Jolly, Moisés Palacio, and Antonio Pérez.*

![Team Photo](https://github.com/TheRoboticClan/Autonomus-3.0/blob/main/t-photos/Photo%20Official.jpg)

Together we developed a robot car that drives autonomously. It uses:
- Two DC motors (one for rear-wheel drive, one for steering)
- Ultrasonic sensors for obstacle detection
- A smartphone for visual recognition
- An Arduino Uno microcontroller for control logic

---

## Repository Content

- **[`schemes/`](schemes)** – Contains a schematic diagram (PNG) showing how all electronic components and motors are connected.

- **[`src/`](src)** – Source code controlling all components, programmed for the competition.

- **[`t-photos/`](t-photos)** – Two team photos: an official one and a funny one.

- **[`v-photos/`](v-photos)** – Six photos of the vehicle (top, bottom, and all sides).

- **[`video/`](video)** – A video (`video.mp4`) demonstrating the robot driving autonomously.

---

## Mobility Management

Our robot is based on a commercial remote-control (RC) car, modified to run autonomously.

### Steering and Propulsion

- **DC motor 1** – Drives the rear wheels (propulsion)
- **DC motor 2** – Controls the front wheels (steering)
- Controlled using an **Arduino UNO** and an **L298P motor driver**, chosen for its simplicity and compatibility with two motors

### Motor Selection and Integration

DC motors were selected for:
- Ease of integration
- Availability
- Simplicity

One motor delivers torque for motion; the other enables accurate steering.

### Chassis and Components

- Chassis: Durable plastic, reused from the RC car
- Components (Arduino board, motor driver, sensors): Taken from **Kit KS0428**
- No CAD or 3D-printed parts used; everything was mounted manually for balance and durability

### Engineering Concepts Applied

- **Torque** – Rear motor chosen for enough driving force
- **Control** – Balanced speed and steering to maintain precision
- **Weight Distribution** – Components were strategically placed to avoid imbalance

### Construction Insights

Adapting a commercial RC chassis for autonomy brought challenges in fitting and wiring new components. In future versions, we plan to:
- Add encoders for better motor feedback
- Use servo motors for finer steering control
- Build a custom 3D-printed chassis optimized for balance

---

## Energy & Sensor Management

### Power Supply

Powered by **rechargeable lithium batteries** to ensure steady voltage and long operation time.

### Sensors

- **Two ultrasonic sensors** – Detect track boundaries:
  - One for outer walls
  - One for inner walls

- **Smartphone camera** – Detects **colored blocks** on the track. The robot reacts based on detected colors.

### Connections and Integration

- **Arduino Uno** – The core microcontroller
- **Sensor shield** – Makes wiring easier and cleaner
- **Ultrasonic sensors** – Connected to the shield via jumper wires
- **Motor driver** – Linked to both the motors and Arduino
- **OTG cable** – Connects the smartphone to the Arduino for vision input

### Wiring Diagram Includes:

- Ultrasonic sensors → sensor shield  
- Motor driver → motors + Arduino  
- Power connections → batteries to Arduino & motor driver  
- OTG connection → smartphone to Arduino  

---