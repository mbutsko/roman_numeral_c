TEST_LIBS=-lcheck -lm -lrt -lpthread
C_FLAGS=-I. -Wall 

all: roman
	
roman: roman.c roman.h
	gcc -o roman roman.c

clean: roman.c roman.h
	rm *o roman

test: test_roman.c test_roman.ts
	checkmk test_roman.ts > test_roman.c
	gcc -o test_roman test_roman.c $(TEST_LIBS) $(C_FLAGS)
	./test_roman
