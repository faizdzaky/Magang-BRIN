# 📈 Pembelajaran Pemrograman ADC (Analog-to-Digital Converter)

Folder ini berisi kumpulan kode program dan catatan eksperimen terkait penggunaan **ADC (Analog-to-Digital Converter)** pada mikrokontroler. Modul ini berfokus pada bagaimana mikrokontroler membaca sinyal analog dari dunia nyata dan mengonversinya menjadi nilai digital yang dapat diproses oleh algoritma.

## 💡 Konsep & Pembelajaran Utama dari Kode Program

Berikut adalah poin-poin pembelajaran utama yang dipelajari dari kodingan pada folder ini:

### 1. Pembacaan Tegangan Analog Sederhana

* **Fungsi Utama:** Menggunakan fungsi pembacaan analog (seperti `analogRead()`) untuk mengambil sampel data dari pin input analog (misalnya pin A0, A1, dll.).

* **Penerapan Komponen:** Membaca perubahan resistansi/tegangan dari komponen analog dasar seperti **potensiometer**, **sensor cahaya (LDR)**, atau **sensor suhu analog**.

### 2. Memahami Resolusi ADC & Kalkulasi Tegangan

* **Resolusi Bit:** Mempelajari hubungan antara resolusi bit ADC dengan rentang nilai digital yang dihasilkan:

  * ADC 10-bit (contoh: Arduino Uno): Rentang nilai $0 \text{ hingga } 1023$ ($2^{10} - 1$).

  * ADC 12-bit (contoh: ESP32 / STM32): Rentang nilai $0 \text{ hingga } 4095$ ($2^{12} - 1$).

* **Konversi ke Tegangan Fisik (**$V$**):** Menghitung nilai tegangan sebenarnya ($V_{\text{out}}$) menggunakan rumus kodingan:
  

  $$
  V_{\text{out}} = \left( \frac{\text{Nilai ADC}}{\text{Nilai Maksimum ADC}} \right) \times V_{\text{ref}}
  $$

### 3. Pemetaan Data (*Data Mapping*) & Scaling

* **Fungsi `map()`:** Mengubah rentang nilai raw ADC (misal: $0 - 1023$) menjadi rentang parameter lain yang relevan secara langsung, seperti:

  * Persentase ($0\% - 100\%$)

  * Sudut Motor Servo ($0^\circ - 180^\circ$)

  * Tingkat kecerahan LED PWM ($0 - 255$)

### 4. Teknik *Filtering* & Pengkondisian Sinyal (Noise Reduction)

* **Moving Average Filter:** Mengimplementasikan algoritma perataan (*averaging*) dari beberapa sampel pembacaan ADC berturut-turut untuk mengurangi *noise* (fluktuasi sinyal) yang sering terjadi pada pembacaan sensor analog.

* **Sampling Rate:** Memahami pengaruh waktu jeda pembacaan (*sampling time*) terhadap kestabilan data pembacaan sensor.

## 📂 Struktur File Kode dalam Folder

* `01_Basic_ADC_Read/` : Kode dasar pembacaan nilai raw ADC dari potensiometer dan menampilkan hasilnya di Serial Monitor.

* `02_ADC_to_Voltage/` : Program kalkulasi nilai ADC menjadi variabel tegangan ($V$) presisi.

* `03_ADC_Mapping_PWM/` : Mengontrol tingkat kecerahan LED menggunakan input analog via fungsi pemetaan (`map()`).

* `04_ADC_Filtering_Averaging/` : Implementasi algoritma perataan data (*smoothing/filtering*) untuk meredam *noise* pada sensor.

## 🛠️ Perangkat Hardware yang Digunakan

* Board Mikrokontroler (Arduino)

* Potensiometer 10k $\Omega$ / Sensor LDR

* Breadboard & Kabel Jumper