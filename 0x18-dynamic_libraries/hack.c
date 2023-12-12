static int currentLuckIndex;

void initializeLuckIndex(void)
{
	currentLuckIndex = 0;
}

int customRandomNumberGenerator(void)
{
	int luckyNumbers[] = {8, 8, 7, 9, 23, 74};

	const int numLuckyNumbers = sizeof(luckyNumbers) / sizeof(luckyNumbers[0]);

	initializeLuckIndex();

	int result = luckyNumbers[currentLuckIndex];

	currentLuckIndex = (currentLuckIndex + 1) % numLuckyNumbers;

	return (result + 9);
}
