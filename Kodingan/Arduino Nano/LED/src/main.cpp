#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int baundRate = 115200;          // Baud rate untuk komunikasi serial
const int lcdColumns = 16;             // Jumlah kolom pada LCD
const int lcdRows = 2;                 // Jumlah baris pada LCD
const int lcdAddress = 0x27;           // Alamat I2C untuk modul LCD (umumnya 0x27 atau 0x3F)
const int delayTimeSetUp = 1500;       // Waktu delay untuk pembacaan sensor (dalam milidetik)
const int delayTimeReset = 500;        // Waktu delay untuk pembacaan sensor (dalam milidetik)
const int kodeReset = 27;              // Kode ASCII untuk tombol ESC (reset)
const int kodeTombolReset = '*';       // Kode ASCII untuk tombol '*' (reset)
const int koordinatBaris1 = 0;         // Baris pertama pada LCD
const int koordinatBaris2 = 1;         // Baris kedua pada LCD
const int koordinatKolom1 = 0;         // Kolom pertama pada LCD
const int karakterMaksimal = 32;       // Jumlah karakter maksimal yang dapat ditampilkan pada LCD (16 karakter per baris x 2 baris)
const int karakterMaksimalBaris1 = 16; // Jumlah karakter maksimal per baris pada LCD
const int karakterawal = 0;            // Nilai awal counter

// Catatan Proteus: Jika pin A0, A1, A2 pada PCF8574 dihubungkan ke VCC, gunakan 0x27.
// Jika dihubungkan ke GND, ubah alamat menjadi 0x20.
LiquidCrystal_I2C lcd(lcdAddress, lcdColumns, lcdRows);

String inputBuffer = "";

void setup()
{
  Serial.begin(baundRate);

  Wire.begin();
  lcd.init();
  lcd.backlight();

  lcd.setCursor(koordinatKolom1, koordinatBaris1);
  lcd.print("Proteus Ready!");
  lcd.setCursor(koordinatKolom1, koordinatBaris2);
  lcd.print("Ketik di Term...");
  delay(delayTimeSetUp);
  lcd.clear();
}

void loop()
{
  while (Serial.available() > 0)
  {
    char c = Serial.read();

    // Jika menekan tombol ESC (kode ASCII 27) atau tombol '*'
    if (c == kodeReset || c == kodeTombolReset)
    {
      inputBuffer = "";
      lcd.clear();
      lcd.setCursor(koordinatKolom1, koordinatBaris1);
      lcd.print("Reset / Clear!");
      delay(delayTimeReset);
      lcd.clear();
    }
    else if (c == '\n' || c == '\r')
    {
      inputBuffer = "";
      lcd.clear();
    }
    else
    {
      inputBuffer += c;
      lcd.clear();

      // Jika teks <= 16 karakter, tampilkan di baris pertama
      if (inputBuffer.length() <= karakterMaksimalBaris1)
      {
        lcd.setCursor(koordinatKolom1, koordinatBaris1);
        lcd.print(inputBuffer);
      }
      // Jika teks > 16 karakter, teruskan ke baris kedua
      else
      {
        lcd.setCursor(koordinatKolom1, koordinatBaris1);
        lcd.print(inputBuffer.substring(karakterawal, karakterMaksimalBaris1));
        lcd.setCursor(koordinatKolom1, koordinatBaris2);
        lcd.print(inputBuffer.substring(karakterMaksimalBaris1, karakterMaksimal));
      }
      Serial.print("Input: ");
      Serial.println(inputBuffer);
    }
  }
}
