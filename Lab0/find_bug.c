#include <stdio.h>

int main(int argc, char ** argv)
{
    char str[] = "sihtgubed"; // 8 chars in array
    char *stri = &str[8]; // stri points to last char in array
    char *buf[9]; // char* array of size 9
    char **bufi, **bufend; // two pointers to char*
    bufi = buf; // bufi points to start of buf, i.e. points to the first char*
    bufend = &buf[9]; // bufend points to the last char* in buf

    while (bufi != bufend){ // fill buf with chars from str in reverse order
	*bufi = stri;
	bufi++;
	stri--;
    }

    while (bufi != buf){ 
	// (*bufi) -= 32;  this line is the bug, we try to decrement the char pointer by 32
	bufi--; // we decrement bufi to be the beginning of buf array again
    }

    while (bufi != bufend){ // we print the chars in buf
	printf("%c", **bufi);
	bufi++;
    }
}
