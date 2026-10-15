# ⏱️ Pembelajaran Pemrograman Blocking vs Non-Blocking

Folder ini berisi kumpulan kode program dan materi eksperimen mengenai **Manajemen Waktu (Timing Control)** serta teknik eksekusi program pada mikrokontroler. Fokus utama dari materi ini adalah memahami perbedaan antara pendekatan **Blocking** dan **Non-Blocking**, serta bagaimana dampaknya terhadap performa dan responsivitas sistem *embedded*.

## 💡 Konsep & Pembelajaran Utama dari Kode Program

Berikut adalah poin-poin pembelajaran utama yang dipelajari dari kodingan pada folder ini:

### 1. Eksekusi Kode Berbasis *Blocking* (Pendekatan Sederhana)

* **Penggunaan `delay()`:** Menggunakan fungsi penunda waktu seperti `delay()` atau `delayMicroseconds()`.

* **Karakteristik & Masalah:**

  * **Halt Processor:** Mikrokontroler dipaksa berhenti (*freeze*) dan tidak melakukan proses apa pun selama waktu penundaan berlangsung.

  * **Unresponsive System:** Sistem tidak dapat merespons *event* dari luar secara langsung, seperti pembacaan tombol, penerimaan data Serial, atau interupsi sensor.

* **Penggunaan yang Tepat:** Hanya ideal untuk program sederhana, indikator *startup*, atau pengujian *hardware* dasar.

### 2. Eksekusi Kode Berbasis *Non-Blocking* (Pendekatan Asinkron)

* **Penggunaan Timer / `millis()`:** Memanipulasi fungsi pewaktu sistem internal (`millis()` / `micros()`) untuk mencatat waktu berjalan tanpa menghentikan eksekusi kode.

* **Teknik *Polling* Waktu:** Menggunakan variabel pembanding (`previousMillis`) untuk mengecek apakah interval waktu tertentu sudah tercapai:

  $$
  \text{Waktu Sekarang} - \text{Waktu Sebelumnya} \ge \text{Interval}
  $$

* **Keunggulan:**

  * **Multi-tasking Simulasi:** Mikrokontroler dapat menjalankan beberapa tugas secara bersamaan (*concurrent/parallel behavior*), seperti mengedipkan LED sambil membaca tombol dan mengirimi data Serial.

  * **High Responsiveness:** Input dari pengguna atau sensor dapat langsung diproses tanpa menunggu *delay* selesai.

### 3. Penerapan *State Machine* Dasar (FSM)

* **Pola Perancangan Sistem:** Mengombinasikan logika *non-blocking* dengan *Finite State Machine* (FSM) menggunakan struktur `switch-case` atau `if-else`.

* **Transisi Kondisi:** Memungkinkan program berpindah dari satu kondisi (*state*) ke kondisi lain berdasarkan waktu atau event tertentu tanpa menggunakan fungsi pemblokir.

## 📂 Struktur File Kode dalam Folder

* `01_Blocking_Blink/` : Contoh program pembacaan tombol dan LED menggunakan `delay()`, menunjukkan keterlambatan respons sistem (*unresponsive bug*).

* `02_NonBlocking_Blink_Millis/` : Implementasi *Blink Without Delay* menggunakan fungsi `millis()`.

* `03_MultiTasking_Millis/` : Program mengendalikan beberapa LED dengan interval kedip berbeda secara independen serta tetap responsif membaca tombol.

* `04_State_Machine_NonBlocking/` : Pengorganisasian alur program kompleks menggunakan *State Machine* berbasis waktu *non-blocking*.

## 🛠️ Perangkat Hardware yang Digunakan

* Board Mikrokontroler (Arduino)

* Push Button / Switches

* 2x atau lebih LED & Resistor $220\,\Omega$

* Breadboard & Kabel Jumper