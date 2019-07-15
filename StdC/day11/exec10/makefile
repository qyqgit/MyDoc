all : a.out

a.out : main.o lib.o stdout.o point.o circ.o
	gcc main.o lib.o stdout.o point.o circ.o
main.o : main.c
	gcc -c main.c
lib.o : lib.c
	gcc -c lib.c
stdout.o : stdout.c
	gcc -c stdout.c
point.o : point.c
	gcc -c point.c
circ.o : circ.c
	gcc -c circ.c

clean:
	rm -rf *.o
	rm -rf *.out


