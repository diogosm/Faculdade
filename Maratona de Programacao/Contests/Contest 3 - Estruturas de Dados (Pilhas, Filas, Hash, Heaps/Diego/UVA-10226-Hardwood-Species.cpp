#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <map>

using namespace std;

int main () {

	string str;
	int i, t, total;

	cin >> t;
	while (t-- > 0) {
		map<string, float> h;
		vector<string> v;

		total = 0;
		do {
			getline(cin, str);
		} while (str[0] == '\0');

		do {
			if (h.find(str) == h.end())
				v.push_back(str);
			h[str]++;
			total++;
			getline(cin, str);
		} while (str[0] != '\0');

		sort(v.begin(), v.end());
		cout << fixed;
		for (i = 0; i < v.size(); i++)
			cout << v[i] << " " << setprecision(4) << (h[v[i]]*100)/total << endl;

		if (t > 0) cout << endl;
	}

	return 0;
}
