#include <roman.h>
#include <string.h>
#include <stdio.h>

int rom_ToArabic(char* rom) {
    int ret,i;
    ret = 0;
    if (strlen(rom) > 0) {
        for (i=0; i < sizeof(rom_numbers)/sizeof(int); i++) {
            if (strcmp(rom_numerals[i], rom) == 0) {
                ret += rom_numbers[i];
            }
        }
    } else {
        ret = 0;
    }
    return ret;
}

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
