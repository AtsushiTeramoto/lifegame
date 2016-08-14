OBJS = main.o Run.o Initialize.o Step.o Finalize.o Output.o
ifeq ($(Initializer), Random)
	OBJS += GenerateInitialState_Random.o
	LDFLAGS += -L/usr/local/opt/gsl/lib -lgsl
	OPTIONS = -DMAX_X=5 -DMAX_Y=8 -DSTEP_MAX=30
endif
ifeq ($(Initializer), Preset)
	OBJS += GenerateInitialState_Preset.o
	OPTIONS = -DPULSAR -DSTEP_MAX=50
endif
CFLAGS = ${OPTIONS} -W -Wall -g

lifegame : ${OBJS} Makefile
	cc -o lifegame ${OBJS} ${LDFLAGS}

clean :
	rm *.o

main.o : main.c Structures.h Initialize.h Run.h Finalize.h Makefile
Run.o : Run.c Structures.h Run.h Step.h Output.h  Makefile
Initialize.o : Initialize.c Structures.h Initialize.h Makefile
Finalize.o : Finalize.c Structures.h Finalize.h Makefile
Step.o : Step.c Structures.h Step.h Finalize.h Initialize.h Makefile
Output.o : Output.c Structures.h Makefile
GenerateInitialState_Random.o : GenerateInitialState_Random.c GenerateInitialState.h 
GenerateInitialState_Preset.c : GenerateInitialState_Preset.c GenerateInitialState.h
