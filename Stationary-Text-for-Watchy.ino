#include <Watchy.h> //include the Watchy library
#include "NunitoSans_Bold28pt7b.h"
#include "NunitoSans_Light28pt7b.h"
        

class WatchFace : public Watchy { //inherit and extend Watchy class
  public:
    void drawWatchFace() { //override this method to customize how the watch face looks
      uint16_t lines = 0;
      const char *lows [10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
      const char *teensone [10] = {"ten", "eleven", "twelve", "thir", "four", "fif", "six", "seven", "eight", "nine"};
      const char *teenstwo [10] = {"", "", "", "teen", "teen", "teen", "teen", "teen", "teen", "teen"};
      const char *tens [10] = {"zero", "ten", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};

      //drawbg
      display.fillScreen(GxEPD_BLACK);

      display.setTextColor(GxEPD_WHITE);
      display.setTextWrap(false);

      lines += 1;
      display.setCursor(5, lines*46-2);
      display.setFont(&NunitoSans_Bold28pt7b);
      if (currentTime.Hour == 0) {
        display.print(tens[2]);
        lines += 1;
        display.setCursor(5, lines*46-2);
        display.print(lows[4]);
      } else if (currentTime.Hour < 10) {
        display.print(lows[currentTime.Hour]);
      } else if (currentTime.Hour < 20) {
        display.print(teensone[currentTime.Hour/10]);
        if (currentTime.Hour > 12) {
          lines += 1;
          display.setCursor(5, lines*46-2);
          display.print(teenstwo[currentTime.Hour%10]);
        }
      } else {
        display.print(tens[currentTime.Hour/10]);
        if (currentTime.Hour%10 > 0) {
          display.print(lows[currentTime.Hour%10]);
        }
      }

      lines += 1;
      display.setCursor(5, lines*46-2);
      display.setFont(&NunitoSans_Light28pt7b);
      if (currentTime.Minute == 0) {
      } else if (currentTime.Minute < 10) {
        display.print(lows[currentTime.Minute]);
      } else if (currentTime.Minute < 20) {
        display.print(teensone[currentTime.Minute/10]);
        if (currentTime.Minute > 12) {
          lines += 1;
          display.setCursor(5, lines*46-2);
          display.print(teenstwo[currentTime.Minute%10]);
        }
      } else {
        display.println(tens[currentTime.Minute/10]);
        if (currentTime.Minute%10 > 0) {
          lines += 1;
          display.setCursor(5, lines*46-2);
          display.print(lows[currentTime.Minute%10]);
        }
      }                
    }
};

WatchFace m; //instantiate your watchface

void setup() {
  m.init(); //call init in setup
}

void loop() {
  // this should never run, Watchy deep sleeps after init();
}
