#include <stdio.h>

int main() {

	int a = 0;
	float b = 0.;
	char c = 'a';
	char s[] = "string";

	int* pa = &a;
	float* pb = &b;
	char* pc = &c;
	char* ps = s;

	printf("int: %p\nfloat: %p\nchar: %p\nstring: %p\n", pa, pb, pc, ps);

	return 0;
	
}