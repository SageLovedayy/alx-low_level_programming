#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int numbytes, i;
	char *ptr;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	numbytes = atoi(argv[1]);

	if (numbytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	ptr = (char *)main;

	for (i = 0; i < numbytes; i++)
	{
		if (i == numbytes - 1)
		{
			printf("%02hhx\n", ptr[i]);
			break;
		}

		printf("%02hhx ", ptr[i]);
	}

	return (0);
}
