#include <stdio.h>
#include "roman.h"

#test converts_one_to_I
    ck_assert_str_eq("I", (rom_ConvertToRoman(1))
    );
