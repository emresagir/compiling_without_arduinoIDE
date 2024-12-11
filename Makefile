MCU = atmega328p
F_CPU = 16000000UL
PORT = /dev/ttyUSB0
BAUD = 115200
CORE_PATH = /home/emre/.arduino15/packages/arduino/hardware/avr/1.8.6/cores/arduino
VARIANT_PATH = /home/emre/.arduino15/packages/arduino/hardware/avr/1.8.6/variants/standard
FREERTOS_PATH = /home/emre/Arduino/libraries/FreeRTOS/src
LIBS = -L/home/emre/Arduino/FreeRTOS_Arduino/library -L/home/emre/Arduino/FreeRTOS_Arduino/freertos_lib -lcore -lfreertos


CFLAGS = -Os -DF_CPU=$(F_CPU) -mmcu=$(MCU) -I$(CORE_PATH) -I$(VARIANT_PATH) -I$(FREERTOS_PATH)
LDFLAGS = -mmcu=$(MCU) $(LIBS)

all: main.hex

main.o: main.cpp
	avr-gcc $(CFLAGS) -c main.cpp -o main.o

main.elf: main.o
	avr-gcc main.o $(LDFLAGS) -o main.elf

main.hex: main.elf
	avr-objcopy -O ihex -R .eeprom main.elf main.hex

upload: main.hex
	avrdude -V -F -c arduino -p $(MCU) -P $(PORT) -b $(BAUD) -U flash:w:main.hex

clean:
	rm -f *.o *.elf *.hex
