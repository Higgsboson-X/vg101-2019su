#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	char s1[10] = "hello";
	char s2[] = "hello";

	char* s3 = malloc(10 * sizeof(char));
	memset(s3, 'a', 9);

	printf("%s\n%ld %s\n%s\n", s1, strlen(s2), s2, s3);
	printf("%p %p %p\n", s1, s2, s3);

	free(s3);

	return 0;

}
