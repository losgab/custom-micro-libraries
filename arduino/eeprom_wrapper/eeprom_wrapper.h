/*
    EPPROM Simple Saving for Arduino

    Convenience library for persistent saving values into Arduino

    Written by Gabriel Thien 2023
*/
#ifndef eeprom_wrapper_h
#define eeprom_wrapper_h

#include <EEPROM.h>

/**
 * @brief Writes bytes into EEPROM at specified address
 * 
 * @param address Location at which the data will be stored
 * @param data Data to be stored
 * 
 * @return void
*/
void writeLongIntoEEPROM(int address, long data);

/**
 * @brief Reads bytes from specified address and reconstructs data
 * 
 * @param address Data location to extract from
 * 
 * @return Data
*/
long readLongFromEEPROM(int address);

#endif eeprom_wrapper_h
