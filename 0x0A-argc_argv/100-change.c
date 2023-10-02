#include <stdio.h>
#include <stdlib.h>

/**
* main - prints minimum number of coins to make change for an amount of money.
* @argc: number of arguments
* @argv: arguments themselves
* Return: 1 on error, 0 on success
*/
int main(int argc, char *argv[])
{
	int money, coins, denominations[5], num_denominations, i;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	money = atoi(argv[1]);

	if (money < 0)
	{
		printf("0\n");
		return (0);
	}

	denominations[0] = 25;
	denominations[1] = 10;
	denominations[2] = 5;
	denominations[3] = 2;
	denominations[4] = 1;

	num_denominations = sizeof(denominations) / sizeof(denominations[0]);
	/*
	* formula above calculates number of denominations available. Here it is 5
	*/

	coins = 0;
	for (i = 0; i < num_denominations; i++)
	{
		coins += money / denominations[i];
		money %= denominations[i];
	}

	printf("%d\n", coins);
	return (0);
}
