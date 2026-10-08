#include <Arduino.h>

// Onboard LED on most ESP32 DevKit boards is on GPIO 2
#ifndef LED_BUILTIN
#define LED_BUILTIN 2
#endif

const int LED = LED_BUILTIN;

void blink(int onMs, int offMs) {
  digitalWrite(LED, HIGH);
  delay(onMs);
  digitalWrite(LED, LOW);
  delay(offMs);
}

// Pattern 1: 3 quick blinks
void quickBlinks() {
  for (int i = 0; i < 3; i++) blink(100, 100);
}

// Pattern 2: heartbeat (double pulse)
void heartbeat() {
  blink(80, 120);
  blink(80, 600);
}

// Pattern 3: SOS in Morse ( ... --- ... )
void sos() {
  for (int i = 0; i < 3; i++) blink(150, 150);   // S
  delay(200);
  for (int i = 0; i < 3; i++) blink(450, 150);   // O
  delay(200);
  for (int i = 0; i < 3; i++) blink(150, 150);   // S
}

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  delay(500);
  Serial.println("Desk Buddy: LED test starting");
}

void loop() {
  Serial.println("Pattern: quick blinks");
  quickBlinks();
  delay(800);

  Serial.println("Pattern: heartbeat");
  for (int i = 0; i < 3; i++) heartbeat();
  delay(800);

  Serial.println("Pattern: SOS");
  sos();
  delay(1500);
}
