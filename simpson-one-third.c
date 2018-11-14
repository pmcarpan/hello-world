#include <stdio.h>
#include <math.h>

#define EPSILON 1E-6

double f(double x) {
	return 2 * x;
}

double calc_result(double a, double b, double h) {
	int parity;
	double res = f(a) + f(b);

	for (a += h, parity = 0; a < b - h; a+=h, parity = (parity + 1)%2) {
		if (parity == 0) {
			res += 4 * f(a);
		}
		else {
			res += 2 * f(a);
		}
	}
	res = res * h / 3;

	return res;
}

int main(void) {
	int i = 0;
	double a, b, h, res, prev_res, error;

	printf("Enter a, b: "); scanf("%lf %lf", &a, &b);

	h = 0.1;

	printf("%12s%12s%12s%12s\n", "Iter. No.", "h", "result", "error");
	printf("------------------------------------------------\n");

	res = calc_result(a, b, h);

	printf("%12d%12lf%12lf%12s\n", i++, h, res, "");

	do {
		h /= 2;
		prev_res = res;
		res = calc_result(a, b, h);
		error = fabs(res - prev_res);
		printf("%12d%12lf%12lf%12lf\n", i++, h, res, error);
	} while (error > EPSILON);

	printf("\nFinal Integrand = %lf\n", res);

	return 0;
}