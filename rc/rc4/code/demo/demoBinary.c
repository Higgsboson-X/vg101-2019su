#include <stdio.h>

int main() {

	// x = 0...0101011 in binary;
	int x = 43;
	printf("%d %d %d\n", ~x, x << 2, x >> 2);

	unsigned int y = 43;
	y = ~y;

	int z = (y > 44) ? 1 : 0;
	printf("%d\n", z);

	printf("y printed as signed integer: %d\n", y);
	printf("y printed as unsigned integer: %u\n", y);

	return 0;

}