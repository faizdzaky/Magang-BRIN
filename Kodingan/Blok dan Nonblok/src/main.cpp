#include <Arduino.h>

// Deklarasi Pin Lampu
const int LED2_PIN = 2;
const int LED3_PIN = 3;
const int LED4_PIN = 4;

// Durasi Lampu 2 (dalam milidetik)
const long LED2_ON_TIME = 3000;  // Hidup 3 detik
const long LED2_OFF_TIME = 1000; // Mati 1 detik

// Durasi Lampu 3 (dalam milidetik)
const long LED3_ON_TIME = 2000;  // Hidup 2 detik
const long LED3_OFF_TIME = 3000; // Mati 3 detik

// Durasi Lampu 4 (dalam milidetik)
const long LED4_ON_TIME = 1000;  // Hidup 1 detik
const long LED4_OFF_TIME = 2000; // Mati 2 detik

// Catatan waktu terakhir
unsigned long previousMillisLED2 = 0;
unsigned long previousMillisLED3 = 0;
unsigned long previousMillisLED4 = 0;

// Status Awal LED
int led2State = LOW;
int led3State = LOW;
int led4State = LOW;

void setup()
{
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  pinMode(LED4_PIN, OUTPUT);
}

void loop()
{
  unsigned long currentMillis = millis();

  // ==========================================
  // KONTROL LAMPU 2
  // ==========================================
  long currentIntervalLED2;
  if (led2State == HIGH)
  {
    currentIntervalLED2 = LED2_ON_TIME; // Tahan selama waktu ON
  }
  else
  {
    currentIntervalLED2 = LED2_OFF_TIME; // Tahan selama waktu OFF
  }

  // Periksa apakah waktu tahan sudah terpenuhi
  if (currentMillis - previousMillisLED2 >= currentIntervalLED2)
  {
    previousMillisLED2 = currentMillis; // Simpan waktu saat ini
    led2State = !led2State;             // Balikkan status (HIGH <-> LOW)
    digitalWrite(LED2_PIN, led2State);
  }

  // ==========================================
  // KONTROL LAMPU 3
  // ==========================================
  long currentIntervalLED3;
  if (led3State == HIGH)
  {
    currentIntervalLED3 = LED3_ON_TIME; // Tahan selama waktu ON
  }
  else
  {
    currentIntervalLED3 = LED3_OFF_TIME; // Tahan selama waktu OFF
  }

  // Periksa apakah waktu tahan sudah terpenuhi
  if (currentMillis - previousMillisLED3 >= currentIntervalLED3)
  {
    previousMillisLED3 = currentMillis; // Simpan waktu saat ini
    led3State = !led3State;             // Balikkan status (HIGH <-> LOW)
    digitalWrite(LED3_PIN, led3State);
  }

  // ==========================================
  // KONTROL LAMPU 4
  // ==========================================
  long currentIntervalLED4;
  if (led4State == HIGH)
  {
    currentIntervalLED4 = LED4_ON_TIME; // Tahan selama waktu ON
  }
  else
  {
    currentIntervalLED4 = LED4_OFF_TIME; // Tahan selama waktu OFF
  }

  // Periksa apakah waktu tahan sudah terpenuhi
  if (currentMillis - previousMillisLED4 >= currentIntervalLED4)
  {
    previousMillisLED4 = currentMillis; // Simpan waktu saat ini
    led4State = !led4State;             // Balikkan status (HIGH <-> LOW)
    digitalWrite(LED4_PIN, led4State);
  }
}
