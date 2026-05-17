#include <MIDI.h>
#include <FastLED.h>
#include "colors.h"

// #define display_oled  // remove comment to enable screen

#ifdef display_oled
  #include "display_oled.h"
  String currentNote = "";
  String lastNote = "";
#endif


/* The values below are adjustable depending on your Keyboard*/
#define LED_PIN     8  // Adjustable ---  Choose the pin you would like
#define NUM_LEDS    88  // Adjustable ---  Number of keys on a Yamaha p145b
#define FIRST_NOTE  21  // Adjustable ---  C1 (First key of 88 keyboard)


CRGB leds[NUM_LEDS];

//MIDI_CREATE_INSTANCE(HWCDC, Serial, MIDI);
MIDI_CREATE_INSTANCE(HardwareSerial, Serial, MIDI);

void setup() {

  Serial.begin(115200);
  delay(100);
  
  #ifdef display_oled
    showBoot();
  #endif

//You can request panel color in the github repo or add it yourself in the colorsNote.h 

  setColorTheme1(); //change this to choose your color palette ! (read the)

  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(150);
  FastLED.clear();
  FastLED.show();

  MIDI.begin(MIDI_CHANNEL_OMNI);

  MIDI.setHandleNoteOn(onNoteOn);
  MIDI.setHandleNoteOff(onNoteOff);
}

void loop() {
  MIDI.read();
}

void onNoteOn(byte channel, byte note, byte velocity) {

  if (note < FIRST_NOTE || note > FIRST_NOTE + NUM_LEDS - 1)
  return; //if a key is pressed but isnt in the range
          //then no led is lit up

  int ledIndex = note - FIRST_NOTE;
  CRGB color = noteColors[note % 12]; //find the corresponding color to the key

  color.nscale8(map(velocity, 0, 127, 50, 255)); //scale intensity of pressed key to the led intensity
  leds[ledIndex] = color;

  FastLED.show();

  #ifdef display_oled
    lastNote = currentNote;
    currentNote = noteNames[note % 12] + String((note / 12) - 1);
    note_display(currentNote, lastNote, ledIndex); //display (actual note / last note / note number)
  #endif

  
}

void onNoteOff(byte channel, byte note, byte velocity) {

  if (note < FIRST_NOTE || note > FIRST_NOTE + NUM_LEDS - 1) return;
  leds[note - FIRST_NOTE] = CRGB::Black; // turn the led off after being pressed

  FastLED.show();


}