#!/bin/env make

CC      = gcc
OPT     = -O3
CFLAGS  = -Wall -g $(OPT) -fopenmp
LDFLAGS  = -Wall -g $(OPT) -fopenmp -lpthread -lm

OBJS = main.o pqsort/pqsort.o
PROG = main

all: $(PROG)

main: $(OBJS)

clean:
	rm -f $(OBJS) $(PROG)

