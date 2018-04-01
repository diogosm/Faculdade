#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char **argv) {

	unsigned int n;
	string text;

	while (cin >> n >> text) {

		map<string, unsigned int> map_pwds;
		size_t s = text.size() - n + 1;
		for (register size_t i = 0; i < s; ++i) {
			++map_pwds[text.substr(i, n)];
		}

		map<string, unsigned int>::iterator it_pwd = map_pwds.begin();
		map<string, unsigned int>::iterator it;
		unsigned int max = it_pwd->second;
		for (it = map_pwds.begin(); it != map_pwds.end(); ++it) {
			if (it->second > max) {
				max = it->second;
				it_pwd = it;
			}
		}

		cout << it_pwd->first << endl;
	}

	return 0;
}


