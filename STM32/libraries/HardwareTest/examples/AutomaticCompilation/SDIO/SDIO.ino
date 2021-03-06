//Automatic testing compilation of basic SDIO API

#include "SDIO.h"

SDIOClass sdio;

void setup() {
  Serial.begin(115200);
  sdio.begin();
  uint8_t data[512];

  sdio.readBlocks(1, data, 1);
  for (int i = 0; i < 512; i++)
    Serial << _HEX(data[i]) << " ";
}

void loop() {
  uint32_t s[4];
  Serial.println("\nID= ");
  sdio.readCID(s);
  for (int i = 0; i < 4; i++)
    Serial << _HEX(s[i]) << " ";
  Serial << "\nsize:" << (sdio.cardSize()+2047)/2048;
  delay(2000);
}
