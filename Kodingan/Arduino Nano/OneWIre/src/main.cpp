#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

const int baundRate = 115200;          // Baud rate untuk komunikasi serial
const int delayTime = 1000;            // Waktu delay untuk pembacaan sensor (dalam milidetik)

// Pin data DS18B20 dihubungkan ke Digital Pin D13 Arduino Nano
#define ONE_WIRE_BUS 13

// Inisialisasi OneWire dan DallasTemperature
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup()
{
  Serial.begin(baundRate);
  Serial.println("--- Inisialisasi Sensor DS18B20 ---");

  // Memulai komunikasi dengan sensor
  sensors.begin();
}

void loop()
{
  // Mengirim perintah untuk membaca suhu
  sensors.requestTemperatures();

  // Membaca suhu dalam Celsius
  float tempC = sensors.getTempCByIndex(0);

  // Memeriksa apakah sensor terhubung dengan benar (-127 berarti error/terputus)
  if (tempC == DEVICE_DISCONNECTED_C)
  {
    Serial.println("Error: Sensor DS18B20 tidak terdeteksi!");
  }
  else
  {
    Serial.print("Suhu: ");
    Serial.print(tempC);
    Serial.println(" °C");
  }

  delay(delayTime); // Pembacaan setiap 1 detik
}