#include <cstdio>
using namespace std;

typedef unsigned int uint;

struct Point {

	int x, y;
};

int main(int argc, char **argv) {

	uint t;
	scanf("%u", &t);
	
	uint n;

	for (uint cont = 0; cont < t; ++cont) {
		scanf("%u", &n);

		Point *vertexes = new Point[n];

		double A = 0.0;
		double cx = 0.0, cy = 0.0;

		for (uint i = 0; i < n; ++i) {
			scanf("%d %d", &vertexes[i].x, &vertexes[i].y);
		}

		for (uint i = 0; i < n - 1; ++i) {
			double temp = (double)(vertexes[i].x * vertexes[i + 1].y - vertexes[i + 1].x * vertexes[i].y);
			A += temp;
			cx += (double)(vertexes[i].x + vertexes[i + 1].x) * temp;
			cy += (double)(vertexes[i].y + vertexes[i + 1].y) * temp;
		}

		A += (double)(vertexes[n - 1].x * vertexes[0].y - vertexes[0].x * vertexes[n - 1].y);
		cx += (double)(vertexes[n - 1].x + vertexes[0].x) * (vertexes[n - 1].x * vertexes[0].y - vertexes[0].x * vertexes[n - 1].y);
		cy += (double)(vertexes[n - 1].y + vertexes[0].y) * (vertexes[n - 1].x * vertexes[0].y - vertexes[0].x * vertexes[n - 1].y);

		printf("%.2lf %.2lf\n", cx / (3.0 * A), cy / (3.0 * A));

		delete[] vertexes;
	}

	return 0;
}


