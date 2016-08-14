TEST_LIBS=-lcheck -lm -lrt -lpthread
C_FLAGS=-I. -Wall 

all: roman

roman: roman.o libroman.o
	gcc $(C_FLAGS) -o roman roman.o libroman.o

roman.o: roman.c libroman.h
	gcc $(C_FLAGS) -c roman.c

libroman.o: libroman.c libroman.h
	gcc $(C_FLAGS) -c libroman.c

clean: roman.c libroman.h libroman.c
	-rm *o roman test_roman

check: libroman.o test_roman.ts
	checkmk test_roman.ts > test_roman.c
	gcc -o test_roman test_roman.c libroman.o $(TEST_LIBS)
	./test_roman
