TEST_LIBS=-lcheck -lm -lrt -lpthread
C_FLAGS=-I. -Wall 

all: roman

roman: roman.o
	gcc $(C_FLAGS) -o roman roman.o

roman.o: roman.c roman.h
	gcc $(C_FLAGS) -c roman.c

clean: roman.c roman.h
	-rm *o roman test_roman

check: roman.o test_roman.ts
	checkmk test_roman.ts > test_roman.c
	gcc -o test_roman test_roman.c roman.o $(TEST_LIBS)
	./test_roman
