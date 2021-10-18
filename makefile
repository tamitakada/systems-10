all: main.o linked_list.o
	gcc -o main main.o linked_list.o
main.o: main.c linked_list.h
	gcc -c main.c
linked_list.o: linked_list.c
	gcc -c linked_list.c
run: main
	./main