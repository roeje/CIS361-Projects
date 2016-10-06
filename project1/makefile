CFLAGS=-std=gnu99

project1: project1.o
	gcc project1.o -o project1
project1.o: project1.c

test1: test1encrypt test1decrypt test1check
test1encrypt:
	./project1 1 feather testInput1.txt testOutput1.out
test1decrypt:
	./project1 2 feather testOutput1.out testResult1.out
test1check:
	diff -s testInput1.txt testResult1.out || echo "Files are not identical"

test2: test2encrypt test2decrypt test2check
test2encrypt:
	./project1 1 feather testInput2.txt testOutput2.out
test2decrypt:
	./project1 2 feather testOutput2.out testResult2.out
test2check:
	diff -s testInput2.txt testResult2.out || echo "Files are not identical"
