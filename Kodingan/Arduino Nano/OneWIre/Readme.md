# 🔌 Pembelajaran Pemrograman Protokol OneWire

Folder ini berisi kumpulan kode program dan latihan mengenai penggunaan **Protokol Komunikasi OneWire (1-Wire)** pada sistem *embedded*. Fokus utama dari materi ini adalah memahami cara mengomunikasikan mikrokontroler dengan peranti/sensor (seperti sensor suhu DS18B20) hanya menggunakan **satu jalur data tunggal** (+ jalur VCC dan GND).

## 💡 Konsep & Pembelajaran Utama dari Kode Program

Berikut adalah poin-poin penting yang dipelajari melalui implementasi kode pada folder ini:

### 1. Arsitektur Bus & Jalur Komunikasi Single-Pin

* **Penggunaan Resistor Pull-Up:** Memahami mengapa jalur data OneWire membutuhkan resistor *pull-up* eksternal (umumnya $4.7\text{ k}\Omega$) untuk menjaga sinyal dalam kondisi `HIGH` saat *bus* dalam keadaan *idle*.

* **Komunikasi Master-Slave:** Memahami bagaimana mikrokontroler bertindak sebagai *Master* yang mengendalikan seluruh lalu lintas data, sementara sensor bertindak sebagai *Slave*.

### 2. Identifikasi Alamat Unik Peranti (ROM Address / 64-bit Address)

* **Pencarian Alamat Hardware (*ROM Search*):** Menerapkan algoritma pencarian untuk menemukan alamat unik 64-bit yang dimiliki oleh setiap sensor OneWire.

* **Multi-Drop Bus Topology:** Memahami keunggulan OneWire yang mampu menghubungkan banyak sensor sekaligus pada **satu pin data yang sama** dengan memanfaatkan identifikasi alamat unik masing-masing sensor.

### 3. Protokol & Timing Transmisi Data

* **Sinyal Reset dan Presence Pulse:** Mempelajari tahap inisialisasi di mana *Master* mengirim sinyal *reset* dan *Slave* merespons dengan sinyal *presence* untuk mengonfirmasi bahwa peranti siap berkomunikasi.

* **Proses *Read/Write* berbasis Slot Waktu (*Time Slots*):** Memahami bagaimana bit $0$ dan $1$ dikirim dan dibaca melalui manipulasi durasi pulsa `LOW` dan `HIGH` dalam skala mikrodetik ($\mu\text{s}$).

### 4. Ekstraksi & Transforamasi Data Sensor (DS18B20)

* **Pengiriman Perintah Komando:** Mempelajari alur perintah seperti `0x44` (Convert T) untuk memulai konversi suhu, dan `0xBE` (Read Scratchpad) untuk membaca byte data hasil pengukuran.

* **Konversi Raw Data ke Nilai Fisik:** Mengolah data mentah (*raw bytes*) $12\text{-bit}$ dari registers *scratchpad* menjadi nilai suhu berformat Celcius ($^\circ\text{C}$) atau Fahrenheit ($^\circ\text{F}$).

## 📂 Struktur File Kode dalam Folder

* `01_OneWire_Address_Scanner/` : Program *scanner* untuk mendeteksi dan menampilkan alamat unik 64-bit dari peranti OneWire yang terhubung.

* `02_DS18B20_Single_Sensor/` : Pengukuran suhu menggunakan satu sensor DS18B20 pada bus OneWire.

* `03_DS18B20_Multiple_Sensors/` : Pembacaan data dari beberapa sensor DS18B20 sekaligus yang terhubung secara paralel pada satu pin data.

## 🛠️ Perangkat Hardware & Component

* Mikrokontroler (Arduino)

* Sensor Suhu OneWire (misal: **DS18B20**)

* Resistor $4.7\text{ k}\Omega$ (sebagai *pull-up resistor*)

* Breadboard & Kabel Jumper