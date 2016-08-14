Initializer = Preset
OBJS = main.o Run.o Initialize.o Step.o Finalize.o Output.o
ifeq ($(Initializer), Random)
	OBJS += GenerateInitialState_Random.o
	LDFLAGS += -L/usr/local/opt/gsl/lib -lgsl
	OPTIONS = -DMAX_X=5 -DMAX_Y=8 -DMAX_STEP=30
endif
ifeq ($(Initializer), Preset)
	OBJS += GenerateInitialState_Preset.o
	#OPTIONS = -DPULSAR
	OPTIONS = -DGLIDER
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
GenerateInitialState_Random.o : GenerateInitialState_Random.c GenerateInitialState.h Makefile
GenerateInitialState_Preset.o : GenerateInitialState_Preset.c GenerateInitialState.h Makefile
