CC ?= gcc
CFLAGS ?= -g -Wall -Wextra -Wpedantic --std=c11

PROGRAMS = find_bug \
		   linked_list

all: ${PROGRAMS} 

find_bug: find_bug.c
	${CC} ${CFLAGS} $^ -o $@

linked_list: linked_list.c
	${CC} ${CFLAGS} $^ -o $@

clean:
	rm -f ${PROGRAMS} *~
