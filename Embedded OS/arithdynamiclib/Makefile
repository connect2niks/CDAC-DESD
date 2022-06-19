CC = gcc

libarith.a : add.o sub.o mul.o div.o
	$(CC) -shared -fPIC -o libarith.so add.o sub.o mul.o div.o

arithprog: add.o sub.o main.o
	$(CC) -o arithprog add.o sub.o main.o 

add.o: add.c
	$(CC) -c -o add.o add.c

sub.o : sub.c
	$(CC) -c -o sub.o sub.c

mul.o : mul.c
	$(CC) -c -o mul.o mul.c

div.o : div.c
	$(CC) -c -o div.o div.c		

main.o: main.c
	$(CC) -c -o main.o main.c

clean:
	rm -f add.o main.o sub.o mul.o div.o arithprog libarith.a