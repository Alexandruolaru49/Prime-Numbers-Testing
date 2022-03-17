CC = gcc
CFLAGS = -Wall -Wextra -O2
LDLIBS = -lm

build: fermat_test.o miller_rabin_test.o best_test.o

run-p1:
	./test1

run-p2:
	./test2

run-best:
	./test3

fermat.o: fermat.c
	gcc fermat.c -c $(CFLAGS)

fermat_test.o: main.c fermat.o
	gcc fermat.o main.c -o test1 $(CFLAGS)

miller_rabin.o: miller_rabin.c
	gcc miller_rabin.c -c $(CFLAGS)

miller_rabin_test.o: main.c miller_rabin.o 
	gcc miller_rabin.o main.c -o test2 $(CFLAGS)

best.o: best.c
	gcc best.c -c $(CFLAGS)

best_test.o: main.c best.o
	gcc best.o main.c -o test3 $(CFLAGS)

.PHONY: clean

clean:
	rm -rf *.o test1 test2 test3