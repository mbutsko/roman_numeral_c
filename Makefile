TEST_LIBS=
C_FLAGS=-Wall

all: roman
	
roman: roman.c roman.h
	gcc -o roman roman.c -lcheck -lm -lrt -lpthread

clean: roman.c roman.h
	rm *o roman

test: test_roman.c test_roman.ts
	checkmk test_roman.ts > test_roman.c
	gcc -o test_roman test_roman.c $(TEST_LIBS)
	./test_roman
