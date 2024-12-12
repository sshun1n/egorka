#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int a_flag = 0, b_flag = 0, c_flag = 0;
    	char *b_arg = NULL;

	if (argc == 1)
	{
		printf("\x1B[31mError:\x1B[0m missing options\n");
	}

    	for (int i = 1; i < argc; i++){
        if (argv[i][0] == '-') {
        for (int j = 1; argv[i][j] != '\0'; j++) {
                switch (argv[i][j]) {
                	case 'a':
                        	a_flag = 1;
                        	break;
                    	case 'b':
                        	b_flag = 1;

                        	if (argv[i][j + 1] != '\0')
				{
                            		b_arg = &argv[i][j + 1];
                        	}
				else if (i + 1 < argc)
				{
                            		b_arg = argv[++i];
                        	}
				else
				{
                            		printf("\x1B[31mError:\x1B[0m option '-b' require an argument\n");
                            		return 1;
                        	}
                        	j = strlen(argv[i]) - 1;
                        	break;
                    	case 'c':
                        	c_flag = 1;
                        	break;
                    	default:
                        	printf("\x1B[31mError:\x1B[0m unrecognized option'-%c'.\n", argv[i][j]);
                        	return 1;
                }
            }
        } else {
            printf("\x1B[31mError:\x1B[0m unexpected argument '%s'.\n", argv[i]);
            return 1;
        }
    }

    if (a_flag)
    {
        printf("\x1B[33mLOG:\x1B[0m option \x1B[32m'-a'\x1B[0m is active.\n");
    }
    if (b_flag)
    {
        printf("\x1B[33mLOG:\x1B[0m option \x1B[32m'-b'\x1B[0m is active with argument: \x1B[36m'%s'\x1B[0m\n", b_arg);
    }
    if (c_flag)
    {
        printf("\x1B[33mLOG:\x1B[0m option \x1B[32m'-c'\x1B[0m is active\n");
    }

    return 0;
}

