#include <Arduino.h>
#include <SoftwareSerial.h>

const int baundRateHardware = 115200;          // Baud rate untuk komunikasi serial
const int baundRateSoftware = 9600;            // Baud rate untuk komunikasi serial software

// Definisi pin SoftwareSerial: Pin D2 sebagai RX, Pin D3 sebagai TX
const byte RX_PIN = 2;
const byte TX_PIN = 3;

// Inisialisasi objek SoftwareSerial
SoftwareSerial mySerial(RX_PIN, TX_PIN);

unsigned long previousMillis = 0;
const long interval = 2000; // Interval pengiriman data (2 detik)
int dataCounter = 0;

void setup() {
  // 1. Hardware Serial (Komunikasi ke PC via USB)
  Serial.begin(baundRateHardware);

  // 2. SoftwareSerial (Komunikasi ke modul eksternal via Pin D2 & D3)
  mySerial.begin(baundRateSoftware);

  Serial.println("=== Sistem Siap ===");
  Serial.println("Pengujian: Kirim data ke PC & SoftwareSerial");
}

void loop() {
  unsigned long currentMillis = millis();

  // Task 1: Kirim data rutin ke PC dan SoftwareSerial setiap 2 detik
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    dataCounter++;

    // Kirim data ke PC via Hardware Serial (USB)
    Serial.print("[PC Monitor] Mengirim data counter: ");
    Serial.println(dataCounter);
  }

  // Task 2: Baca data yang masuk dari SoftwareSerial (Pin D2 / RX) -> Tampilkan di PC
  if (mySerial.available() > 0) {
    char inByte = mySerial.read();
    Serial.print("[Diterima via SoftwareSerial]: ");
    Serial.print(inByte);
  }

  // Task 3: Ketikan dari Serial Monitor PC (USB) -> Teruskan ke SoftwareSerial (TX)
  if (Serial.available() > 0) {
    char outByte = Serial.read();
    mySerial.print(outByte);
  }
}