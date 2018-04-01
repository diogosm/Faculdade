#include <iostream>
#include <cmath>
#include <cfloat>
#include <string>

using namespace std;

typedef unsigned int uint;

bool comp_double(double a, double b) {

	return (fabs(a - b) <= DBL_EPSILON);
}

int main(int argc, char **argv) {

	uint n;
	cin >> n;

	const double p1[2] = {52.5, 3.66};
	const double p2[2] = {52.5, -3.66};
	
	double bx, by;
	double gx, gy, r;

	for (uint i = 0; i < n; ++i) {
		string temp_string;
		getline(cin, temp_string);

		cin >> bx >> by >> gx >> gy >> r;

		if (comp_double(by - p1[1], 0.0) || comp_double(by - p2[1], 0.0)) {
			cout << "No goal..." << endl;
			continue;
		}

		double m1 = (by - p1[1]) / (bx - p1[0]);
		double m2 = (by - p2[1]) / (bx - p2[0]);
		
		double d1 = fabs(m1 * gx - gy - m1 * bx + by) / sqrt(m1 * m1 + 1);
		double d2 = fabs(m2 * gx - gy - m2 * bx + by) / sqrt(m2 * m2 + 1);

		if (d1 > r || d2 > r) {
			cout << "Goal!" << endl;
		}
		else {
			cout << "No goal..." << endl;
		}
	}

	return 0;
}

