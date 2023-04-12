#include "ADTs/arraystack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define UNUSED __attribute__((unused))

int main(UNUSED int argc, UNUSED char *argv[]) {
	const Stack *st;
	char buf[BUFSIZ]; 
	/*
	BUFSIZ is a preprocessor macro defined in the standard C library stdio.h. 
	Its value is implementation-defined and represents the size of a buffer 
	used by the standard I/O library for file input/output operations.
	*/
	char *s;

	st = ArrayStack(0L, free);
	while (fgets(buf, sizeof buf, stdin) != NULL) {
		/*
		For each line of input, the code allocates memory for a duplicate 
		string s using the strdup function, which returns a pointer to a new 
		string that is a duplicate of the input string.
		*/
		char *s = strdup(buf);
		st->push(st, (void *)s);
	}
	while (st->pop(st, (void **)&s)) {
		printf("%s", s);
		free(s);
	}
	st->destroy(st);
	return EXIT_SUCCESS;
}