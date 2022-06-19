CC = gcc

mulmake: mul.o main.o
	$(CC) -o mulmake mul.o main.o

mul.o: mul.c
	$(CC) -c -o mul.o mul.c

main.o: main.c
	$(CC) -c -o main.o main.c

clean:
	rm -f mul.o main.o mulmake