Initializer = Preset
SRCS = main.c Run.c Initialize.c Step.c Finalize.c Output.c
OBJS = main.o Run.o Initialize.o Step.o Finalize.o Output.o
HEADS =       Run.h Initialize.h Step.h Finalize.h Output.h GenerateInitialState.h Structures.h
ifeq ($(Initializer), Random)
	OBJS += GenerateInitialState_Random.o
	SRCS += GenerateInitialState_Random.c
	LDFLAGS += -L/usr/local/opt/gsl/lib -lgsl
	OPTIONS += -DMAX_X=15 -DMAX_Y=15 -DMAX_STEP=50 
endif
ifeq ($(Initializer), Preset)
	OBJS += GenerateInitialState_Preset.o
	SRCS += GenerateInitialState_Preset.c
	#OPTIONS += -DPULSAR
	OPTIONS += -DGLIDER
endif
OPTIONS += -DMAX_HISTORY=4
CFLAGS = ${OPTIONS} -W -Wall -g

lifegame : ${OBJS} Makefile
	cc -o lifegame ${OBJS} ${LDFLAGS}

clean :
	rm *.o

tags : ${SRCS} ${HEADS} Makefile
	ctags ${SRCS} ${HEADS}

main.o : main.c Structures.h Initialize.h Run.h Finalize.h Makefile
Run.o : Run.c Structures.h Run.h Step.h Output.h  Makefile
Initialize.o : Initialize.c Structures.h Initialize.h Makefile
Finalize.o : Finalize.c Structures.h Finalize.h Makefile
Step.o : Step.c Structures.h Step.h Finalize.h Initialize.h Makefile
Output.o : Output.c Structures.h Makefile
GenerateInitialState_Random.o : GenerateInitialState_Random.c GenerateInitialState.h Makefile
GenerateInitialState_Preset.o : GenerateInitialState_Preset.c GenerateInitialState.h Makefile
