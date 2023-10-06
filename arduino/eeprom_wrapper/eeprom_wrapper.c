#include "eeprom_wrapper.h"

void writeLongIntoEEPROM(int address, long number)
{
	EEPROM.write(address, (number >> 24) & 0xFF);
	EEPROM.write(address + 1, (number >> 16) & 0xFF);
	EEPROM.write(address + 2, (number >> 8) & 0xFF);
	EEPROM.write(address + 3, number & 0xFF);
}

long readLongFromEEPROM(int address)
{
	return ((long)EEPROM.read(address) << 24) +
		   ((long)EEPROM.read(address + 1) << 16) +
		   ((long)EEPROM.read(address + 2) << 8) +
		   (long)EEPROM.read(address + 3);
}