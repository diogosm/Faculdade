#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char **argv) {

	vector<int> ns;

	while (1) {
		int n;
		cin >> n;
		if (n == 42) {
			break;
		}
		ns.push_back(n);
	}

	for (size_t i = 0; i < ns.size(); ++i) {
		cout << ns[i] << endl;
	}

	return 0;
}


