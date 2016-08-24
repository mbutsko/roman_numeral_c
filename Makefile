TEST_LIBS=-lcheck -lm -lrt -lpthread
C_FLAGS=-I. -Wall -Wextra

all: roman_arithmetic

roman_arithmetic: main.o roman_conversion.o roman_arithmetic.o 
	gcc $(C_FLAGS) -o roman_math main.o roman_conversion.o roman_arithmetic.o

main.o: main.c roman_conversion.h roman_arithmetic.h
	gcc $(CFLAGS) -c main.c

roman_conversion.o: roman_conversion.c roman_conversion.h
	gcc $(C_FLAGS) -c roman_conversion.c

roman_arithmetic.o: roman_arithmetic.c roman_arithmetic.h
	gcc $(C_FLAGS) -c roman_arithmetic.c

.PHONEY: clean
clean: 
	-rm *o test_roman_conversion test_roman_arithmetic

check: roman_conversion.o test_roman_conversion.ts roman_arithmetic.o test_roman_arithmetic.ts
	checkmk test_roman_conversion.ts > test_roman_conversion.c
	checkmk test_roman_arithmetic.ts > test_roman_arithmetic.c
	gcc -o test_roman_conversion test_roman_conversion.c roman_conversion.o $(TEST_LIBS)
	gcc -o test_roman_arithmetic test_roman_arithmetic.c roman_conversion.o roman_arithmetic.o $(TEST_LIBS)
	./test_roman_conversion
	./test_roman_arithmetic
