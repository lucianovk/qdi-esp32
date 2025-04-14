# qdi-esp32 – Simple Web Interface for ESP32 Prototypes

**qdi-esp32** is a minimal yet functional template project designed to help you quickly build and test web-based interfaces on ESP32 boards. Ideal for prototyping and educational projects, it serves a static web UI from the ESP32 itself, with no external JavaScript libraries required.

---

## ✨ Features

- **Built-in Web Interface**: Serves HTML, CSS, and JS files directly from the ESP32 using SPIFFS.
- **Self-Contained**: No need for external JS frameworks or CDN dependencies.
- **Access Point Mode**: Creates its own Wi-Fi network so clients can connect directly to the ESP32.
- **Plug-and-Play**: Ready-to-use with minimal setup, perfect for fast prototyping or demonstrations.

---

## 🚀 Getting Started

1. **Install Tools**:
   - [Visual Studio Code](https://code.visualstudio.com/)
   - [PlatformIO IDE extension](https://platformio.org/install)

2. **Clone the Repository**:
    
    ````bash
    git clone https://github.com/lucianovk/qdi-esp32.git
    ````

3. **Open the Project in VSCode**

4. **Select Your Board** in PlatformIO under `PIO Home → Projects & Configuration`.

5. **Upload the Web Files and Firmware**:
   - Build File System Image
   - Upload File System Image
   - Build firmware
   - Upload firmware

6. **Connect to the ESP32 Wi-Fi**:
   - SSID: `qdi-esp32`
   - Password: `12345678`

7. **Access the Web Interface**:
   - Open your browser and go to [http://192.168.4.1](http://192.168.4.1)

---

## 🖼️ UI Preview

Below is a screenshot of the web interface served by the ESP32:

![Web UI Screenshot](qdi-screenshot.png)

---

## 📁 Project Structure

- `src/`: Main ESP32 application code
- `data/`: Static website (HTML, CSS, JS) to be served from SPIFFS
- `platformio.ini`: PlatformIO build configuration
- `qdi-screenshot.png`: UI preview image

---

## 📜 License

This project is released under the [Creative Commons Zero v1.0 Universal license (CC0-1.0)](LICENSE), placing it in the public domain.
