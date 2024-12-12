#include <stdio.h>
#include <time.h>

int copysys(int argc, char *argv[]);

int main(int argc, char *argv[])
{

	for (int i = 0; i < 1000; i++)
	{
		copysys(argc, argv);
	}

	return 0;
}
