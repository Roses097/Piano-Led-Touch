#pragma once
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>


extern const char* noteNames[12];
extern Adafruit_SSD1306 display;

void showBoot();
void note_display(String actualNote, String lastNote, int keyNumber);