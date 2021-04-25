CC = gcc
CFLAGS = -Wall
DEPS = function.h function.c calculator.h calculator.c
OBJ = function.o calculator.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

calculator: $(OBJ)
	gcc $(CFLAGS) -lm -o $@ $^
