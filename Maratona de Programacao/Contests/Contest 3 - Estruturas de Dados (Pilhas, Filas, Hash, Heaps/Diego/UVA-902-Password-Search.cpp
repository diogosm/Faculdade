#include <iostream>
#include <string>
#include <map>

using namespace std;

int main () {

	int i, n, max, pos;
	string str;
	map<string, int>::iterator it;

	while (cin >> n) {
		cin >> str;
		map<string, int> h;
		for (i = 0; i+n < str.size(); i++)
			h[str.substr(i, n)]++;
		max = 0;
		for (it = h.begin(); it != h.end(); it++)
			if (it->second > max) {
				max = it->second;
				str = it->first;
			}
		cout << str << endl;
	}

	return 0;
}
