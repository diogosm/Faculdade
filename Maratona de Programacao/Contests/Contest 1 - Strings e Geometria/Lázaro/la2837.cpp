#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cfloat>
using namespace std;

inline bool doubleEqual(double a, double b) {

	return fabs(a - b) <= 0.01;
}

bool isTriangle(double a, double b, double c) {

	return (a < b + c) && (b < a + c) && (c < a + b);
}

char *class_side(double a, double b, double c) {

	if (doubleEqual(a, b) && doubleEqual(b, c)) {
		return "Equilateral";
	}
	else
	if (doubleEqual(a, b) || doubleEqual(a, c) || doubleEqual(b, c)) {
		return "Isosceles";
	}
	else {
		return "Scalene";
	}
}

char *class_angle(double a, double b, double c) {

	double cos_A = (b * b + c * c - a * a) / (2 * b * c);
	double cos_B = (a * a + c * c - b * b) / (2 * a * c);
	double cos_C = (a * a + b * b - c * c) / (2 * a * b);
	
	if (cos_A >= -0.03489949670250073 && cos_A <= 0.03489949670250108 ||
		cos_B >= -0.03489949670250073 && cos_B <= 0.03489949670250108 ||
		cos_C >= -0.03489949670250073 && cos_C <= 0.03489949670250108) {
		return "Right";
	}
	else
	if (cos_A < -0.03489949670250073 ||
		cos_B < -0.03489949670250073 ||
		cos_C < -0.03489949670250073) {
		return "Obtuse";
	}
	else {
		return "Acute";
	}
}

int main(int argc, char **argv) {

	double x1, y1;
	double x2, y2;
	double x3, y3;

	while (1) {
		if (scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3) != 6) {
			break;
		}

		double a = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		double b = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
		double c = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));

		if (isTriangle(a, b, c)) {
			printf("%s %s\n", class_side(a, b, c), class_angle(a, b, c));
		}
		else {
			printf("Not a Triangle\n");
		}
	}
	
	printf("End of Output\n");

	return 0;
}


