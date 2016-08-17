#include <roman.h>
#include <string.h>
#include <stdio.h>

int rom_ToArabic(char* rom) {
    int arabic, i, check_pos;
    arabic = 0;
    check_pos = 0;
    if (strlen(rom) > 0) {
        for (i=0; i < numeral_count; i++) {
          /* Go into two character check */
            if (strncmp(rom_numerals[i], rom + check_pos, 2) == 0 && strlen(rom) > check_pos) {
                arabic += rom_numbers[i];
                check_pos += 2;
          /* Go into 1-3 one character checks - should be able to loop */
            } else if (strlen(rom) > check_pos && strlen(rom_numerals[i]) < 2 && strncmp(rom_numerals[i], rom + check_pos, 1) == 0) {
                arabic += rom_numbers[i];
                check_pos += 1;
            }
if (strlen(rom) > check_pos && strlen(rom_numerals[i]) < 2 && strncmp(rom_numerals[i], rom + check_pos, 1) == 0) {
                arabic += rom_numbers[i];
                check_pos += 1;
            }

if (strlen(rom) > check_pos && strlen(rom_numerals[i]) < 2 && strncmp(rom_numerals[i], rom + check_pos, 1) == 0) {
                arabic += rom_numbers[i];
                check_pos += 1;
            }

        }
    } 
    return arabic;
}

char* rom_ToRoman(int x) {
    int i;
    char numeral[16];
    memset(numeral, 0, 16);

    for (i=0; i < numeral_count; i++) {
        while (x >= rom_numbers[i]) { 
            strcat(numeral, rom_numerals[i]);
            x = x - rom_numbers[i];
        }
    }
    return strdup(numeral);
}
