#include <libroman.h>
#include <string.h>

const char * rom_ToRoman(int x) {
  int i, ret;
  for (i=0; i < sizeof(rom_numbers); i++) {
    if (rom_numbers[i] == x) {
      ret = i;
    }
  }
  return rom_numerals[ret];
}
