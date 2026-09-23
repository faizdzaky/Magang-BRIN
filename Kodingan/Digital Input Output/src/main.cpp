#include <Arduino.h>

const int segPins[7] = {2, 3, 4, 5, 6, 7, 8};
const int buttonPin = 10; // Tombol hitung
const int LED_PIN = 11; // Pin LED internal untuk indikasi status

// Pola angka standar (1 = segmen aktif, 0 = segmen mati)
const byte numPatterns[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

int counter = 0;

// Variabel Debounce Tombol
unsigned long lastDebounceTime = 0;
const long debounceDelay = 50;   // Waktu filter getaran tombol (50 ms)

int lastButtonState = LOW;
int stableButtonState = LOW;

void displayDigitCA(int digit) {
  for (int i = 0; i < 7; i++) {
    // Logika Common Anode: Inversi nilai (1 -> LOW / Menyala, 0 -> HIGH / Mati)
    digitalWrite(segPins[i], numPatterns[digit][i] ? HIGH : LOW);
  }
}

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segPins[i], OUTPUT);
  }
  pinMode(buttonPin, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
 
  // Debounce Tombol Hitung
  int currentReadingButton = digitalRead(buttonPin);

  if (currentReadingButton != lastButtonState) {
    lastDebounceTime = millis(); // Reset timer debounce jika status pin berubah
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // Sinyal dianggap stabil setelah melewati durasi debounce
    if (currentReadingButton != stableButtonState) {
      stableButtonState = currentReadingButton;

      // 2. Timer Hitungan 1 Detik (Non-blocking)
       if (stableButtonState == LOW) {
       // Tombol hitung ditekan: Tambahkan hitungan
       counter++;
        if (counter > 9) counter = 0;
         digitalWrite(LED_PIN, HIGH); // Nyalakan LED untuk menunjukkan penambahan
        } else {
         digitalWrite(LED_PIN, LOW); // Matikan LED jika tombol hitung tidak ditekan
        }
      // 3. Perbarui Tampilan 7-Segment 
        displayDigitCA(counter);
    }
  }
  lastButtonState = currentReadingButton;
}
