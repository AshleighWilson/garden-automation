#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <Adafruit_LC709203F.h> // Internal battery monitor
#include <SPI.h>

#include "tft.h"

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);
GFXcanvas16 canvas(240, 135);
Adafruit_LC709203F battery;


void init_screen() {
	Serial.print(F("Initialising TFT screen.. "));
	pinMode(TFT_BACKLITE, OUTPUT);
	digitalWrite(TFT_BACKLITE, HIGH);

	pinMode(TFT_I2C_POWER, OUTPUT);
	digitalWrite(TFT_I2C_POWER, HIGH);
	delay(10);
	Serial.println(F("done."));

	tft.init(135, 240);
	tft.setRotation(1);

	tft.setTextWrap(false);
	tft.setCursor(0, 30);
	tft.setTextColor(ST77XX_WHITE);
	tft.setTextSize(2);
	clear_screen();
}

void clear_screen() {
	tft.fillScreen(ST77XX_BLACK);
}

void print_screen() {
	canvas.fillScreen(ST77XX_BLACK);
	canvas.setCursor(0, 25);
	canvas.setTextColor(ST77XX_ORANGE);
	canvas.setTextSize(2);
	canvas.print("BAT  ");
	canvas.setTextColor(ST77XX_WHITE);
	canvas.print(battery.cellVoltage(), 2);
	canvas.print("V / ");
	canvas.print(battery.cellPercent(), 1);
	canvas.println("%");

	tft.drawRGBBitmap(0, 0, canvas.getBuffer(), 240, 135);
	delay(5000);
}

