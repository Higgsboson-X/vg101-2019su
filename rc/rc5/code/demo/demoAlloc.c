#include <stdio.h>
#include <stdlib.h>

typedef struct Complex {
	int real;
	int imag;
} complex_t;

int main() {

	complex_t* p1 = malloc(6 * sizeof(*p1));
	int i;
	for (i = 0; i < 6; i++) {
		p1[i].real = i;
		p1[i].imag = i;
	}
	puts("-------\n");
	for (i = 0; i < 6; i++) {
		printf("%d + %di\n", p1[i].real, p1[i].imag);
	}
	printf("p1: %p, &p1: %p\n", p1, &p1);

	complex_t* p2 = realloc(p1, 10 * sizeof(*p2));
	puts("-------\n");
	if (p2) {
		p2[6] = (complex_t){-6, -6};
		p2[7] = (complex_t){-7, -7};
		for (i = 0; i < 10; i++) {
			printf("%d + %di\n", p2[i].real, p2[i].imag);
		}
		printf("p2: %p, &p2: %p\n", p2, &p2);
	}

	complex_t* p3 = realloc(p2, 2 * sizeof(*p3));
	puts("-------\n");
	if (p3) {
		for (i = 0; i < 2; i++) {
			printf("%d + %di\n", p3[i].real, p3[i].imag);
		}
		printf("p3: %p, &p3: %p\n", p3, &p3);
	}

	puts("-------\n");
	for (i = 0; i < 6; i++) {
		printf("%d + %di\n", p1[i].real, p1[i].imag);
	}
	puts("-------\n");
	for (i = 0; i < 10; i++) {
		printf("%d + %di\n", p2[i].real, p2[i].imag);
	}
	puts("-------\n");
	for (i = 0; i < 2; i++) {
		printf("%d + %di\n", p3[i].real, p3[i].imag);
	}

	printf("%p %p %p\n", p1, p2, p3);

	// free(p1);
	// free(p2);
	free(p3);

}