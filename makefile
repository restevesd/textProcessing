CC=gcc

test: test_compile test_run

test_compile:
	$(CC) hashString.c testHashString.c -o testHashString -g -Wall

test_run:
	testHashString
