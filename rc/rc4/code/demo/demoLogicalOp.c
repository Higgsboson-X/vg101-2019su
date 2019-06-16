#include <stdio.h>

int main() {

	// x = 101011 in binary;
	int x = 43;
	printf("%d %d %d\n", ~x, x << 2, x >> 2);

/*
	unsigned int y = 43;
	y = ~y;
	int z = (y > 43) ? 1 : 0;
	printf("%d\n", z);

	printf("y printed in signed format: %d\n", y);
	printf("y printed in unsigned format: %u\n", y);
*/

	return 0;

}