#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	char* s = "1234+234i";

	char* p;
	float f = strtod(s, &p);
	float g = strtod(p, &p);
	char i = *p;

	printf("%f %f %c \n", f, g, i);
	
	return 0;

}