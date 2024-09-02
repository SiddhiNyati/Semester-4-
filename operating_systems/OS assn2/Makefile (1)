all: main

main: main.o student.o
	gcc -o main main.o student.o

main.o: main.c student.h
	gcc -c main.c

student.o: student.c student.h
	gcc -c student.c

clean:
	rm -f main *.o

