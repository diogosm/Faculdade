#include <stdio.h>

#define MAX 32000
#define MAX2 100001

char mark1[MAX], mark2[MAX2];

int main () {

	long long int i, j, a, b, aux;
	int t;

	for (i = 3; i < MAX; i += 2)
		mark1[i] = '1';

	for (i = 3; i*i < MAX; i += 2)
		if (mark1[i])
			for (j = i*i; j < MAX; j += i)
				mark1[j] = 0;

	scanf("%d", &t);
	while (t-- > 0) {
		scanf("%lld %lld", &a, &b);
		for (i = 0; i <= b-a; i++)
			mark2[i] = '1';

		for (i = 3; i*i <= b; i += 2)
			if (mark1[i]) {
				aux = a/i;
				aux *= i;
				if (aux == 0) j = i+i;
				else j = (aux == a) ? aux : aux+i;
				for (; j <= b; j += i)
					mark2[j-a] = 0;
			}

		if (a == 1) mark2[0] = 0;
		if (a <= 2 && b >= 2) printf("2\n");

		for (i = 0; i <= b-a; i++)
			if (mark2[i] && (a+i)&1)
				printf("%lld\n", a+i);
		if (t)
			printf("\n");
	}

	return 0;
}
