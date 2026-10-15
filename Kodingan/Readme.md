# Dokumentasi & Repositori Pembelajaran Pemrograman Embedded Systems

Folder ini berisi latihan dan kode program hasil pembelajaran mengenai pemrosesan sinyal digital, komunikasi mikrokarakter/mikroprosesor, serta pengontrolan I/O.

---

## 📁 Struktur dan Isi Folder

Berikut adalah penjelasan fungsi dan cakupan materi dari masing-masing folder di dalam repositori ini:

### 1. `01-Digital-Input-Output/`
Membahas konsep dasar pengoperasian pin I/O digital pada mikrokontroler.
* **Materi:** Konfigurasi mode pin (`INPUT`, `OUTPUT`, `PULLUP`/`PULLDOWN`), pembacaan sinyal diskrit (HIGH/LOW), dan manipulasi register I/O.

### 2. `02-LED-Control/`
Implementasi pengontrolan aktuator berupa LED berdasarkan pembacaan input digital maupun logika pemrosesan.
* **Materi:** Blinking LED, pola nyala terprogram, kontrol kecerahan menggunakan PWM (Pulse Width Modulation), dan teknik penghematan pin.

### 3. `03-ADC/` (Analog-to-Digital Converter)
Proses konversi sinyal analog berkelanjutan (kontinu) dari sensor menjadi data digital diskrit.
* **Materi:** Pembacaan tegangan analog, resolusi ADC, kalkulasi *mapping* nilai sensor, serta penggunaan sampel *sampling rate* dan *filtering* dasar.

### 4. `04-Blocking-vs-NonBlocking/`
Studi komparatif dan teknik manajemen waktu dalam eksekusi kode program (*timing control*).
* **Materi:** 
  * **Blocking:** Penggunaan fungsi tundaan (seperti `delay()`) yang menghentikan eksekusi baris kode berikutnya.
  * **Non-Blocking:** Implementasi *timer/millis()* dan *state machine* agar program tetap reponsif terhadap event/input lain tanpa *freezing*.

### 5. `05-Serial-Port/`
Komunikasi data berantai (*serial communication*) antara mikrokontroler dengan komputer (PC) atau antar peranti.
* **Materi:** Konfigurasi *baud rate*, pengiriman/penerimaan data via UART/USART, parsing string data, serta debugging *Real-time Serial Monitor*.

### 6. `06-OneWire-Protocol/`
Implementasi antarmuka bus komunikasi **One-Wire (1-Wire)** yang hanya menggunakan satu jalur data tunggal untuk komunikasi dengan beberapa sensor (misal: DS18B20).
* **Materi:** Pencarian alamat unik peranti (*ROM Search*), pengiriman perintah *read/write*, dan pembacaan temperatur/data sensor.

---

## 🛠️ Prasyarat & Perangkat yang Digunakan
* **Hardware:** Mikrokontroler (Arduino), LED, Resistor, Potensiometer/Sensor Analog, Sensor OneWire (DS18B20).
* **Software/IDE:** Arduino IDE / VS Code + PlatformIO.

## 🚀 Cara Menggunakan
1. Clone repositori ini ke komputer lokal kamu:
   ```bash
   git clone [https://github.com/faizdzaky/Magang-BRIN/tree/main/Kodingan](https://github.com/faizdzaky/Magang-BRIN/tree/main/Kodingan)