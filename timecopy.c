#include <stdio.h>
#include <time.h>

int copy(int argc, char *argv[]);

int main(int argc, char *argv[])
{

	for (int i = 0; i < 1000; i++)
	{
		copy(argc, argv);
	}

	return 0;
}
