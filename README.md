# Sensors And Actuators Based Parking Access Management
<div style="text-align:center"><img src="https://i.ibb.co/47D601z/image1.png" /></div>

> This is a student project, which aims to automate parking access and improve the associated user experience
---

### Table of Contents

- [Specifications](#specifications)
- [System Architecture](#system-architecture)
- [Demonstration](#demonstration)
- [Project Files](#project-files)
- [Author Info](#author-info)

---

## Specifications

### Parking Entrance

<div style="text-align:center"><img src="https://i.ibb.co/XCRwbBg/image2.png" /></div>

- The parking is reserved for subscribers, so it can be accessed by membership card, which contains the identifier of subscribed members, so when an unsubscribed driver tries to badge, a sound effect is triggered indicating that access is impossible.

- The car, once arrived at the entrance of the parking lot, stops to request a possible access. For this, it will be necessary to know if empty spaces are available, it is for this reason that we envisaged a seven segment display which will display the number of free places.

- If the car park is full, a sound effect via the buzzer is triggered to show the driver that access to the car park is impossible.

- When a subscriber arrives at the car park, he uses his membership card containing a unique identifier, the barrier opens thereafter and the number displayed decreases by 1. During its opening, a green LED lights up showing that a access is in progress, otherwise a red LED is on.

- A photoresistor placed after the entry barrier is used to trigger its closure. 

- The sound effect heard by a non-subscribed member is accompanied by a flashing of the red LED.

### Parking Exit

<div style="text-align:center"><img src="https://i.ibb.co/7j1QbDr/image3.png" /></div>

- To exit the car park, the subscriber reuses his card, when the barrier goes up, the green LED lights up by analogy to the process which is carried out at the entrance to the car park, otherwise another red LED is lit.

- When the car is outside the parking lot, information is sent to the entrance to increment the number displayed on the seven-segment display, by 1.

- The time spent for exit is controlled by a potentiometer near the exit. An LCD display is there to help to read the value (time in seconds) fixed by the potentiometer. 

---

## System Architecture

<div style="text-align:center"><img src="https://i.ibb.co/yQ70yMR/image4.png" /></div>

---

## Demonstration

<div style="text-align:center"><img src="https://i.ibb.co/yfL4FNw/image5.png" /></div>

### **A video demonstration is availbale via the following link :**

*(This content is not yet available)*

---

## Project Files

The project contains the following files :

1. [7Seg_Decoder.ino](7Seg_Decoder.ino) : contains the code that decodes the value sent by the entrance's arduino interface to be displayed on the 7 segment displayer
2. [Entrance_Interface.ino](Entrance_Interface.ino) : it does all the user interface management before and after entering into the parking
3. [Exit_Custom_Control.ino](Exit_Custom_Control.ino) : it acts as the interface between the exit parameters setting and the Arduino interface corresponding to the exit
4. [Exit_Interface.ino](Exit_Interface.ino) : it does all the user interface management dedicated for exit operation
5. [Ultrasonic_Interface.ino](Ultrasonic_Interface.ino) : it contains the code that reads Ultradonic sensor's values and controls some LEDs, in order to help the driver to well park

---

## Author Info

- Email - oussama.oulkaid@gmail.com
- LinkedIn - [Oussama Oulkaid](https://www.linkedin.com/in/oulkaid)
