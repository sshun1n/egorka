#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		perror("Error: missing argument <filename>\n");
		return 1;
	}

	int file = open(argv[1], O_RDONLY);
	if (file == -1)
	{
		perror("Error: while opening file\n");
		return 1;
	}

	if (lseek(file, 3, SEEK_SET) == -1)
	{
		perror("Error: while moving pointer\n");
		close(file);
		return 1;
	}

	char buff[6];
	ssize_t bytes = read(file, buff, 5);
	if (bytes == -1)
	{
		perror("Error: while reading file\n");
		close(file);
		return 1;
	}

	buff[bytes] = '\0';

	if (write(STDOUT_FILENO, buff, bytes) == -1)
	{
		perror("Error: while writing stdout\n");
	}

	close(file);
	return 0;
}
