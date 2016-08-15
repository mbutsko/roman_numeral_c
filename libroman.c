#include <libroman.h>
#include <string.h>
#include <stdio.h>

char* rom_ToRoman(int x) {
  int i;
  char numeral[16];
  memset(numeral, 0, 16);

  for (i=0; i < sizeof(rom_numbers)/sizeof(int); i++) {
    while (x >= rom_numbers[i]) { 
      strcat(numeral, rom_numerals[i]);
      x = x - rom_numbers[i];
    }
  }
  return strdup(numeral);
}
