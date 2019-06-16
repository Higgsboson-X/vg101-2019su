#include <stdio.h>

int main() {

	int a = 1 + 1.5;
	double b = 3 / 2;
	double c = 3 / 2.0;
	char d = 'd';
	d += 1;

	printf("%d %f %f %c\n", a, b, c, d);

	return 0;

}