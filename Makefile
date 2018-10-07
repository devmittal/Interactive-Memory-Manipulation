
prog:	main.o help.o allocate.o free.o display.o write.o invblk.o wrpatt.o verpatt.o
	cc -o prog main.o help.o allocate.o free.o display.o write.o invblk.o wrpatt.o 	verpatt.o

main.o: main.c help.h allocate.h free.h display.h write.h invblk.h wrpatt.h verpatt.h
	cc -c main.c

help.o: help.c help.h
	cc -c help.c

allocate.o: allocate.c allocate.h
	cc -c allocate.c

free.o: free.c allocate.h free.h
	cc -c free.c

display.o: display.c allocate.h display.h
	cc -c display.c

invblk.o: invblk.c invblk.h allocate.h
	cc -c invblk.c

write.o: write.c allocate.h write.h
	cc -c write.c

wrpatt.o: wrpatt.c allocate.h wrpatt.h
	cc -c wrpatt.c

verpatt.o: verpatt.c allocate.h wrpatt.h verpatt.h
	cc -c verpatt.c

clean:  
	rm prog *.o

test: prog testfile
	./prog < testfile

