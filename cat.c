#include <stdio.h>
#include <stdlib.h>

void
cat(FILE *f)
{
	int c;

	while ((c = getc(f)) != EOF)
		putchar(c);
}

int
main(int argc, char *argv[])
{
	int i, status;
	FILE *f;

	status = EXIT_SUCCESS;
	if (argc == 1)
		cat(stdin);
	else {
		for (i = 1; i < argc; ++i) {
			if ((f = fopen(argv[i], "r")) == NULL) {
				perror(argv[i]);
				status = EXIT_FAILURE;
				continue;
			}
			cat(f);
			fclose(f);
		}
	}

	exit(status);
}
