#include <stdio.h>
#include <math.h>

#define EPSILON 1E-4

double f(double x, double y) {
	return y - x;
}

int main(void) {
	int step = 0;
	double y, y_prev, x0, y0, h, x_final, error;

	printf("Enter x0, y0, x_final, h: "); scanf("%lf %lf %lf %lf", &x0, &y0, &x_final, &h);

	
	printf("%12s%12s%12s%12s%12s\n", "Step", "x(i)", "y(i)", "y(i+1)", "Error");
	printf("------------------------------------------------------------\n");

	while (x0 < x_final - EPSILON) {

		printf("%12d%12lf%12lf%12s%12s\n", step++, x0, y0, "", "");

		// calc y(i) upto precision
		
		y = y + h * f(x0, y0);
		printf("%12s%12s%12s%12lf%12s\n", "", "", "", y, "");

		do {
			y_prev = y;
			y = y0 + 0.5 * h * (f(x0, y0) + f(x0 + h, y_prev));
			error = fabs(y - y_prev);

			printf("%12s%12s%12s%12lf%12lf\n", "", "", "", y, error);
		} while ( error > EPSILON );

		// x += h;
		x0 += h;
		y0 = y;
	}

	printf("\ny(%lf) = %lf\n", x_final, y);

	return 0;
}