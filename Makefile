OBJS = main.o Run.o Initialize.o Step.o Finalize.o Output.o
OPTIONS = -DMAX_X=10 -DMAX_Y=10 -DSTEP_MAX=20
CFLAGS = ${OPTIONS} -W -Wall -g

lifegame : ${OBJS}
	cc -o lifegame ${OBJS}

clean :
	rm *.o

main.o : main.c Structures.h Initialize.h Run.h Finalize.h
Run.o : Run.c Structures.h Run.h Step.h Output.h 
Initialize.o : Initialize.c Structures.h Initialize.h
Finalize.o : Finalize.c Structures.h Finalize.h
Step.o : Step.c Structures.h Step.h Finalize.h Initialize.h
Output.o : Output.c Structures.h
