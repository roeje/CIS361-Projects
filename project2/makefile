CFLAGS=-std=gnu99

project2: project2.c queue.c list.c
	gcc -o project2 project2.c list.c queue.c -lm

test: test1
test1:
	./project2 input.txt output.txt
