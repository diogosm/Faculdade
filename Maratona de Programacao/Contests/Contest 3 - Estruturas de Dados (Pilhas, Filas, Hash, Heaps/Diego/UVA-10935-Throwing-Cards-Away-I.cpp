#include <iostream>

using namespace std;

int main () {

	int i, j, n, v[200];

	while (1) {
		cin >> n;
		if (!n) break;

		for (i = 0; i < n; i++)
			v[i] = i+1;
		cout << "Discarded cards:";
		if (n > 1) cout << ' ';
		for (i = j = 0; j < n-1; j++, i += 2) {
			cout << v[i];
			if (j+1 < n-1) cout << ", ";
			v[n+j] = v[i+1];
		}
		if (n > 1) i--;
		cout << endl << "Remaining card: " << v[i]  << endl;
	}

	return 0;
}
