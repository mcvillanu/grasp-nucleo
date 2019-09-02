# grasp-nucleo

This project contains all the microcontroller code necessary for the GRASP.

Download visual studio code and the platformio extension in vs code to compile and upload to the Nucleo

# connections
- A3 to output of emg signal
- D5 to input signal of linear actuator drivers
- Ground nucleo and bread board

# debug
Noise issues; make sure electrodes are nice and sticky, change position to a large muscle area 
- change REF_VOLTAGAE in emg.h to higher or lower voltage
- ground to chassis ground
- move away from electronics

# to use the EMG
rest your arm on the table and flex either biceps or squeeze your hand into a fist

electrodes can be moved around to find the best spot

**use Putty to read the serial output!**


![connections](setup-photos/IMG_20190901_122850.jpg)
![connections](setup-photos/circuit.JPG)

![connections](setup-photos/InkedIMG_20190901_164441_LI.jpg)

# to do
Add a voltage regulator for emg signal input
    - **don't plug in battery until electrodes are in position** and unplug battery before taking off electrodes