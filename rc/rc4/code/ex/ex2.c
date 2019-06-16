#include <stdio.h>
#include <math.h>

void ex2() {

	int n;
	scanf("%d", &n);

	int digits, num;
	float s;

	while (1) {
		digits = (int)floor(log(n + 1) / log(10)) + 1;
		num = n;
		s = 0.;
		while (num > 0) {
			s += pow((num % 10), digits);
			num -= (num % 10);
			num /= 10;
		}
		if ((int)s == n) {
			printf("The next Armstrong number is: %d.\n", n);
			return;
		}
		n++;
	}

}


int main() {

	ex2();

	return 0;

}