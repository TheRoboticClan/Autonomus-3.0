The Robotic Clan
==
### Welcome! ###

*Our team is made up of: Nathan Jolly, Moisés Palacio and Antonio Pérez.*

![](https://github.com/TheRoboticClan/Autonomus-3.0/blob/main/t-photos/Photo%20Official.jpg)

*Together we developed a robot car that can drive autonomously. We use two motors, one for the rear wheels and one for the steering axle. An ultrasonic sensor to detect obstacles and a cell phone to spot all the obstacles. We use the Arduino Uno microcontroller for our project.*

Content
==
> 
- **[schemes](schemes)**: contains a schematic diagram in PNG format of the electromechanical components illustrating all the elements (electronic components and motors) used in the vehicle and how they are connected to each other.

- **[src](src)**: contains code of control software for all components which were programmed to participate in the competition.

- **[t-photos](t-photos)**: contains 2 photos of the team (an official one and one funny photo with all team members).

- **[v-photos](v-photos)**: contains 6 photos of the vehicle (from every side, from top and bottom).

- **[video](video)**: contains the video.mp4 file with the robot driving demonstration.

Mobility management
==

Our vehicle is based on a remote-control (RC) car that was modified to function autonomously. The mobility system focuses on controlling both the direction and movement of the vehicle. The steering mechanism uses a DC motor to turn the front wheels, while another DC motor drives the rear wheels, which are responsible for propulsion. We use an Arduino UNO and connect it to the L298P motor driver. We considered using this motor driver because we find it easier to use and it has the input for the two motors we need.

**Motor Selection and Implementation**

Two DC motors are used in this vehicle. One is dedicated to steering the front wheels, and the other is used for driving the rear wheels. DC motors were chosen due to their simplicity, availability, and ease of integration with the existing RC car structure. The driving motor provides enough torque to move the car effectively, and the steering motor allows for smooth directional control.

**Chassis Design and Assembly**

The chassis is made of durable plastic and comes from the original remote-control car. We modified the structure to support autonomous movement by integrating components from another electronics kit. Both the board and the motor driver were components from another **kit (KS0428)** that we had used previously. These included sensors, a microcontroller, and power supply connections. No 3D-printed parts were used, but components were mounted securely to ensure stability and balance during operation.

**Engineering Principles**

Several engineering concepts were applied to improve performance:

Torque: Ensured the rear motor could generate enough force to move the car efficiently.

Speed and control: Balancing speed with control was essential to maintain accurate steering.

Weight distribution: The placement of components was planned to avoid imbalance between the front (steering) and rear (driving) sections.


**Construction and Components**

While the base was a commercial RC car, we added modules from another kit to support autonomous navigation. Components were carefully mounted, and wiring was organized to prevent interference with movement. Though no CAD files were used, the construction process involved careful planning and adaptation.

**Discussion and Improvements**

Transforming an RC car into an autonomous robot presented challenges, especially in integrating new components without redesigning the chassis. Future improvements could include adding encoders for better motor control, using servos for more precise steering, or designing a custom 3D-printed chassis optimized for weight and layout.


Energy and sensor management
==

Our vehicle is powered by rechargeable lithium batteries, chosen for their efficiency and ability to deliver consistent power throughout the operation.

The vehicle uses two ultrasonic sensors and a smartphone as a camera. The ultrasonic sensors are used to detect track walls: one detects the outer walls, and the other detects the inner walls. This helps the vehicle navigate and stay within the boundaries.

The smartphone camera is used to detect the color of blocks on the track. Based on the color recognized, the vehicle performs specific actions. This allows it to interact intelligently with its environment.

We use an Arduino Uno as the microcontroller, with a sensor shield mounted on top. This shield simplifies connections to the ultrasonic sensors and other components. The sensors are connected to the digital pins of the shield using jumper wires.

The motors are connected through a motor driver, which is also connected to the Arduino. The smartphone is connected to the Arduino via an OTG (On-The-Go) cable, allowing it to send camera input to the microcontroller.

A wiring diagram would include:

Ultrasonic sensors wired to the sensor shield

Motor driver connected to the motors and Arduino Uno

Power lines from lithium batteries to Arduino and motor driver

OTG cable linking the smartphone to the Arduino


This configuration ensures reliable power delivery and efficient sensor integration, enabling autonomous navigation and decision-making based on real-time data.