static int currentLuckIndex;

void initializeLuckIndex(void)
{
	currentLuckIndex = 0;
}

int customRandomNumberGenerator(void)
{
	int luckyNumbers[] = {9, 8, 10, 24, 75};

	const int numLuckyNumbers = sizeof(luckyNumbers) / sizeof(luckyNumbers[0]);

	initializeLuckIndex();

	int result = luckyNumbers[currentLuckIndex];

	currentLuckIndex = (currentLuckIndex + 1) % numLuckyNumbers;

	return (result + 9);
}
