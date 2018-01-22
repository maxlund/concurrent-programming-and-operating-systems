CC ?= gcc
CFLAGS ?= -g -Wall -Wextra -Wpedantic --std=c11

BINDIR = bin

PROGRAMS = ${BINDIR}/find_bug \
		   ${BINDIR}/linked_list

all: ${BINDIR} ${PROGRAMS} 

${BINDIR}:
	test -d ${BINDIR} || mkdir ${BINDIR}

${BINDIR}/find_bug: find_bug.c
	${CC} ${CFLAGS} $^ -o $@

${BINDIR}/linked_list: linked_list.c
	${CC} ${CFLAGS} $^ -o $@

clean:
	rm -rf ${BINDIR} *~
