#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

typedef unsigned int uint;

int main(int argc, char **argv) {

	uint n;
	cin >> n;

	string esp;
	getline(cin, esp);
	getline(cin, esp);

	for (register uint i = 0; i < n; ++i) {

		map<string, uint> trees;
		string tree_name;
		uint count = 0;

		while (getline(cin, tree_name)) {
			if (tree_name != "") {
				++trees[tree_name];
			}
			else {
				break;
			}		
			++count;
		}

		for (map<string, uint>::iterator it = trees.begin(); it != trees.end(); ++it) {
			printf("%s %.4lf\n", it->first.c_str(), (double(it->second) / double(count)) * 100.0);
		}
		if (i + 1 < n) {
			fputc('\n', stdout);
		}
	}

	return 0;
}

