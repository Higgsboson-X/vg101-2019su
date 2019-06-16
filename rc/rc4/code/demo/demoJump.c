#include <stdio.h>

int main() {

	int i = 0;
	printf("I am at position %d.\n", i);
	i++;

	goto end;
	printf("I am at position %d.\n", i);
	end:
		i++;
		printf("It all ends here, at position %d.\n", i);
	return 0;

	i++;
	printf("Unless it's here at position %d.\n", i);

}