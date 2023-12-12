static int val = 0;

int rand(void){
	int luck[] = {9, 8, 10, 24, 75};
	int i = val;

	val++;
	if (val >= 6)
		val = 0;

	return luck[i];
}
