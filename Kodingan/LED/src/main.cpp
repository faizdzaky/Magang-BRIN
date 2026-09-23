#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Catatan Proteus: Jika pin A0, A1, A2 pada PCF8574 dihubungkan ke VCC, gunakan 0x27.
// Jika dihubungkan ke GND, ubah alamat menjadi 0x20.
LiquidCrystal_I2C lcd(0x27, 16, 2);

String inputBuffer = "";

void setup()
{
  Serial.begin(115200);

  Wire.begin();
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Proteus Ready!");
  lcd.setCursor(0, 1);
  lcd.print("Ketik di Term...");
  delay(1500);
  lcd.clear();
}

void loop()
{
  while (Serial.available() > 0)
  {
    char c = Serial.read();

    // Jika menekan tombol ESC (kode ASCII 27) atau tombol '*'
    if (c == 27 || c == '*')
    {
      inputBuffer = "";
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Reset / Clear!");
      delay(500);
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
      if (inputBuffer.length() <= 16)
      {
        lcd.setCursor(0, 0);
        lcd.print(inputBuffer);
      }
      // Jika teks > 16 karakter, teruskan ke baris kedua
      else
      {
        lcd.setCursor(0, 0);
        lcd.print(inputBuffer.substring(0, 16));
        lcd.setCursor(0, 1);
        lcd.print(inputBuffer.substring(16, 32));
      }
      Serial.print("Input: ");
      Serial.println(inputBuffer);
    }
  }
}
