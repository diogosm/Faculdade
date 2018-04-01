/* Password Search - problem: 843*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

typedef map<string, int> table2;

int calc_hash (string s) {

	int i;
	long long int h, k = 4;

	h = 0;
	for (i = 0; i < s.size(); i++)
		h = k*h + s[i] - 'a';
		
	return h%1403;
}

int main () {

	int i, j, t, h, n;
	string str;
	map<int, table2>::iterator it;
	table2::iterator it2;

	while (cin >> n) {
		map<int, table2> hash;
		cin >> str;
		for (i = 0; i+n <= str.size(); i++) {
			string s;
			for (j = i, t = 0; t < n; t++, j++)
				s.push_back(str[j]);
			h = calc_hash(s);
			if (hash.find(h) == hash.end() || hash[h].find(s) == hash[h].end())
				hash[h][s] = 0;
			else
				hash[h][s]++;
		}

		t = -1;
		for (it = hash.begin(); it != hash.end(); it++)
			for (it2 = (it->second).begin(); it2 != (it->second).end(); it2++)
				if (it2->second >= t) {
					t = it2->second;
					str = it2->first;
				}
				
		cout << str << endl;
	}

	return 0;
}
