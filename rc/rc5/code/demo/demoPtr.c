#include <stdio.h>

int main() {

	int* p;

	int v2 = 1;
	int* v1 = &v2;
	int v4;
	int** v5;

	p = v1;
	*p = v2;
	v4 = *p;
	v5 = &p;

	printf("v1 = %p, v2 = %d, v4 = %d, v5 = %p, *v5 = %p, **v5 = %d\n", v1, v2, v4, v5, *v5, **v5);

	// int* s;
	// *s = 4;
	// printf("%p, %d\n", s, *s);

	// int* a;
	int a[5] = {1, 2, 3, 4, 5};
	int* b = &(a[0]);
	printf("%d\n", a == b);

	b = a + 3;
	printf("%d %d\n", *b, a[3] == *(a + 3));

	return 0;

}