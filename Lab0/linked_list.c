#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct list_item
{
    int value;
    struct list_item *next;
};

void append(struct list_item *first, int x)
{
    while (first->next != NULL) first = first->next;
    first->next = (struct list_item*)malloc(sizeof(struct list_item));
    first->next->value = x;
}

void prepend(struct list_item *first, int x)
{
    struct list_item *n = (struct list_item*)malloc(sizeof(struct list_item));
    n->next = first->next;
    first->next = n;
}

void print(struct list_item *first)
{
    while (first->next != NULL)
    {
	first = first->next;
	printf("%d", first->value);
    }
}

int main( int argc, char ** argv)
{
    struct list_item root;
    root.value = -1; /* This value is always ignored */
    root.next = NULL;

    // destructors / free ??
}
