all: help.out strlength.out strconcat.out strcompare.out

help.out: main.c
	gcc main.c -o help.out

strlength.out: strlength.c mystring.o
	gcc strlength.c mystring.o -o strlength.out

strconcat.out: strconcat.c mystring.o
	gcc strconcat.c mystring.o -o strconcat.out

strcompare.out: strcompare.c mystring.o
	gcc strcompare.c mystring.o -o strcompare.out

mystring.o: mystring.c mystring.h
	gcc -c mystring.c -o mystring.o

clean:
	rm -f *.o *.out
