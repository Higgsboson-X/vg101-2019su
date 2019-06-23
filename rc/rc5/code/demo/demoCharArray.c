#include <stdio.h>

int main() {

	char s1[20] = "Hello, world.";

	char s2[20];

	int i;
	for (i = 0; i < 5; i++) {
		s2[i] = s1[i];
	}

	// s2[i] = '\0';
	puts(s2);

	return 0;

}