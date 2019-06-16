#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MIN(x, y) (x < y) ? x : y
#define MAX(x, y) (x < y) ? y : x

// do not use global variables in your vg101 work;
// 3, 4, 5, 6, 7, 8, 9, 10, 15, 20, >= 100;
const double T95SQ[11] = {2.48, 1.59, 1.204, 1.05, 0.926, 0.834, 0.770, 0.715, 0.553, 0.467, 0.139};

typedef struct Result {

	int n;

	double mean;
	double sx;
	double deltaA;
	double deltaB;
	double t95sq;
	double u;
	double ur;

	char* var;
	char* unit;

} result_t;

result_t empty = {0, 0., 0., 0., 0., 0., 0., 0., "", ""};

// =========================================================================================================== //


double get_mean(double* data, int n) {

	int i;
	double sum = 0.;
	for (i = 0; i < n; i++) {
		sum += data[i];
	}

	return sum / n;

}


double get_sx(double* data, int n, double mean) {

	int i;
	double sum_sq = 0.;
	for (i = 0; i < n; i++) {
		sum_sq += pow(data[i] - mean, 2);
	}

	return sqrt(sum_sq / (n - 1));

}


double find_t95sq(int n) {

	int ind = (n <= 10) ? n - 3 : MIN(9 + (int)(MAX(0, n - 15) / 5), 10);

	return T95SQ[ind];

}


double round_digits(double x, int d) {

	double factor = pow(10, d);

	return round(x * factor) / factor;

}


// =========================================================================================================== //

// generating Latex code for uncertainty analysis;

result_t* calc_direct(FILE* fp) {

	// FILE* fp = fopen(filename, "r");
	if (!fp) {
		perror("File not opened.");
		return &empty;
	}

	int n, d;
	fscanf(fp, "%d %d", &n, &d);

	if (n <= 1) {
		perror("Single measurement.");
		return &empty;
	}

	double* data = malloc(n * sizeof(double));
	int i;
	for (i = 0; i < n; i++) {
		fscanf(fp, "%lf", &data[i]);
	}

	double mean = round_digits(get_mean(data, n), d);
	double sx = round_digits(get_sx(data, n, mean), d);
	double t95sq = find_t95sq(n);
	double deltaA = round_digits(sx * t95sq, d);

	double deltaB;
	fscanf(fp, "%lf", &deltaB);

	char* var = malloc(10 * sizeof(char));
	// fgets(var, sizeof(var), fp);
	fscanf(fp, "%s\n", var);

	char* unit = malloc(5 * sizeof(char));
	// fgets(unit, sizeof(unit), fp);
	fscanf(fp, "%s\n", unit);

	double u  = round_digits(sqrt(pow(deltaA, 2) + pow(deltaB, 2)), d);
	double ur = round_digits(u / mean, d - 1);

	// fclose(fp);

	free(data);

	result_t* result = malloc(sizeof(result_t));

	*result = (result_t){n, mean, sx, deltaA, deltaB, t95sq, u, ur, var, unit};

	return result;
	
}


void write_direct(result_t* result, FILE* fp, int indirect) {

	// FILE* fp = fopen(filename, "w");
	// mean;
	fprintf(fp, "The average value of measurement results is given by\n");
	fprintf(fp, "\\begin{align*}\n");
	fprintf(fp, "\\overline{{%s}} & = \\frac{1}{n}\\sum_{i=1}^{n}{%s}_i\\\\ \n", result->var, result->var);
	fprintf(fp, "               & = \\frac{1}{%d}\\sum_{i=1}^{%d}{%s}_i\\\\ \n", result->n, result->n, result->var);
	fprintf(fp, "               & \\approx %g\\ [\\mathrm{{%s}}]. \n", result->mean, result->unit);
	fprintf(fp, "\\end{align*}\n");
	// s_X;
	fprintf(fp, "Then we obtain\n");
	fprintf(fp, "\\begin{align*}\n");
	fprintf(fp, "s_{%s} & = \\sqrt{\\dfrac{1}{n-1}\\sum_{i=1}^{n}(x_i-\\overline{X})^2}\\\\ \n", result->var);
	fprintf(fp, "       & = \\sqrt{\\dfrac{1}{%d}\\sum_{i=1}^{%d}({%s}_i-%g)^2}\\\\ \n", result->n - 1, result->n, result->var, result->mean);
	fprintf(fp, "       & \\approx %g\\ [\\mathrm{%s}]. \n", result->sx, result->unit);
	fprintf(fp, "\\end{align*}\n");
	// delta_A;
	fprintf(fp, "The type-A uncertainty for $n = %d$ is given by\n", result->n);
	fprintf(fp, "\\begin{align*}\n");
	fprintf(fp, "\\Delta_A & = s_{%s} \\times \\frac{t_{0.95}}{\\sqrt{n}}\\\\ \n", result->var);
	fprintf(fp, "          & = %g \\times %g\\\\ \n", result->sx, result->t95sq);
	fprintf(fp, "          & \\approx %g\\ [\\mathrm{%s}].\n ", result->deltaA, result->unit);
	fprintf(fp, "\\end{align*}\n");
	// delta_B;
	fprintf(fp, "According to the resolution of the measurement device, we have $\\Delta_B = %g [%s]$. ", result->deltaB, result->unit);
	// u;
	fprintf(fp, "Therefore, the total uncertainty is calculated as\n");
	fprintf(fp, "\\begin{align*}\n");
	fprintf(fp, "u & = \\sqrt{\\Delta_A^2 + \\Delta_B^2}\\\\ \n");
	fprintf(fp, "  & = \\sqrt{%g^2 + %g^2} [\\mathrm{%s}]\\\\ \n", result->deltaA, result->deltaB, result->unit);
	fprintf(fp, "  & \\approx %g\\ [\\mathrm{%s}], \n", result->u, result->unit);
	fprintf(fp, "\\end{align*}\n");
	if (!indirect) {
		// u_r;
		fprintf(fp, "and the relative uncertainty is calculated as\n");
		fprintf(fp, "\\begin{align*}\n");
		fprintf(fp, "u_r = \\frac{u}{\\overline{%s}} \\times 100\\%% \\approx %g\\%%. \n", result->var, result->ur * 100);
		fprintf(fp, "\\end{align*}\n");
		// final representation;
		fprintf(fp, "\nThe final result is $$%s = %g \\pm %g\\ [\\mathrm{%s}], \\qquad u_r = %g\\%%.$$\n", result->var, result->mean, result->u, result->unit, result->ur * 100);
	}

	// fclose(fp);

}


void write_indirect() {}


// =========================================================================================================== //



int main() {

	int type;
	scanf("%d", &type);

	result_t* result;
	FILE* fp;

	switch (type) {
		case 0:
			fp = fopen("./files/data.txt", "r");
			result = calc_direct(fp);
			fclose(fp);
			fp = fopen("./files/latex.txt", "w");
			write_direct(result, fp, 0);
			fclose(fp);
			free(result->var);
			free(result->unit);
			free(result);
			break;
		case 1:
			write_indirect();
			break;
		default:
			break;
	}

	return 0;

}