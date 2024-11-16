# Distance Alert Sensor for Car Parking

This project implements a **distance alert sensor** using an ESP32, ultrasonic sensor, buzzer, and OLED display. The sensor measures the distance of objects using ultrasonic waves and provides both visual and audible feedback to assist in parking vehicles. 

---

## Features
1. **Ultrasonic Distance Measurement**:  
   Measures distance using the HC-SR04 ultrasonic sensor.
   
2. **OLED Display**:  
   Displays the measured distance in real-time.
   
3. **Audible Alerts**:  
   Buzzer emits variable tones based on object proximity.
   
4. **Configurable Measurement System**:  
   Supports metric (cm) and imperial (inches) units through preprocessor directives.

---

## Components
- **ESP32** (Development Board)  
- **HC-SR04** Ultrasonic Sensor  
- **OLED Display** (128x64, SSD1306)  
- **Buzzer**  
- Wires and Breadboard  

---

## Circuit Diagram
1. **Ultrasonic Sensor**:  
   - `VCC` → 5V  
   - `GND` → GND  
   - `Trig` → GPIO 13  
   - `Echo` → GPIO 12  

2. **OLED Display**:  
   - `SDA` → GPIO 21  
   - `SCL` → GPIO 22  
   - `VCC` → 3.3V  
   - `GND` → GND  

3. **Buzzer**:  
   - Positive → GPIO 15  
   - Negative → GND  

---

## Installation & Setup
1. **Clone Repository**:  
   Clone this repository or download the ZIP file and extract it.

2. **Install Required Libraries**:  
   Install the following libraries in the Arduino IDE:  
   - `Adafruit GFX Library`  
   - `Adafruit SSD1306`

   To install:
   - Go to **Sketch > Include Library > Manage Libraries**.  
   - Search for the library and click **Install**.

3. **Configure the Measurement System**:  
   - By default, the system uses the metric system.  
   - To use the imperial system, uncomment `#define ImperialNonsenseSystem` and comment `#define CommonSenseMetricSystem`.

4. **Upload the Code**:  
   - Connect your ESP32 to the computer via USB.  
   - Select the correct COM port and ESP32 board in Arduino IDE.  
   - Click **Upload** to flash the code.

---

## Usage
1. Power up the system with the ESP32.  
2. Place the ultrasonic sensor where it can measure distances (e.g., rear bumper of a car).  
3. The distance to the nearest object is displayed on the OLED screen in real time.  
4. The buzzer emits a sound that increases in pitch as the object gets closer (for distances ≤50 cm).

---

## How It Works
1. The **HC-SR04 Ultrasonic Sensor** emits a pulse and measures the time it takes for the echo to return.  
2. The ESP32 calculates the distance based on the pulse duration.  
3. The distance is displayed on the **OLED screen**, and the buzzer frequency varies with distance.  
   - **Closer objects**: Higher pitch.  
   - **Farther objects**: Lower pitch.  
   - **Beyond 50 cm**: Buzzer remains silent.

---

## Demo Video
[Add a link to your demo video once available]

---

## Future Enhancements
- Add support for multiple sensors for broader coverage.  
- Integrate with a mobile app for remote monitoring.  
- Include advanced alert levels using LEDs or vibration motors.

---

## License
This project is open-source and licensed under the [MIT License](https://opensource.org/licenses/MIT).

---

### Author
[Sangeeth Ananthanan](mailto:sangeethananthanan@gmail.com)
