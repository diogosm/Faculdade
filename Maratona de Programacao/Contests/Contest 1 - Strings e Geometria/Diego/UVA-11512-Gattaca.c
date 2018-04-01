/*
 * Main idea is to use suffix array.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

char str[MAX+1];
int tam;

int cmp (const void *a, const void *b) {

	int i, j, tam1, tam2;

	tam1 = *(int*)a; tam2 = *(int*)b;
	for (i = tam1, j = tam2; i < tam && j < tam; i++, j++) {
		if (str[i] < str[j])
			return -1;
		else if (str[i] > str[j])
			return 1;
	}

	if (i == tam) return -1;
	else return 1;
}

/* calculate the match from suffix strin i and i+1 */
int match (int st, int st2) {

	int i, j, k, f, aux;

	f = 0;
	for (i = st2, j = st; i < tam && j < tam; i++, j++) {
		if (str[i] == str[j])
			f++;
		else
			break;
	}

	return f;
}

int main () {

	int i, j, k, z, v[MAX], v2[MAX], t;
	int c, posf, aux, max;

	scanf("%d", &t);
	while (t-- > 0) {
		scanf("%s", str);
		tam = strlen(str);

		for (i = 0; i < tam; i++)
			v[i] = i;

		/* sort in lexicographical order */
		qsort(v, tam, sizeof(int), cmp);

		/* find LCP */
		j = k = z = -1;
		v2[0] = 0;
		for (i = 1; i < tam; i++) {
			v2[i] = match(v[i-1], v[i]);
			if (v2[i] > k) {
				k = v2[i];
				z = v[i];
			}
		}

		/* define the prefix strings in LCP */
		for (i = 0; i < tam-z; i++)
			v[i] = z+i;

		/* find the longest substring that repeats two or more times */
		max = 0;
		posf = -1;
		for (i = 0; i < tam-z; i++) {
			c = 0;
			for (j = 0; j < tam; j++) {
				for (aux = j, k = z; k <= v[i]; k++, aux++)
					if (str[aux] != str[k])
						break;
				if (k == v[i]+1)
					c++;
			}
			if (c >= 2 && ((v[i]-z) >= (v[i]-posf) || posf == -1)) {
				max = c;
				posf = v[i];
			}
		}

		if (max == 0)
			printf("No repetitions found!\n");
		else {
			for (i = z; i <= posf; i++)
				printf("%c", str[i]);
			printf(" %d\n", max);
		}

	}
	
	return 0;
}
