/*
 *  This sketch shows sector hoping acros reboots
 */

#include <EEPROM_Rotate.h>

EEPROM_Rotate EEPROMr;

#define DATA_OFFSET     10

void setup() {

    Serial.begin(115200);
    Serial.println();
    Serial.println();
    delay(2000);

    EEPROMr.sectors(4);
    EEPROMr.begin(4096);
    Serial.println();

    uint8_t data;

    Serial.printf("Position 0: 0x%02X\n", EEPROMr.read(0));
    Serial.printf("Position 1: 0x%02X\n", EEPROMr.read(1));
    Serial.printf("Position 2: 0x%02X\n", EEPROMr.read(2));
    Serial.printf("Data      : 0x%02X\n", data = EEPROMr.read(DATA_OFFSET));

    Serial.println();
    Serial.printf("Writing 0x%02X to data\n", data + 1);
    EEPROMr.write(DATA_OFFSET, data + 1);

    Serial.println();
    Serial.printf("Commit %s\n", EEPROMr.commit() ? "OK" : "KO");
    Serial.printf("Position 0: 0x%02X\n", EEPROMr.read(0));
    Serial.printf("Position 1: 0x%02X\n", EEPROMr.read(1));
    Serial.printf("Position 2: 0x%02X\n", EEPROMr.read(2));
    Serial.printf("Data      : 0x%02X\n", data = EEPROMr.read(DATA_OFFSET));

}

void loop() {}
