#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double approximate_pi(int n) {

	srand(time(NULL));
	int c = 0;
	double a, b;
	for (int i = 0; i < n; i++) {
		a = (double)rand() / RAND_MAX;
		b = (double)rand() / RAND_MAX;
		if (pow(a - 0.5, 2) + pow(b - 0.5, 2) < 0.25) {
			c++;
		}
	}

	return (double)c * 4. / n;

}

int main() {

	double appr = approximate_pi(1000000);
	printf("%lf\n", appr);

	return 0;

}
