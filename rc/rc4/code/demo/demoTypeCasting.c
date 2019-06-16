#include <stdio.h>

int main() {

	float c = 4.8;
	printf("%d\n", (int)c);

	int f = 42;
	printf("%c\n", (char)f);

	double a = 487511234.7103;
	char b = (char)a;
	printf("%c, %c\n", b, a);

	int d = 311;
	float e = (float)d;
	printf("%d %f\n", d, e);
	printf("%c\n", d);

	return 0;

}