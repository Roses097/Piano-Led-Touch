# 🎹 Piano LED Touch

Light up your piano keys in real time — each key you press triggers a matching LED on a WS2812B strip.

## ℹ️ Overview

Piano LED Touch is a project that visualizes piano playing using an MCU and a WS2812B LED strip. When you press a key on a keyboard, the corresponding LED lights up in a color based on the musical note. This is my first embedded project, built to learn MCU development and MIDI communication.

### ✍️ Authors

GitHub: [@Ray](https://github.com/Roses097)
GitHub: [@rei_ayanami01](https://discord.com/users/rei_ayanami01)

---
# 📋 Requirements

### Hardware
- Arduino or ESP board (UNO, ESP32S3 etc...)
- WS2812B LED strip (5V, 60 LEDs/meter, 1 meter)
- Piano keyboard (or any 61-key MIDI keyboard)
- 5V 3A power supply
- USB cable

### Software
- Arduino IDE
- Python 3
- [FastLED](https://github.com/FastLED/FastLED) Arduino library
- [MIDI Library](https://github.com/FortySevenEffects/arduino_midi_library) by FortySevenEffects
- Python packages: `mido`, `pyserial`

### System
- macOS (tested on macOS with Apple Silicon Tahoe)



# 🚀 Quickstart

### 1. Clone Repo
```bash
git clone https://github.com/Roses097/piano-led-touch.git

cd piano-led-touch
```

### 2. Download MIDI library

Open Arduino IDE, go in Library Manager, search MIDI Library. Install the library made by Francois Best.


![MIDI Library](piano_led/img/library-manager.png)

### 3. Flash the ESP32

Open `piano_led.ino` in Arduino IDE, select your board name and your port, then upload. Make sure to remember which port your MCU is connected on, you'll need it for later.


### 4. Install Python dependencies

```bash
pip install -r requirements.txt
```


### 5. Run the MIDI bridge

```bash
python3 midi_bridge.py
```

### 6. Play!

Press any key on your piano — the matching LED lights up instantly.

---------
# ⚙️ How it works


### Example 
```bash
Yamaha P-45B (61 keys)
        │
        │  USB MIDI
        ▼
      macOS
        │
        │  midi_bridge.py (mido + pyserial)
        ▼
     ESP32S3
        │
        │  GPIO 48 (Data signal)
        ▼
  WS2812B LED Strip
  (61 LEDs, one per key)
```

### Python bridge

The `midi_bridge.py` script reads MIDI from your piano and forwards it to the ESP32 over USB serial:

```python
import mido
import serial
```

### MCU code

The `MIDI.h` library makes the MCU understand the MIDI data sent from the device. It acts as a translator to convert raw serial bytes into readable function calls, allowing the MCU to know exactly which key was pressed, on which channel, and how hard.

```ino
  MIDI.setHandleNoteOn(onNoteOn);
  MIDI.setHandleNoteOff(onNoteOff);

  void onNoteOn(byte channel, byte note, byte velocity)
  void onNoteOff(byte channel, byte note, byte velocity)
```

---
# 🔮 Roadmap

- [X] Velocity-based brightness — harder keypress = brighter LED (already partially implemented)

- [X] Configurable color themes — change note colors via a config file

- [ ] PianoBooster integration — sync LEDs with sheet music to highlight upcoming notes

- [ ] Wireless connection via Bluetooth MIDI — no USB cable needed

- [ ] Web interface — control LED settings from a browser over WiFi


## 💭 Feedback and Contributing

Found a bug or have an idea? Open an issue or start a discussion in the [Discussions tab](../../discussions).  
Contributions are welcome — feel free to open a pull request!