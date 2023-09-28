# Line-Follower-and-Obstacle-avoiding-Car-with-Login-System
The System asks for entering password for security check and the user have three trials before the system forces the user to wait 10 seconds before the next three trials and if you entered it correctly it follows the line and it steers according to the readings we have from the infrared sensors and during following the line, the ultrasonic sensor checks for obstacles and display on the LCD what is the distance between the car and the next obstacle and if it is less than the MINIMUM_DISTANCE it begins the obstacle avoiding protocol and it sends message using uart to another atmega32 microcontroller which is responsible for firing the alarm using led and sounder and the sound is produced for a period of time proportional to the distance

>>> The drivers used are as follows:

For MCAL:

1- GPIO

2- UART

3- Timer

4- Interrupt

For HAL:

1- LCD

2- Keypad

3- DC-motor

4- buzzer

5- Ultrasonic sensor

6- Infrared Sensors



-Another Implementation of crash warning system on ATmega2560 is attached in the repository 
