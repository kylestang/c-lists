run: build
	./out

build:
	gcc src/* -o out

test:
	gcc -g src/* -o out

leaks: build
	valgrind --leak-check=full ./out
