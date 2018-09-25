
prog:	main.o help.o allocate.o free.o display.o write.o invblk.o wrpatt.o verpatt.o
	cc -o prog main.o help.o allocate.o free.o display.o write.o invblk.o wrpatt.o 	verpatt.o

main.o: main.c controller.h
	cc -c main.c

help.o: help.c
	cc -c help.c

allocate.o: allocate.c
	cc -c allocate.c

free.o: free.c
	cc -c free.c

display.o: display.c
	cc -c display.c

write.o: write.c
	cc -c write.c

wrpatt.o: wrpatt.c
	cc -c wrpatt.c

verpatt.o: verpatt.c
	cc -c verpatt.c

clean:  
	rm prog *.o

