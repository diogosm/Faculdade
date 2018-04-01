#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int len = 0;

int main () {

	int n, i;

	while(1) {
		cin >> n;
		if(n == 42 || !cin) break;
		v.push_back(n);
		len++;
	}

	if (n == 42)
		for (i = 0; i < len; i++)
			cout << v[i] << endl;

	return 0;
}
