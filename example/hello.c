#include <stdlib.h>
#include <stdio.h>

#include "hello.h"

void
hello_showargs(char **args, int nargs)
{
	size_t i;

	for (i = 0; i < nargs; i++)
		printf("%s\n", args[i]);
}
