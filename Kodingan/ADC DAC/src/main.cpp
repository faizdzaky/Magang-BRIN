#include <Arduino.h>

// Menentukan pin analog tempat pembagi tegangan LDR terhubung
const int ldrPin = A0; 

void setup() {
  Serial.begin(115200);
  Serial.println("--- Inisialisasi Sensor Cahaya (LDR) ---");
  delay(1000);
}

void loop() {
  // Membaca nilai analog dari sensor LDR (rentang 0 - 1023)
  int ldrValue = analogRead(ldrPin);

  // Menampilkan nilai mentah ke Serial Monitor
  Serial.print("Nilai LDR (Analog): ");
  Serial.println(ldrValue);

  // Contoh logika sederhana berdasarkan intensitas cahaya
  // Nilai threshold dapat disesuaikan dengan kondisi ruangan Anda
  if (ldrValue > 700) {
    Serial.println("Kondisi: Ruangan Terang / Siang Hari");
    Serial.println("Persen: " + String(map(ldrValue, 0, 1023, 0, 100)) + "%");
  } else if (ldrValue > 300) {
    Serial.println("Kondisi: Cahaya Redup / Sore Hari");
    Serial.println("Persen: " + String(map(ldrValue, 0, 1023, 0, 100)) + "%");
  } else {
    Serial.println("Kondisi: Gelap / Malam Hari");
    Serial.println("Persen: " + String(map(ldrValue, 0, 1023, 0, 100)) + "%");
  }

  delay(1000); // Jeda pembacaan setiap 1 detik
}