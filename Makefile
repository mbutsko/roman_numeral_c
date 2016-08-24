TEST_LIBS=-lcheck -lm -lrt -lpthread
TEST_DIR=./test/
SRC_DIR=./src/
C_FLAGS=-I. -Wall -Wextra

all: roman_arithmetic

roman_arithmetic: src/main.o src/roman_conversion.o src/roman_arithmetic.o 
	gcc $(C_FLAGS) -o roman_math main.o roman_conversion.o roman_arithmetic.o

src/main.o: src/main.c src/roman_conversion.h src/roman_arithmetic.h
	gcc $(CFLAGS) -c src/main.c

src/roman_conversion.o: src/roman_conversion.c src/roman_conversion.h
	gcc $(C_FLAGS) -c src/roman_conversion.c

src/roman_arithmetic.o: src/roman_arithmetic.c src/roman_arithmetic.h
	gcc $(C_FLAGS) -c src/roman_arithmetic.c

.PHONEY: clean
clean: 
	-rm roman_math test/roman_conversion test/roman_arithmetic *.o

check: src/roman_conversion.o test/roman_conversion.ts src/roman_arithmetic.o test/roman_arithmetic.ts
	checkmk test/roman_conversion.ts > test/roman_conversion.c
	checkmk test/roman_arithmetic.ts > test/roman_arithmetic.c
	gcc -o test/roman_conversion test/roman_conversion.c roman_conversion.o $(TEST_LIBS)
	gcc -o test/roman_arithmetic test/roman_arithmetic.c roman_conversion.o roman_arithmetic.o $(TEST_LIBS)
	./test/roman_conversion
	./test/roman_arithmetic
