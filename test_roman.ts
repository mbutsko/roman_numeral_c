#include <stdio.h>
#include "libroman.h"

#test converts_one_to_I
        ck_assert_str_eq("I", rom_ToRoman(1));
