#include <stdio.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
	if (argc != 2) {
		perror("Error: missing argument <filename>\n");
	}

	FILE *file = fopen(argv[1], "r");
	if (file == NULL) {
		perror("Error while opening the file\n");
        	return 1;
	}

	char buff[BUFFER_SIZE];
        size_t bytes;

        while ((bytes = fread(buff, 1, BUFFER_SIZE, file)) > 0) {
                if (fwrite(buff, 1, bytes, stdout) != bytes) {
			perror("Error: while writing from file\n");
			return 1;
		}
	}

        if (ferror(file)) {
                perror("Error: while reading files");
                return 1;
	}

	fclose(file);
	return 0;
}
