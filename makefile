CFLAGS = -Wall -std=c++11 --pedantic-errors -O2
all: program
program: main.o Directory.o File.o Folder.o
	g++ ${CFLAGS} Directory.o main.o File.o Folder.o -o program

.PHONY:debug
debug: CFLAGS = -g -Wall --pedantic-errors
debug: program

main.o: main.cpp Directory.h
	g++ ${CFLAGS} -c main.cpp

Directory.o: Directory.h Directory.cpp File.o Folder.o
	g++ ${CFLAGS} File.o Folder.o -c Directory.cpp

File.o: File.h File.cpp
	g++ ${CFLAGS} -c File.cpp

Folder.o: Folder.h Folder.cpp
	g++ ${CFLAGS} -c Folder.cpp

clean:
	rm -rf *o program