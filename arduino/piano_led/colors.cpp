#include "colors.h"


CRGB noteColors[12];    // default storage (defined once)

/*                          HOW TO ADD YOUR OWN PALETTE                           */

/*  1 - To create your own palette, make a function called setColorThemeX()                         
            (keep it this format so it's easier for others to use it)

/*  2 -              Add your function name into colors.h                         */

/*  3 - In piano_led_touch.ino , change only the first line of the void setup()   */
/*                        to the color theme you wish to us.                      */


//base color
void setColorTheme1() {
  noteColors[0] = CRGB(255, 0, 0);
  noteColors[1] = CRGB(255, 69, 0);
  noteColors[2] = CRGB(255, 165, 0);
  noteColors[3] = CRGB(255, 215, 0);
  noteColors[4] = CRGB(255, 255, 0);
  noteColors[5] = CRGB(0, 255, 0);
  noteColors[6] = CRGB(0, 255, 127);
  noteColors[7] = CRGB(0, 191, 255);
  noteColors[8] = CRGB(0, 0, 255);
  noteColors[9] = CRGB(75, 0, 130);
  noteColors[10] = CRGB(148, 0, 211);
  noteColors[11] = CRGB(255, 0, 255);
}

//Pastel colors
void setColorTheme_Pastel() {
  noteColors[0]  = CRGB(255, 182, 193); // C  - Pastel Pink
  noteColors[1]  = CRGB(255, 204, 170); // C# - Pastel Peach
  noteColors[2]  = CRGB(255, 229, 153); // D  - Pastel Yellow
  noteColors[3]  = CRGB(204, 255, 153); // D# - Pastel Lime
  noteColors[4]  = CRGB(153, 255, 204); // E  - Pastel Mint
  noteColors[5]  = CRGB(153, 229, 255); // F  - Pastel Sky
  noteColors[6]  = CRGB(153, 179, 255); // F# - Pastel Periwinkle
  noteColors[7]  = CRGB(179, 153, 255); // G  - Pastel Lavender
  noteColors[8]  = CRGB(229, 153, 255); // G# - Pastel Lilac
  noteColors[9]  = CRGB(255, 153, 229); // A  - Pastel Rose
  noteColors[10] = CRGB(255, 153, 179); // A# - Pastel Coral
  noteColors[11] = CRGB(204, 204, 255); // B  - Pastel Blue
}
