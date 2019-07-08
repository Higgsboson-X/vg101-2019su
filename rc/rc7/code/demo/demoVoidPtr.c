#include <stdio.h>

int main() {

	int a = 10;
	char b = 'a';

	void* p = &a;
	printf("a = %d, ", *(int*)p);
	p = &b;
	printf("b = %c\n", *(char*)p);

	int c[5] = {1, 2, 3, 4, 5};
	p = &c;
	p += 2 * sizeof(int);
	printf("%d\n", *(int*)p);

	return 0;

}