CFLAGS=-std=gnu99

project1: project1.o
	gcc project1.o -o project1
project1.o: project1.c

test: test1 test2 test3
test1:
	./project1 1 feather input.txt output.out
test2:
	./project1 2 feather output.out decrypt.out
test3:
	diff -s input.txt decrypt.out || echo "Files are not identical"
