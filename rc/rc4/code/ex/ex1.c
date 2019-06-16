#include <stdio.h>

void ex1() {

	float num;
	int pos = 0, neg = 0;
	for (int i = 0; i < 5; i++) {
		scanf("%f", &num);
		if (num > 0) {
			pos++;
		}
		else if (num < 0) {
			neg++;
		}
	}

	printf("Number of postivie numbers: %d\n", pos);
	printf("Number of negative numbers: %d\n", neg);

}


int main() {

	ex1();

	return 0;

}