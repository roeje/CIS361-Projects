CFLAGS=-std=gnu99

cipher: cipher.o
	gcc cipher.o -o cipher
cipher.o: cipher.c

test: test1 test2
test1:
	./cipher 1 testkeyone data.txt data.out
test2:
	./cipher 2 testkeyone data.out data.bak
