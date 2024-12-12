#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *num = getenv("MYVAR");

	long number;
	char *end;

/*	if (argc == 1)
        {
                printf("\x1B[31mError:\x1B[0m missing option <var>\n");
        	return 1;
	}*/

	if ((number = strtol(num, &end, 10)) == 0)
	{
		printf("\x1B[31mError:\x1B[0m the env variable is not a number\n");
		return 1;
	}

	if (*end != '\0')
	{
        	printf("\x1B[31mError:\x1B[0m the env variable is not integer\n");
        	return 1;
    	}

	printf("\x1B[32mIncreased value:\x1B[0m %lu\n", number + 1);
	return 0;
}
