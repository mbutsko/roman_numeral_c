TEST_LIBS=-lcheck -lm -lrt -lpthread
C_FLAGS=-I. -Wall 

all: roman_conversion

roman_conversion: roman_conversion.o
	gcc $(C_FLAGS) -o roman roman_conversion.o

roman_conversion.o: roman_conversion.c roman_conversion.h
	gcc $(C_FLAGS) -c roman_conversion.c

clean: roman_conversion.c roman_conversion.h
	-rm *o roman test_roman

check: roman_conversion.o test_roman_conversion.ts
	checkmk test_roman_conversion.ts > test_roman_conversion.c
	gcc -o test_roman_conversion test_roman_conversion.c roman_conversion.o $(TEST_LIBS)
	./test_roman_conversion
