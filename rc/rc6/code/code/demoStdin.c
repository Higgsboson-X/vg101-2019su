#include <stdio.h>
#include <stdlib.h>

int main() {

	char s[50] = "hello, ";
	// scanf("%s", s + 7);
	fgets(s + 7, 20, stdin);

	puts(s);

	return 0;

}
