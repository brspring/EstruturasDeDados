flags = -Wall -std=c99
nome = myavl

all: $(nome)

$(nome): main.o avl.o
	gcc -o $(nome) main.o avl.o $(flags)

main.o: main.c
	gcc -c main.c $(flags)

avl.o: avl.c
	gcc -c avl.c $(flags)

clean:
	rm -f *~ *.o

purge: clean
	rm -f $(nome)
