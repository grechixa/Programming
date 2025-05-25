CC = gcc
CFLAGS = -Wall -Wextra -std=c11

OBJ = main.o data.o

LR_5: $(OBJ)
	$(CC) $(CFLAGS) -o LR_5 $(OBJ)

main.o: main.c data.h
	$(CC) $(CFLAGS) -c main.c

data.o: data.c data.h
	$(CC) $(CFLAGS) -c data.c

clean:
	rm -f *.o LR_5