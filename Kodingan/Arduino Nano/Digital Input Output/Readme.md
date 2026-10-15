# 🔘 Pembelajaran Pemrograman Digital Input / Output (GPIO)

Folder ini berisi kumpulan kode program dan latihan mengenai dasar pengoperasian pin **GPIO (General Purpose Input/Output)** pada mikrokontroler. Modul ini merupakan fondasi paling dasar namun krusial dalam dunia *embedded systems* untuk berinteraksi dengan peranti eksternal secara digital.

---

## 💡 Konsep & Pembelajaran Utama dari Kode Program

Melalui kodingan di dalam folder ini, kamu akan mempelajari konsep-konsep berikut:

### 1. Konfigurasi Mode Pin (`Pin Direction`)
* **Output Mode (`OUTPUT`):** Mengatur pin agar dapat mendrive sinyal tegangan keluar untuk mengendalikan beban/aktuator diskrit (seperti LED, Relay, atau Buzzer).
* **Input Mode (`INPUT`):** Mengatur pin sebagai penerima sinyal digital eksternal (HIGH/LOW) dari peranti input seperti Saklar (Push Button), Sensor Proximity digital, atau sensor PIR.

### 2. Konfigurasi Resistor Internal (`PULL-UP` / `PULL-DOWN`)
* **State Floating:** Memahami bahaya pin input yang mengambang (*floating state*) yang dapat menyebabkan pembacaan acak akibat *noise* elektromagnetik.
* **Internal Pull-Up (`INPUT_PULLUP`):** Mengaktifkan resistor penarik logika ke posisi $HIGH$ secara internal pada mikrokontroler, sehingga tombol hanya perlu dihubungkan ke $GND$ (logika aktif rendah / *active-low*).
* **Pull-Down External/Internal:** Mengatur kondisi pin tetap berada di logika $LOW$ hingga tombol ditekan untuk mengalirkan tegangan $VCC$ (logika aktif tinggi / *active-high*).

### 3. Logika Pembacaan & Penulisan Sinyal Diskrit
* **Digital Write (`digitalWrite`):** Mengubah status tegangan pin output antara $HIGH$ (biasanya $3.3\text{V}$ atau $5\text{V}$) dan $LOW$ ($0\text{V}$).
* **Digital Read (`digitalRead`):** Membaca status level logika pada pin input untuk mendeteksi apakah sinyal berada pada ambang batas $HIGH$ atau $LOW$.

### 4. Teknik Debouncing Saklar Mekanis (*Debouncing*)
* **Masalah Bounce:** Memahami efek pantulan mekanis (*contact bounce*) saat saklar ditekan yang dapat terbaca sebagai penekanan berulang dalam milidetik.
* **Software Debouncing:** Mengimplementasikan algoritma tundaan (*delay*) atau pengecekan pewaktuan berbasis `millis()` untuk menyaring sinyal palsu agar pembacaan input stabil dan akurat.

---

## 📂 Struktur File Kode dalam Folder

* `01_Digital_Output_Basic/` : Program dasar mengontrol status logika pin output secara langsung.
* `02_Digital_Input_Direct/` : Pembacaan status tombol (*push button*) secara langsung untuk menyalakan/mematikan output.
* `03_Input_PullUp_Internal/` : Implementasi pembacaan tombol menggunakan fitur *internal pull-up resistor*.
* `04_Button_Debouncing/` : Algoritma *software debouncing* untuk memastikan pembacaan saklar mekanis tidak memicu kalkulasi ganda.

---

## 🛠️ Perangkat Hardware & Komponen yang Digunakan

* Mikrokontroler (Arduino)
* Push Button / Saklar Mekanis
* Resistor $10\text{ k}\Omega$ (untuk konfigurasi *pull-up/pull-down* eksternal)
* LED / Indicator LED
* Breadboard & Kabel Jumper