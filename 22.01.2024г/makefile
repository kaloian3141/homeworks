main.out: main.c quadraticroots.o quadraticroots.h
	gcc main.c quadraticroots.o -o main.out -lm

quadraticroots.o: quadraticroots.c quadraticroots.h
	gcc -c quadraticroots.c -o quadraticroots.o

clean:
	rm -f main.out *.o