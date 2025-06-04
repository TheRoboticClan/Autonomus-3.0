The Robotic Clan
==
### Welcome! ###

*Our team is made up of: Moisés Palacio, Nathan Jolly and Antonio Pérez.*

*Together we developed a robot car that can drive autonomously. We use two motors, one for the rear wheels and one for the steering axle. An ultrasonic sensor to detect obstacles and a cell phone to spot all the obstacles. We use the Arduino Uno microcontroller for our project.*

Content
==
> 
- **schemes**: contains a schematic diagram in PNG format of the electromechanical components illustrating all the elements (electronic components and motors) used in the vehicle and how they are connected to each other.

- **src**: contains code of control software for all components which were programmed to participate in the competition.

- **t-photos**: contains 2 photos of the team (an official one and one funny photo with all team members).

- **v-photos**: contains 6 photos of the vehicle (from every side, from top and bottom).

- **video**: contains the video.mp4 file with the robot driving demonstration.

Mobility management
==

In this folder is how we connect the motors to our board. We use an Arduino UNO and connect it to the L298P motor driver. We considered using this motor driver because we find it easier to use and it has the input for the two motors we need. Both the board and the driver motor are components from another **kit (KS0428)** that we had used previously.

To move the robot we used, from a driving axis of a remote control car that we had, a motor and we connected it to the motor driver to pin 2 and 1 which is fixed to digital pin 3 and digital pin 12 of the Arduino UNO. We decided to use this motor and put the driving axis at the back of the robot to make it easier for our robot to move forward.

To drive the motor we decided to build a drive shaft ourselves using some tires from the Obstacle Avoidance Smart Car kit, some sweet wire, popsicle sticks, and a couple of cable clips. In order to direct the driving axis we use a servo motor that is connected to the Sensor Shield.

Energy and sensor management
==

We use two rechargeable lithium batteries. The cell with the two batteries is connected to the drivier motor which directs the power to the motor, the arduino UNO and the sensor shield.

We use the following components:

- **Servomotor**: where the ultrasonic sensor are placed to locate the traffic lights and have a broader view.

- **One ultrasonics sensor (HC-SR04)**: To determine the distance between the robot and the wall.
