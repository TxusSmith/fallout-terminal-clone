CC = gcc
CFLAGS = -std=c99

# DEBUGGING FLAGS
# CFLAGS = -ggdb -Wall -Wextra -pedantic -std=c99

ifeq ($(OS),Windows_NT)
	CFLAGS += -lpdcurses
else
	CFLAGS += -lncurses
endif

FalloutTerminal: main.o print.o intro.o pass.o wordParse.o getline.o getdelim.o
	$(CC) -o $@ $^ $(CFLAGS) 

main.o: main.c intro.c pass.c

intro.o: intro.c print.c

print.o: print.c

pass.o: pass.c print.c

wordParse.o: wordParse.c

getline.o: getline.c 

getdelim.o: getdelim.c

clean:
	rm -f *.o FalloutTerminal