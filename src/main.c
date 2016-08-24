#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "roman_conversion.h"
#include "roman_arithmetic.h"

int main(int argc, const char* argv[])
{
    if (argc != 4) {
        printf("Usage: %s operand operator(+ or -) operand\n", argv[0]);
        return 1;
    }
    else if (strcmp(argv[2], "+") == 0) {
        char *roman = addRoman(argv[1], argv[3]);
        printf("%s\n", roman);
        free(roman);
        return 0;
    }
    else if (strcmp(argv[2], "-") == 0) {
        char *roman = addRoman(argv[1], argv[3]);
        printf("%s\n", roman);
        free(roman);
        return 0;
    }
    else {
        printf("Unknown operand\n");
        return 1;
    }
}
