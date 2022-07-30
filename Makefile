DEV_BOARD = "/dev/serial/by-id/usb-Adafruit_Feather_ESP32-S2_TFT_84:f7:03:f5:a5:52-if00"

all:
	pio -f -c vim run

upload:
	pio -f -c vim run --target upload

clean:
	pio -f -c vim run --target clean

program:
	pio -f -c vim run --target program

uploadfs:
	pio -f -c vim run --target uploadfs

update:
	pio -f -c vim update

monitor:
	pio -f -c vim run --target monitor

init:
	pio project init --ide vim
