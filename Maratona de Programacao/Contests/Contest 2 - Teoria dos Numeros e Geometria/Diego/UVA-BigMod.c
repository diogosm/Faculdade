#include <stdio.h>

long long int big_mod (long long int a, long long int b, long long int m) {

	long long int c, r;

	c = 0; r = 1;
	while (b > 0) {
		if (b & 1)
			r = (r*a) % m;
		b = b >> 1;
		a = (a*a) % m;
	}

	return r;
}

int main () {

	long long int a, b, m;

	while (scanf("%lld %lld %lld", &a, &b, &m) == 3)
		printf("%lld\n", big_mod(a,b,m));

	return 0;
}
