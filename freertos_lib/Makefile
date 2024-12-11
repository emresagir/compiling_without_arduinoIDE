CC = avr-gcc
CXX = avr-g++
MCU = -mmcu=atmega328p
CPU_SPEED = -DF_CPU=16000000UL
INCLUDE = -I/home/emre/Arduino/libraries/FreeRTOS/src -I/home/emre/.arduino15/packages/arduino/hardware/avr/1.8.6/cores/arduino -I/home/emre/.arduino15/packages/arduino/hardware/avr/1.8.6/variants/standard

# Identify source files in the Arduino core
CORE_SRC = $(wildcard /home/emre/Arduino/libraries/FreeRTOS/src/*.cpp) \
           $(wildcard /home/emre/Arduino/libraries/FreeRTOS/src/*.c)

# Create object file names by replacing .cpp and .c with .o
CORE_OBJ = $(CORE_SRC:.cpp=.o) $(CORE_SRC:.c=.o)

# Compile flags
CFLAGS = -c -g -Os -w -ffunction-sections -fdata-sections $(MCU) $(CPU_SPEED) $(INCLUDE)
CPPFLAGS = -c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections $(MCU) $(CPU_SPEED) $(INCLUDE)

# Target to create the static library
all: libfreertos.a

# Rule to compile .cpp files into object files
%.o: %.cpp
	$(CXX) $(CPPFLAGS) $< -o $@

# Rule to compile .c files into object files
%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

# Archive object files into a static library
libfreertos.a: $(CORE_OBJ)
	avr-ar rcs $@ $^

# Clean up object files and the static library
clean:
	rm -f $(CORE_OBJ) libfreertos.a
cp:
	cp /home/emre/Arduino/libraries/FreeRTOS/src/* .