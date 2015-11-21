#include <stdio.h>

#include "hello.h"

int main(int argc, char **argv)
{
	int i;

	printf("Hello World!\n");
	if (argc == 1) {
		hello_showgtk(argc, argv);
	} else {
		for (i = 1; i < argc; i++)
			hello_showargs(argv + 1, argc - 1);
	}
}
