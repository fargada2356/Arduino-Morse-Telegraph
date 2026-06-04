# Arduino Morse Telegraph

This project features a Morse Code Telegraph built using an **Arduino Uno** microcontroller. It integrates several hardware components that work in synergy to encode inputs, provide auditory and visual feedback, and display characters in real-time.

##  How It Works
* **The Button:** Acts as the primary input. A single short tap registers as a **dot (.)**, while holding the button down (for 1 second) registers as a **dash (-)**.
* **LCD Display (16x2):** Provides the main visual information, showing how the telegraph reacts to your input and printing the translated text.
* **Active Buzzer:** Emits a sound tone whenever the button is pressed or held down, mimicking a classic telegraph.
* **Red LED Diode:** Synchronizes with the buzzer to provide a clear visual light signal during button presses.
* **1-Digit 7-Segment Display:** The "main character" of the project. It is strictly tied into the software logic to display the current character or count dynamically.

---

## Project Structure

This project is built using **PlatformIO** extension via VS Code. Below is the necessary organization of the files and folders for the project:

```text
Morse-Telegraph/
├── src/                # Core logic and module files
│   ├── Button.h        # Detects dots and dashes based on press duration
│   ├── Buzzer.h        # Handles the telegraph sound feedback (Pin 11)
│   ├── LCD.h           # Visualizes typed text on the 16x2 screen
│   ├── Led.h           # Syncs the red light with the buzzer (Pin 13)
│   ├── morse_encoder.cpp # Main program containing setup() and loop()
│   └── segmentDisplay.h # Manages the 1-digit 7-segment pin setup (Pins 2-9)
└── platformio.ini      # Configures the project environment for Arduino Uno
``` 

---

##  Media & Demonstration

### Project Setup
Here is how the complete hardware configuration looks on the breadboard:
![Arduino Morse Telegraph Setup](https://media.discordapp.net/attachments/1204887824982347827/1512012924053360660/IMG_20260604_113901.jpg?ex=6a228b44&is=6a2139c4&hm=6815b8ebb861136ec7e29f67964705912d340bf187dbb2503d10fe3a57eaf059&=&format=webp&width=1760&height=1320)

### Video Demonstration
Here I am demonstrating the Morse Telegraph in action, showing the button inputs, buzzer sounds, and the 7-segment display updates:



https://github.com/user-attachments/assets/b851fc04-f61c-49b3-b482-72aec830606a



---

##  Hardware & Pin Configuration

The components share a common ground (GND) rail on the breadboard to close the circuit safely. Below are the precise pin mappings for the project:

### 1. 7-Segment Display Wiring (Made Simple)

The 1-digit display has 10 pins in total (5 on the top side, 5 on the bottom side). Here is the exact way to connect them from left to right:

#### TOP SIDE (Counted from Left to Right)
* **Pin 10** (Far Left) Connects to **Arduino Pin 8** (Middle bar)
* **Pin 9** Connects to **Arduino Pin 2** (Top-Left bar)
* **Pin 8** (Middle) **LEAVE EMPTY** (Not connected)
* **Pin 7** Connects to **Arduino Pin 7** (Top horizontal bar)
* **Pin 6** (Far Right) Connects to **Arduino Pin 6** (Top-Right bar)

#### BOTTOM SIDE (Counted from Left to Right)
* **Pin 1** (Far Left) Connects to **Arduino Pin 3** (Bottom-Left bar)
* **Pin 2** Connects to **Arduino Pin 4** (Bottom horizontal bar)
* **Pin 3** (Middle) Connects to a **Resistor**, which then goes to the **GND** rail
* **Pin 4** Connects to **Arduino Pin 5** (Bottom-Right bar)
* **Pin 5** (Far Right) Connects to **Arduino Pin 9** (Decimal Point dot)

---

### 2. Other Components (Button, LED & Buzzer)
* **The Button:** Connect one side to **Arduino Pin 12** and the other side to **GND** (minus rail).
* **The Red LED:** Connect the long leg to **Arduino Pin 13** and the short leg through a **Resistor** to **GND**.
* **The Buzzer:** Connect the positive (+) pin to **Arduino Pin 11** and the negative (-) pin to **GND**.
