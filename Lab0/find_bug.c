#include <stdio.h>

int main(int argc, char ** argv)
{
    char str[] = "sihtgubed"; // 8 chars in array
    char *stri = &str[8]; // stri points to last char in array
    char *buf[9]; // char* array of size 9
    char **bufi, **bufend; // two pointers to char*
    bufi = buf; // bufi points to start of buf, i.e. points to the first char*
    bufend = &buf[9]; // bufend points to char at buf[9] 
    while (bufi != bufend)
    { // fill buf with chars from str in reverse order
        *bufi = stri;
        bufi++;
        stri--;
    }

    int i = 0;
    while (bufi != buf)
    { 
        // we dereference the char* and decrement char value by 3, but if first pointed to is beyond char array, segfault?
        *(*--bufi) -= 32; // decrement by 32 after decrementing bufi instead
    }
    while (bufi != bufend)
    { // we print the chars in buf
        printf("%c", **bufi);
        bufi++;
    }
    printf("\n");
}
