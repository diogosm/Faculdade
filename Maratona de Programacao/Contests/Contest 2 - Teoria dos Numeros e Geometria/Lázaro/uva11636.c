#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

	int n;
	unsigned int cont = 1;
	while (1) {
		scanf("%d", &n);
		if (n < 0) {
			break;
		}

		printf("Case %d: %.lf\n", cont, ceil(log10(n) / log10(2.0)));
		++cont;
	}

	return 0;
}


