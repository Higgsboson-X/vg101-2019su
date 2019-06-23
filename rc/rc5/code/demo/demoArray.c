#include <stdio.h>
#include <stdlib.h>

int main() {

	int a[10];
	int b[10] = {0};
	int c[10] = {1};

	int d[5] = {1, 2, 3, 4, 5};
	int e[]  = {1, 2, 3, 4, 5};

	int i;
	for (i = 0; i < 10; i++) {
		printf("%d %d %d\n", a[i], b[i], c[i]);
	}

}