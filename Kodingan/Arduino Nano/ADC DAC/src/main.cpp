#include <Arduino.h>

// Menentukan pin analog tempat pembagi tegangan LDR terhubung
const int ldrPin = A0;
const int delayTime = 1000;     // Waktu delay untuk pembacaan sensor (dalam milidetik)
const int batasan_akhir = 700;  // Batasan akhir untuk kondisi terang
const int batasan_tengah = 300; // Batasan tengah untuk kondisi redup
const int baundRate = 115200;   // Baud rate untuk komunikasi serial
const int persenMaks = 100;     // Nilai maksimum untuk persentase
const int persenMin = 0;        // Nilai minimum untuk persentase
const int ldrValueMax = 1023;   // Nilai maksimum dari pembacaan analog
const int ldrValueMin = 0;      // Nilai minimum dari pembacaan analog

void setup()
{
  Serial.begin(baundRate);
  Serial.println("--- Inisialisasi Sensor Cahaya (LDR) ---");
  delay(delayTime); // Memberikan waktu untuk inisialisasi
}

void loop()
{
  // Membaca nilai analog dari sensor LDR (rentang 0 - 1023)
  int ldrValue = analogRead(ldrPin);

  // Menampilkan nilai mentah ke Serial Monitor
  Serial.print("Nilai LDR (Analog): ");
  Serial.println(ldrValue);

  // Contoh logika sederhana berdasarkan intensitas cahaya
  // Nilai threshold dapat disesuaikan dengan kondisi ruangan Anda
  if (ldrValue > batasan_akhir)
  {
    Serial.println("Kondisi: Ruangan Terang / Siang Hari");
    Serial.println("Persen: " + String(map(ldrValue, ldrValueMin, ldrValueMax, persenMin, persenMaks)) + "%");
  }
  else if (ldrValue > batasan_tengah)
  {
    Serial.println("Kondisi: Cahaya Redup / Sore Hari");
    Serial.println("Persen: " + String(map(ldrValue, ldrValueMin, ldrValueMax, persenMin, persenMaks)) + "%");
  }
  else
  {
    Serial.println("Kondisi: Gelap / Malam Hari");
    Serial.println("Persen: " + String(map(ldrValue, ldrValueMin, ldrValueMax, persenMin, persenMaks)) + "%");
  }

  delay(delayTime); // Jeda pembacaan setiap 1 detik
}