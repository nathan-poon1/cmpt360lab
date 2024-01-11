CC = gcc
CFLAGS = -Wall -std=c11
LIBS = -lm

.PHONY: all clean

all: test_dStruct

test_dStruct: dStruct.o test_dStruct.o
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

dStruct.o: dStruct.c dStruct.h
	$(CC) $(CFLAGS) -c $< -o $@

test_dStruct.o: test_dStruct.c dStruct.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f test_dStruct *.o
