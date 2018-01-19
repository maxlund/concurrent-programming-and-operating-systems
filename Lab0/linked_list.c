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
    while (first->next != NULL) 
	first = first->next;

    first->next = (struct list_item*)malloc(sizeof(struct list_item));
    first->next->value = x;
}

void prepend(struct list_item *first, int x)
{
    struct list_item *n = (struct list_item*)malloc(sizeof(struct list_item));
    n->next = first->next;
    first->next = n;
    n->value = x;
}

void print(struct list_item *first)
{
    while (first->next != NULL)
    {
	first = first->next;
	printf("%d ", first->value);
    }
    printf("\n");
}

void input_sorted(struct list_item *first, int x)
{
    if (first->next == NULL) 
    {
	prepend(first, x);
    }
    else 
    {
	if (first->next->value > x)
	{
	    struct list_item *n = (struct list_item*)malloc(sizeof(struct list_item));
	    n->next = first->next;
	    n->value = x;
	    first->next = n;
	}
	else
	{
	    input_sorted(first->next, x);
	}
    }
}
void clear(struct list_item *first)
{
    while (first->next != NULL)
    {
	struct list_item* to_free = first->next;
	first = first->next;
	free(to_free);
    }
}

int main( int argc, char ** argv)
{
    struct list_item root;
    root.value = -1; /* This value is always ignored */
    root.next = NULL;

    // test append
    append(&root, 10);
    append(&root, 20);
    append(&root, 30);
    append(&root, 2);
    print(&root); // should print 10, 20, 30, 2

    // test prepend
    prepend(&root, 8);
    prepend(&root, 5);
    print(&root); // should print 5, 8, 10, 20, 30, 2

    // test input_sorted
    input_sorted(&root, 25);
    input_sorted(&root, 9);
    input_sorted(&root, 1);
    input_sorted(&root, 100);
    print(&root); // should print 1, 5, 8, 9, 10, 20, 25, 20, 2, 100

    /*  total heap usage: 10 allocs, 10 frees 
	All heap blocks were freed -- no leaks are possible */
    clear(&root);
}

