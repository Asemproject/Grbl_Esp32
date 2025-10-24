
---
🧭 Grbl_ESP32 for WeMos D1 R32 + CNC Shield V3 (Protoneer)
---

Overview

WEMOS_ESP32_PROTONEER.V3_CNC adalah firmware CNC berbasis Grbl_ESP32 yang telah dikonfigurasi khusus untuk:

Board: WeMos D1 R32 (ESP32)

Shield: Protoneer CNC Shield V3 (Arduino Uno-compatible pinout)


Firmware ini membawa fitur dan keunggulan Grbl klasik dengan kemampuan tambahan dari ESP32 seperti WiFi, WebUI, dan kontrol motor yang lebih cepat dan presisi.

⚙️ Hardware Setup

Komponen	Spesifikasi

MCU Board	WeMos D1 R32 (ESP32, pinout kompatibel Arduino Uno)
CNC Shield	Protoneer CNC Shield V3
Driver Stepper	A4988 / DRV8825 / TMC2209 / TMC2130
Limit Switch	X, Y, Z endstops (Normally Open / Closed)
Spindle / Laser	PWM controlled, relay, atau MOSFET
Power	12V – 24V DC



---

🧩 Pin Mapping (Default Configuration)

Axis	STEP	DIR	Limit	RMT Channel

X	GPIO 26	GPIO 16	GPIO 13	0
Y	GPIO 25	GPIO 27	GPIO 5	1
Z	GPIO 17	GPIO 14	GPIO 23	2


Fungsi	Pin ESP32	Keterangan

Enable Motor	GPIO 12	STEP ENABLE (aktif LOW)
Probe Input	GPIO 39	Z-Probe
Spindle Enable	GPIO 19	PWM / Relay
Spindle Direction	GPIO 18	Arah putaran
Feed Hold	GPIO 4	Tombol Jeda
Reset	GPIO 2	Tombol Reset



---

🛠 Default Configuration

Parameter	Nilai Awal

Homing Enable ($22)	1 (aktif)
Hard Limits ($21)	0
Soft Limits ($20)	1
Max Travel X/Y/Z	1000 / 500 / 100 mm
Steps per mm	200.0
Max Rate	X/Y = 1500 mm/min, Z = 600 mm/min
Acceleration	X/Y = 30 mm/s², Z = 15 mm/s²


> 💡 Disarankan menyesuaikan $130, $131, $132 dengan ukuran meja mesin nyata.
Misal: $130=995, $131=495, $132=100.




---

🌐 Connectivity Features

WiFi Mode

Access Point dan Client Mode didukung.

WebUI bawaan untuk kontrol CNC melalui browser tanpa aplikasi tambahan.


Bluetooth Serial

Menghubungkan ke aplikasi sender via Bluetooth (misal LaserGRBL Mobile, ESP3D, dsb).


USB Serial

Kompatibel dengan G-code sender seperti Candle, UGS, LaserGRBL, dll.





🚀 Kompilasi dan Upload Firmware

---

1. Instal PlatformIO

pip install platformio


2. Build Firmware

pio run


3. Upload ke Board

pio run -t upload

---

Atau jika menggunakan Arduino IDE:

Pilih board: ESP32 Dev Module

Upload file .ino utama Grbl_ESP32



---

📦 Direktori Konfigurasi

File utama yang digunakan:

/src/Machines/wemos_protoneer_v3.h

---

🧠 Catatan Tambahan

Firmware ini turunan dari Grbl_ESP32 dan masih kompatibel penuh dengan FluidNC.

Semua pengembangan baru akan diarahkan ke FluidNC, tapi Grbl_ESP32 tetap bisa digunakan untuk setup ringan seperti laser engraver, plotter, dan mini CNC.



---

🌟 Credits

Original GRBL: Sonny Jeon

Grbl_ESP32 Port: Bart Dring

Konfigurasi Wemos + Protoneer CNC V3: AsemProject

---
