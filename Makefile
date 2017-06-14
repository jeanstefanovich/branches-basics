.PHONY: all clean make
CC = gcc

all: wrongverb.exe

wrongverb.exe: build/src/modul.o build/src/main.o wrong_verbs.txt
	mkdir -p bin/
	$(CC) -Wall -o bin/wrongverb.exe build/src/modul.o build/src/main.o

build/src/modul.o:
	mkdir -p build/src
	$(CC) -I src/ -Werror -Wall -c -o build/src/modul.o src/modul.c

build/src/main.o:
	mkdir -p build/src
	$(CC) -I src/ -Werror -Wall -c -o build/src/main.o src/main.c

wrong_verbs.txt:
	mkdir -p bin/
	cp src/wrong_verbs.txt bin/wrong_verbs.txt

clean:
	rm -rf bin/
	rm -rf build/
