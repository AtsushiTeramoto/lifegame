OBJS = main.o Run.o Initialize.o Step.o Finalize.o Output.o
OPTIONS = -DMAX_X=5 -DMAX_Y=8 -DSTEP_MAX=30
OPTIONS += -DUSE_INIT_ARRAY
CFLAGS = ${OPTIONS} -W -Wall -g

lifegame : ${OBJS} Makefile
	cc -o lifegame ${OBJS}

clean :
	rm *.o

main.o : main.c Structures.h Initialize.h Run.h Finalize.h Makefile
Run.o : Run.c Structures.h Run.h Step.h Output.h  Makefile
Initialize.o : Initialize.c Structures.h Initialize.h Makefile
Finalize.o : Finalize.c Structures.h Finalize.h Makefile
Step.o : Step.c Structures.h Step.h Finalize.h Initialize.h Makefile
Output.o : Output.c Structures.h Makefile
