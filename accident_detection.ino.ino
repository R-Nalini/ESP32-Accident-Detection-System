#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

// Pin definitions
#define LED_PIN     26
#define BUZZER_PIN  27

// Threshold (adjust if needed)
#define ACCIDENT_THRESHOLD 2.5   // in 'g'

// Alert time
#define ALERT_DURATION 20000     // 20 seconds

bool accidentDetected = false;
unsigned long accidentTime = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin(21, 22);   // SDA, SCL for ESP32

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  Serial.println("Initializing MPU6050...");
  mpu.initialize();

  if (!mpu.testConnection()) {
    Serial.println("MPU6050 connection failed!");
    while (1);
  }

  Serial.println("MPU6050 ready");
}

void loop() {
  int16_t ax, ay, az;
  mpu.getAcceleration(&ax, &ay, &az);

  // Convert to g
  float Ax = ax / 16384.0;
  float Ay = ay / 16384.0;
  float Az = az / 16384.0;

  // Resultant acceleration
  float A = sqrt(Ax * Ax + Ay * Ay + Az * Az);

  Serial.print("Acceleration: ");
  Serial.println(A);

  // Accident detection
  if (A > ACCIDENT_THRESHOLD && !accidentDetected) {
    accidentDetected = true;
    accidentTime = millis();

    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);

    Serial.println("⚠️ Accident Detected!");
  }

  // Auto reset after delay
  if (accidentDetected && millis() - accidentTime > ALERT_DURATION) {
    accidentDetected = false;

    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);

    Serial.println("Alert reset");
  }

  delay(200);
}