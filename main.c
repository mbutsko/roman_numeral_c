#include <string.h>
#include <stdio.h>
#include "roman.h"

int main( int argc, const char* argv[] )
{
  if (argc != 4) {
    printf("Should supply an operand, operator and another operand. \n");
    return 1;
  } else if (strcmp(argv[2], "+") == 0) {
    printf("%s\n", addRoman( strdup(argv[1]), strdup(argv[3]) ));
    return 0;
  } else if (strcmp(argv[2], "-") == 0) {
    printf("%s\n", subtractRoman( strdup(argv[1]), strdup(argv[3]) ));
    return 0;
  }
}
