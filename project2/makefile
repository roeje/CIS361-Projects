CFLAGS=-std=gnu99

project2: project2.o
	gcc project2.o -o project2
project2.o: project2.c queue.c list.c

testList: testList.o
	gcc testList.o -o testList
testList.o: llistTest.c queue.c list.c

test1: test1encrypt test1decrypt test1check
test1encrypt:
	./project2 1 feather testInput1.txt testOutput1.out
test1decrypt:
	./project2 2 feather testOutput1.out testResult1.out
test1check:
	diff -s testInput1.txt testResult1.out || echo "Files are not identical"
