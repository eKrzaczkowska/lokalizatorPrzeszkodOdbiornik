# Typ AVRa
MMCU = atmega8a

# Częstotliwość zegara
F_CPU = 8000000

# Typ programatora
PROGRAMMER = usbasp 
PROGRAMMER_PORT = usb

# Nazwa wynikowego pliku hex
PROJECT = toprog

# Pliki źródłowe
SOURCES = main.c nRF24L01.c SPI.c uart.c

OBJECTS = $(SOURCES:.c=.o)

# Kompilator
CC = avr-gcc
OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump

# Flagi do kompilacji
CFLAGS = -DF_CPU=$(F_CPU)UL 
CFLAGS += -mmcu=$(MMCU) -g -Os -Wall

help:
	@echo 'clean        Delete automatically created files.'
	@echo 'help     Show this text.'
	@echo 'hex      Create all hex files for flash, eeprom and fuses.'
	@echo 'elf      Create .elf file'
	@echo 'disasm      Create demo.lst file with all statistics and disassebly'
	@echo 'flash      Program avr.'

# Make output file .elf from compiled all files 
elf: main.o nRF24L01.o SPI.o uart.o
	$(CC) $(CFLAGS) main.o nRF24L01.o SPI.o uart.o -o $(PROJECT).elf -lm

# Compile all files
main.o: main.c SPI.h nRF24L01.h nRF24L01_memory_map.h uart.h
	$(CC) $(CFLAGS) -c main.c

SPI.o: SPI.c SPI.h
	$(CC) $(CFLAGS) -c SPI.c

nRF24L01.o: nRF24L01.c nRF24L01.h nRF24L01_memory_map.h
	$(CC) $(CFLAGS) -c nRF24L01.c

uart.o: uart.c uart.h 
	$(CC) $(CFLAGS) -c uart.c

# Make hex file to program to avr; avr-size print short statistics
hex: elf
	$(OBJCOPY) -O ihex -R .eeprom $(PROJECT).elf $(PROJECT).hex
	avr-size $(PROJECT).elf

disasm: elf
	$(OBJDUMP) -h -S $(PROJECT).elf > demo.lst

# Flash avr
flash: hex
	avrdude -c $(PROGRAMMER) -P $(PROGRAMMER_PORT) -p m8 -U flash:w:$(PROJECT).hex 
	
clean:
	rm -f $(PROJECT).elf
	rm -f $(PROJECT).hex
	rm -f $(OBJECTS)
	rm -f demo.lst

#This is not a file name
.PHONY: help elf hex disasm flash clean
