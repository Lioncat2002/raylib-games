CC = gcc
INCDIR = -Iinclude
LIBDIR = -L lib/
CFLAGS += -O2 -Wall -std=c99

LDFLAGS += -lraylib -lopengl32 -lgdi32 -lwinmm

.PHONY: all clean

all:
	$(CC) main.c -o  main.exe $(CFLAGS) $(INCDIR) $(LIBDIR) $(LDFLAGS)

clean:
	rm *.o
	rm *.a
	rm *.exe