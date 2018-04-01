#include <stdio.h>
#include <math.h>

int main () {

	int n, t = 1, i;
	int v[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192};

	while (1) {
		scanf("%d", &n);
		if (n < 0) break;
		if (n == 1)
			printf("Case %d: 0\n", t++);
		else {
			for (i = 0; i <= 13; i++)
				if (v[i] >= n) break;
			printf("Case %d: %d\n", t++, i);
		}
	}

	return 0;
}
