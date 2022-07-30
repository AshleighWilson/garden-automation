#include <Arduino.h>
#include <Adafruit_LC709203F.h>
#include "tft.h"

extern Adafruit_LC709203F battery;

void setup() {
	Serial.begin(115200);
	delay(2000);
	Serial.println(F("Booting.."));

	init_screen();

	if(!battery.begin()) {
		Serial.println(F("Couldn't detect battery."));
		while(1);
	}
}

int count = 0;

void loop() {
	Serial.println(count++);
	delay(1000);
	print_screen();
}
