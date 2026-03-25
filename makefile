all: graph.o main.c
	gcc graph.o main.c -o main -std=c99 -Wall -lm
graph:
	gcc -c graph.c -o graph.o
run:
	./main
clean:
	rm *.o
memory:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./main