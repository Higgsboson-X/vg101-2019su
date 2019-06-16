#include <stdio.h>

int main() {

	int i = 0;
	while (i++ < 3) {
		printf("%d\n", i);
	}

	i = 0;
	do {
		printf("%d\n", i);
	} while (i++ < 3);

	return 0;

}