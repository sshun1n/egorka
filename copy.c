#include <stdio.h>

#define BUFFER_SIZE 1

int copy(int argc, char *argv[])
{
	if (argc != 3)
	{
		perror("Error: missing arguments <filename>");
	}

        FILE *file = fopen(argv[1], "r");
	FILE *copy = fopen(argv[2], "w");
        if (file == NULL || copy == NULL)
        {
                perror("Error: while opening files");
                return 1;
        }

	char buff[BUFFER_SIZE];
	size_t bytes;

	while ((bytes = fread(buff, 1, BUFFER_SIZE, file)) > 0)
    	{
        	fwrite(buff, 1, bytes, copy);
    	}

	if (ferror(file) || ferror(copy))
	{
		perror("Error: while reading files");
		return 1;
	}

        fclose(copy);
        fclose(file);
        return 0;
}
