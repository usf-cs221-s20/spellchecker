
PROGNAME=spell-check
OBJS=main.o trie.o

# Enable debugging symbols
CFLAGS+=-g

# First we define our program and how to link it
#
${PROGNAME}: ${OBJS}
	${CC} -o $@ ${OBJS}

# Put some dependencies for .o files.
#
main.o: main.c trie.h
trie.o: trie.c trie.h

# "make clean" will clear out the compiled program, any object files,
# any core files, etc.
#
clean:
	rm -f ${PROGNAME} *.o *.core
