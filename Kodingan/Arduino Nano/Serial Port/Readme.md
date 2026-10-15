# 📡 Pembelajaran Pemrograman Serial Port (UART/USART)

Folder ini berisi kumpulan kode program dan materi eksperimen mengenai **Komunikasi Serial Port** pada sistem *embedded*. Fokus utama dari materi ini adalah memahami cara mengalirkan data antara mikrokontroler dengan perangkat lain (seperti Komputer/PC, modul Bluetooth, GPS, atau sesama mikrokontroler) secara *real-time*.

## 💡 Konsep & Pembelajaran Utama dari Kode Program

Berikut adalah poin-poin pembelajaran utama yang dipelajari dari kodingan pada folder ini:

### 1. Inisialisasi & Konfigurasi Serial

* **Pengaturan *Baud Rate*:** Memahami pentingnya menyamakan kecepatan transmisi data (misalnya $9600$, $115200$ bps) antara pengirim (*transmitter*) dan penerima (*receiver*).

* **Manajemen Alokasi Buffer:** Memahami bagaimana data Serial disimpan sementara di dalam *hardware/software buffer* sebelum diproses oleh CPU.

### 2. Pengiriman Data (*Data Transmit / TX*)

* **Metode `print()` vs `write()`:**

  * `print()` / `println()`: Mengirim data dalam bentuk karakter/teks ASCII yang mudah dibaca oleh manusia (*human-readable format*).

  * `write()`: Mengirim data mentah dalam bentuk biner/byte (*raw binary format*) untuk efisiensi komunikasi antar perangkat.

* **Formating & Debugging:** Mengirim nilai sensor, pesan *log*, dan format tabel untuk keperluan *monitoring* melalui Serial Monitor atau Serial Plotter.

### 3. Penerapan Penerimaan Data (*Data Receive / RX*)

* **Pengecekan Ketersediaan Data (`Serial.available()`):** Memeriksa ketersediaan byte data masuk di buffer sebelum melakukan pembacaan untuk mencegah program *stuck* atau membaca data kosong.

* **Mekanisme Parsing Data:**

  * Pembacaan karakter tunggal (`Serial.read()`).

  * Pembacaan berbasis batas baris/delimiter (`Serial.readStringUntil('\n')`).

  * Ekstraksi angka dari string teks (`Serial.parseInt()`, `Serial.parseFloat()`).

### 4. Kontrol Kontrol Aktuator via Serial Command

* **Interaktivitas Sistem:** Mengontrol perangkat keras (seperti menyalakan LED, mengatur kecepatan motor, atau mengubah *mode* kerja) berdasarkan perintah/perintah teks yang dikirim pengguna melalui Serial Monitor.

## 📂 Struktur File Kode dalam Folder

* `01_Serial_Hello_World/` : Inisialisasi dasar komunikasi Serial dan pengiriman pesan sederhana.

* `02_Serial_Read_Command/` : Pembacaan perintah dari Serial Monitor untuk mengendalikan LED (contoh: kirim `"ON"` atau `"OFF"`).

* `03_Serial_Parsing_Numbers/` : Pembacaan dan pemrosesan data angka (seperti nilai PWM) dari Serial.

* `04_Serial_Plotter_Graph/` : Pengiriman data sensor secara kontinu agar dapat ditayangkan dalam bentuk grafik di Serial Plotter.

## 🛠️ Perangkat Hardware & Tools yang Digunakan

* Board Mikrokontroler (Arduino2)

* Kabel Data USB

* Software Serial Monitor / Serial Plotter (Arduino IDE / Platform IO)