# Compiler
CC=gcc
# Compiler flags
CFLAGS=-g -Wall
# Linker
CCLINK=$(CC)
# Libararies
LIBS=
# Objects
OBJS=party.o voter.o main.o
#The rmove command
RM=rm -f

all: $(OBJS)
	$(CCLINK) -o Elect_MMT $(OBJS) $(LIBS)

party.o: party.c party.h
voter.o: voter.c voter.h
main.o: main.c party.h voter.h

# Deletes all the object files
clean:
	$(RM) *.o