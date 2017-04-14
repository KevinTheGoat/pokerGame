#makefile
#Description: complies all source files for program which are included in FILES

CC = gcc -pedantic -ansi
FILES = main.c cards.c player.c deck.c

.PHONY: makefile

build: $(FILES)
	$(CC) -o studPoker $(FILES)
clean:
	rm -f *.out