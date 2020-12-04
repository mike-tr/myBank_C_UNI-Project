# $@ the current target file
# $^ all sources listed for the current target
# $< the first (left-most) source for the current 

FLAGS = -Wall -g
CC = gcc
AR = ar

PROGRAM = myBank

OBJECTS_MAIN = main.o
MYOBJECTS = myBank.o main.o

run: $(PROGRAM)
	./$<
all: $(PROGRAM)

$(PROGRAM) : $(MYOBJECTS)
	gcc $(FLAGS) -o $@ $^

%.o : %.c myBank.h
	gcc $(FLAGS) -c $<

PHONY: run, clean, all

clean:
	rm -f *.o *.a *.so $(PROGRAM)

delo:
	rm -f *.o