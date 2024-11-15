#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define CommonSenseMetricSystem
//#define ImperialNonsenseSystem

#define trigPin 13
#define echoPin 12
#define buzzerPin 15    // Buzzer connected to pin 15
#define OLED_RESET -1   // ESP32 usually does not use a reset pin for OLED
#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);  // Initialize buzzer pin as output

  // If you are using different I2C pins for ESP32, initialize them here
  Wire.begin(21, 22); // SDA = 21, SCL = 22 (Change if necessary)

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // initialize with the I2C addr 0x3C (128x64)
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();
}

void loop() {
  long duration, distance;

  // Generate ultrasonic pulse
  digitalWrite(trigPin, LOW);  // PULSE ___|---|___
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read pulse duration
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance based on defined system
  #ifdef CommonSenseMetricSystem
    distance = (duration / 2) / 29.1;  // cm
  #endif

  #ifdef ImperialNonsenseSystem
    distance = (duration / 2) / 73.914;  // inches
  #endif

  // Display distance on OLED
  display.clearDisplay();
  display.setCursor(22, 10);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.println(distance);

  // Display unit
  display.setCursor(55, 10);
  display.setTextSize(2);
  #ifdef CommonSenseMetricSystem
    display.println("cm");
  #endif
  #ifdef ImperialNonsenseSystem
    display.println("in");
  #endif

  display.display();

  // Use tone to represent the distance with sound frequency
  if (distance <= 50) {
    // Map the distance to a frequency range
    int frequency = map(distance, 0, 50, 1000, 200);  // Closer objects have a higher pitch, farther have lower
    tone(buzzerPin, frequency);  // Play sound with frequency based on distance
  } else {
    noTone(buzzerPin);  // Stop the buzzer if distance is greater than 50 cm
  }

  // Debugging on Serial Monitor
  Serial.println(distance);

  delay(500);  // Wait 500 ms before next reading
}
