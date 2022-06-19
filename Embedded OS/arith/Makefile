CC = gcc

arithprog: add.o sub.o main.o
	$(CC) -o arithprog add.o sub.o main.o 

add.o: add.c
	$(CC) -c -o add.o add.c

sub.o : sub.c
	$(CC) -c -o sub.o sub.c

main.o: main.c
	$(CC) -c -o main.o main.c

clean:
	rm -f add.o main.o sub.o arithprog