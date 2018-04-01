/* the idead is to use like an stack. The order always starts from 1 to n 
 * and it's necessary to reorganized it to respect the given order. But it's
 * and station, so, the coaches can go out right after they come, or they can
 * come and stay in the station, so, others can go out or stay.
 *
 * for this, a stack will be used and if the current coach is not the same as
 * in the order, it is put in the stack. When there're no more coaches, just
 * pop all the elements from the stack and see if the order is respect.
 */

 #include <stdio.h>

 int main () {
 
 	int i, j, n, order[1000], top, stack[1000];

	scanf("%d", &n);
	while (n) {
		while (1) {
			scanf("%d", &order[0]);
			if (!order[0]) break;

			for (i = 1; i < n; i++)
				scanf("%d", &order[i]);

			top = j = 0;
			for (i = 1; i <= n;) {
				if (top > 0 && stack[top-1] == order[j]) {
					top--; j++;
				}
				else if (order[j] == i) {
					j++; i++;
				}
				else
					stack[top++] = i++;
			}

			for (; j < n; j++, top--)
				if (stack[top-1] != order[j])
					break;

			if (top == 0) printf("Yes\n");
			else printf("No\n");
		}
		scanf("%d", &n);
		printf("\n");
	}
 
 	return 0;
 }
