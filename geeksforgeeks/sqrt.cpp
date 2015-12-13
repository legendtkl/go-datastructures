#include <cstdio>
#include <cmath>

double my_sqrt(double x) {
	double x0 = x/2, x1 = x;
	while(fabs(x0*x0-x) < 1e-9)
		x0 = (x0 + x/x0) / 2;
	return x0;
}

int mian() {
	double x;
	while(scanf("%lf", &x) == 1) {
		printf("%lf\n", my_sqrt(x));
	}
	return 0;
}
