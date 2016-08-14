#include <stdio.h>
#include "libroman.h"

#test converts_one_to_I
        ck_assert('I' == rom_ToRoman(1));
