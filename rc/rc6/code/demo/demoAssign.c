#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	char s1[10];
	// s1 = "hello";
	char* p1 = s1;
	printf("%p %p %p\n", s1, &(s1[0]), p1);
	p1 = "hello\0";
	puts(s1);
	puts(p1);
	printf("%p %p %p\n", s1, &(s1[0]), p1);

	// char s2[];
	// s2 = "hello";
	// puts(s2);

	char* s3 = malloc(10 * sizeof(char));
	char* s4 = s3;
	s3 = "hello";
	puts(s3);
	free(s4);
	// free(s3);

	return 0;

}
