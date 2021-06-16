#makefile
main: main.o linked_list.o
	gcc -g main.o linked_list.o -o main.exe
	./main

compile: linked_list.c linked_list.h
	gcc -g -c linked_list.c
	gcc -g -c main.c

clean:
	rm *.o main *.exe