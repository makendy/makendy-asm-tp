CC = gcc
CFLAGS = -Wall -Wextra -pedantic -g -m32
VPATH = 
LDLIBS = 

STROBJS = str.o
STRBIN= str


${STRBIN}: ${STROBJS}
	${CC} ${CFLAGS} $^ ${LDLIBS} -o $@


all: ${STRBIN}

clean:
	${RM} ${STROBJS} ${STRBIN}

.PHONY: clean all ${STRBIN}