#include <stdio.h>
#include <stdlib.h>

typedef struct Input {

	int b, c, d;
} Input;

int main(int argc, char **argv) {

	unsigned int t;
	scanf("%u", &t);

	Input *vin;
	vin = (Input *)malloc(t * sizeof(Input));

	unsigned int i;
	for (i = 0; i < t; ++i) {
		scanf("%d %d %d", &vin[i].b, &vin[i].c, &vin[i].d);
	}

	int a;
	for (i = 0; i < t; ++i) {
		a = 2 * vin[i].c - vin[i].b - vin[i].d;
		printf("%d\n", a);
	}

	free(vin);

	return 0;
}

