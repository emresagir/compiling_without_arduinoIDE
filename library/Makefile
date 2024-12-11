CC = avr-gcc
CXX = avr-g++
MCU = -mmcu=atmega328p
CPU_SPEED = -DF_CPU=16000000UL
INCLUDE = -I  # Adjust if you have other directories for includes

# List of object files you want to include in the library
OBJ = $(wildcard *.o)  # All .o files in the current directory

# Target to create the static library
all: libcore.a

# Rule to create the static library (libcore.a) from object files
libcore.a: $(OBJ)
	avr-ar rcs $@ $(OBJ)

# Clean up object files and the static library
clean:
	rm -f $(OBJ) libcore.a

cp:
	cp /home/emre/.arduino15/packages/arduino/hardware/avr/1.8.6/cores/arduino/* .