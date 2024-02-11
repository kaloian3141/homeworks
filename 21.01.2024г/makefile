all: taskmanager.out

taskmanager.out: processes.o processes.h taskmanager.c
	gcc taskmanager.c processes.o -o taskmanager.out

processes.o: processes.h processes.c
	gcc -c processes.c -o processes.o

clean:
	rm -f *.out *.o