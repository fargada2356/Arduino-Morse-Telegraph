# Arduino Morse Telegraph

This project features a digital Morse Code Telegraph built using an **Arduino Uno** microcontroller. It integrates several hardware components that work in synergy to encode inputs, provide auditory and visual feedback, and display characters in real-time.

##  How It Works
* **The Button:** Acts as the primary input. A single short tap registers as a **dot (.)**, while holding the button down (for 1 second) registers as a **dash (-)**.
* **LCD Display (16x2):** Provides the main visual information, showing how the telegraph reacts to your input and printing the translated text.
* **Active Buzzer:** Emits a sound tone whenever the button is pressed or held down, mimicking a classic telegraph.
* **Red LED Diode:** Synchronizes with the buzzer to provide a clear visual light signal during button presses.
* **1-Digit 7-Segment Display:** The "main character" of the project. It is strictly tied into the software logic to display the current character or count dynamically.

---

## 📂 Project Structure

This project is built using **PlatformIO** inside VS Code. Below is the organization of the main directory and files:

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

### 1. 7-Segment Display (Common Cathode)
*The upper middle pin (Pin 8) is left disconnected. The bottom middle pin (Pin 3) is connected to a current-limiting resistor, which hooks into the breadboard's GND rail via a jumper wire.*

| Segment | Arduino Pin | Display Pin | Description |
| :---: | :---: | :---: | --- |
| **A** | Pin 7 | Pin 7 | Upper horizontal bar |
| **B** | Pin 6 | Pin 6 | Top-right vertical bar |
| **C** | Pin 5 | Pin 4 | Bottom-right vertical bar |
| **D** | Pin 4 | Pin 2 | Bottom horizontal bar |
| **E** | Pin 3 | Pin 1 | Bottom-left vertical bar |
| **F** | Pin 2 | Pin 9 | Top-left vertical bar |
| **G** | Pin 8 | Pin 10 | Middle horizontal bar |
| **DP** | Pin 9 | Pin 5 | Decimal point (Bottom-right) |
| **GND** | GND | Pin 3 | Connected via resistor to Ground |

### 2. Peripheral Components
* **Input Button:** Connected to **Pin 12** on the Arduino, with the opposite terminal running a jumper wire directly to the negative (GND) rail.
* **Red LED Diode:** Connected to **Pin 13**. The shorter negative leg (Cathode) is wired through a protecting resistor straight into the negative (GND) rail.
* **Active Buzzer:** The positive terminal is hooked to **Pin 11**, while the negative terminal goes straight to the GND rail.
