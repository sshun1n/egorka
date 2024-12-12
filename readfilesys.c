#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(STDERR_FILENO, "Usage: ./program <filename>\n", 28);
        	return 1;
	}

	int file = open(argv[1], O_RDONLY);
	if (file == -1)
		{
		perror("Error while opening file");
		return 1;
	}

	char buff[BUFFER_SIZE];
	ssize_t bytes;

	while((bytes = read(file, buff, BUFFER_SIZE)) > 0)
	{
		if (write(STDOUT_FILENO, buff, bytes) != bytes)
		{
			perror("Error while writing");
			close(file);
			return 1;
		}
	}

	if (bytes == -1)
	{
		perror("Error while reading");
	}

	close(copy);
	close(file);
	return 0;
}
