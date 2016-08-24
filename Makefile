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
	-rm *o test/roman_conversion test/roman_arithmetic *.o

check: roman_conversion.o test/roman_conversion.ts roman_arithmetic.o test/roman_arithmetic.ts
	checkmk test/roman_conversion.ts > test/roman_conversion.c
	checkmk test/roman_arithmetic.ts > test/roman_arithmetic.c
	gcc -o test/roman_conversion test/roman_conversion.c roman_conversion.o $(TEST_LIBS)
	gcc -o test/roman_arithmetic test/roman_arithmetic.c roman_conversion.o roman_arithmetic.o $(TEST_LIBS)
	./test/roman_conversion
	./test/roman_arithmetic
