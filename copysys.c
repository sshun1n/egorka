#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1

int copysys(int argc, char *argv[])
{
        if (argc != 3)
        {
                write(STDERR_FILENO, "Error: missing argument <filename>\n", 35);
                return 1;
        }

        int file = open(argv[1], O_RDONLY);
	int copy = open(argv[2], O_WRONLY | O_CREAT, 0644);
        if (copy == -1 || file == -1)
        {
                perror("Error while opening files\n");
                return 1;
        }

        char buff[BUFFER_SIZE];
        ssize_t bytes;

        while((bytes = read(file, buff, BUFFER_SIZE)) > 0)
        {
                if (write(copy, buff, bytes) != bytes)
                {
                        perror("Error while writing\n");
                        close(file);
                        return 1;
                }
        }

        if (bytes == -1)
        {
                perror("Error while reading\n");
        }

        close(file);
        
}
