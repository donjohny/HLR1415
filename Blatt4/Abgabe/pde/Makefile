# Common definitions
CC = gcc

# Compiler flags, paths and libraries
CFLAGS = -std=c99 -pedantic -Wall -Wextra -O0 -ggdb
LFLAGS = $(CFLAGS)
LIBS   = -lm

OBJS-SEQ = partdiff-seq.o askparams.o
OBJS-OPENMP = partdiff-openmp.o askparams.o

# Rule to create *.o from *.c
.c.o:
	$(CC) -c $(CFLAGS) $*.c

# Targets ...
all: partdiff-seq

partdiff-seq: $(OBJS-SEQ) Makefile
	$(CC) $(LFLAGS) -o $@ $(OBJS-SEQ) $(LIBS)

partdiff-openmp: $(OBJS-OPENMP) Makefile
	$(CC) $(LFLAGS) -fopenmp -o $@ $(OBJS-OPENMP) $(LIBS)

clean:
	$(RM) *.o *~

partdiff-seq.o: partdiff-seq.c Makefile

askparams.o: askparams.c Makefile

partdiff-openmp.o: partdiff-openmp.c
	$(CC) -c $(CFLAGS) -fopenmp partdiff-openmp.c
