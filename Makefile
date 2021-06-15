#makefile
main: main.o linked_list.o test.o
	gcc -g main.o test.o linked_list.o  -o main.exe
	./main.exe

compile: linked_list.c linked_list.h
	gcc -g -c linked_list.c
	gcc -g -c test.c
	gcc -g -c main.c

clean:
	rm *.o main *.exe

strict-compile:
	linked_list.c linked_list.h
	gcc -g -Wall -c linked_list.c
	gcc -g -Wall -c test.c
	gcc -g -Wall -c main.c

