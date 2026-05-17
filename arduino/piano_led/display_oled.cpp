#include "display_oled.h"

#define screen_width 128
#define screen_height 64
#define screen_SDA 8
#define screen_SCL 9

#define loading_posX 10
#define loading_posY 50

Adafruit_SSD1306 display(screen_width, screen_height, &Wire, -1);

const char* noteNames[12] = {  // definition
    "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"
};



void showBoot(){

    Wire.begin(screen_SDA, screen_SCL);
    Wire.setClock(400000);

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {

        Serial.println("SSD1306 failed");
        while (true){
        }
    }

    display.clearDisplay();
    display.setTextColor(WHITE);


    display.setTextSize(2);
    display.setCursor(10, 5);
    display.println("PIANO LED TOUCH");

    display.setTextSize(1);
    display.setCursor(10, 40);
    display.println("by Roses097");


    display.drawRect(loading_posX, loading_posY, 108, 10, WHITE);
    display.display();

    for (int i = 0; i <= 109; i += 7)
    {
        display.fillRect(loading_posX, loading_posY, i, 10, WHITE);
        display.display();
        delay(50);
    }

    delay(500);
    display.clearDisplay();
    display.display();

}



void note_display(String actualNote, String lastNote, int keyNumber){

    //reset screen at every new key pressed
    display.clearDisplay();

    // middle center actual note
    display.setTextSize(3);
    display.setCursor(40, 12);
    display.println(actualNote);

    // right bottom corner last note
    display.setTextSize(2);
    display.setCursor(83, 49);
    display.println(lastNote);

    // left bottom corner  note number between 1 and 88
    display.setTextSize(2);
    display.setCursor(18, 49);
    display.println(keyNumber);

    //line separation
    display.drawLine(0, 43, 128, 43, WHITE);
    display.drawLine(64, 64, 64, 43, WHITE);
    display.display();

}