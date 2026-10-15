# 🔄 Pembelajaran Pemrograman Protokol Komunikasi I2C (Inter-Integrated Circuit)

Folder ini berisi kumpulan kode program dan latihan mengenai penggunaan **Protokol Komunikasi I2C (Inter-Integrated Circuit /** $TWI$**)** pada sistem *embedded*. Fokus utama materi ini adalah memahami cara mengomunikasikan mikrokontroler dengan peranti periferal (seperti modul LCD 16x2 I2C Backpack, sensor, atau EEPROM) hanya menggunakan dua jalur komunikasi serial.

## 💡 Konsep & Pembelajaran Utama dari Kode Program

Berikut adalah poin-poin penting yang dipelajari melalui implementasi kode pada folder ini:

### 1. Arsitektur Dua Jalur Bus ($SDA$ & $SCL$)

* **Jalur Data & Clock:** Memahami fungsi pin $SDA$ **(Serial Data)** untuk transmisi data bit-demi-bit dan pin $SCL$ **(Serial Clock)** untuk sinkronisasi pewaktuan sinyal antara *Master* dan *Slave*.

* **Jaringan Multi-Device:** Mempelajari bagaimana protokol I2C memungkinkan banyak peranti periferal terhubung secara paralel pada jalur bus yang sama tanpa saling mengganggu.

### 2. Alamat Peranti (*I2C Slave Address*)

* **Prinsip Addressing 7-bit:** Memahami bagaimana mikrokontroler (*Master*) memanggil peranti (*Slave*) tertentu menggunakan alamat unik $7\text{-bit}$ (misalnya `0x27` atau `0x3F` untuk LCD 16x2).

* **I2C Address Scanner:** Membuat program pemindai alamat untuk melacak seluruh peranti I2C yang aktif dan terhubung pada bus secara otomatis.

### 3. Implementasi Display LCD 16x2 dengan Modul PCF8574 (I2C Backpack)

* **Efisiensi Pin Mikrokontroler:** Mengapresiasi pengurangan kebutuhan pin dari $6\text{--}8\text{ pin}$ (mode standar paralel) menjadi **hanya 2 pin data (**$SDA$**/**$SCL$**)** menggunakan IC *I/O Expander* PCF8574.

* **Inisialisasi & Pengontrolan Display:** Mempelajari perintah inisialisasi karakter LCD, pengaturan kursor (`setCursor`), pembersihan layar (`clear`), hingga pengontrolan *Backlight* (lampu latar) secara terprogram.

* **Formatting & Printing Data:** Menampilkan karakter teks *string*, nilai variabel angka/sensor, serta teks bergerak (*scrolling text*) pada baris dan kolom tertentu pada LCD 16x2.

### 4. Transmisi Data & Protokol Handshaking

* **Kondisi START, STOP, dan ACK/NACK:** Memahami mekanik sinyal saat transmisi data dimulai (*START condition*), dihentikan (*STOP condition*), serta konfirmasi penerimaan data (*Acknowledge bit*).

## 📂 Struktur File Kode dalam Folder

* `01_I2C_Address_Scanner/` : Program pemindai otomatis untuk menemukan alamat *Hexadecimal* (misal: `0x27`) dari modul I2C yang terpasang.

* `02_LCD1602_I2C_Basic/` : Program dasar untuk menampilkan teks, mengontrol kursor, dan menyalakan/mematikan lampu latar LCD 16x2 via I2C.

* `03_LCD1602_I2C_Dynamic_Data/` : Menampilkan data dinamis (seperti nilai pembacaan sensor atau pembacaan *counter*) secara *real-time* pada layar LCD 16x2.

## 🛠️ Perangkat Hardware & Component

* Mikrokontroler (Arduino)

* Modul Display LCD 16x2 + **I2C Backpack Adapter (PCF8574)**

* Resistor *Pull-Up* (jika menggunakan mikrokontroler/board tanpa internal pull-up)

* Breadboard & Kabel Jumper (pin $SDA$, $SCL$, $VCC$, $GND$)