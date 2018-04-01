#include <iostream>
#include <string>
#include <map>

using namespace std;

int main () {

	int i;
	string str;

	while (1) {
		if (!getline(cin, str)) break;

		map<string, string> h;

		while (1) {
			string str1, str2;
			if (str[0] == '\0') break;

			for (i = 0; str[i] != ' '; i++)
				str1.push_back(str[i]);

			for (i++; i < str.size(); i++)
				str2.push_back(str[i]);

			h[str2] = str1;
			getline(cin, str);
		}

		string str2;
		while (1) {
			getline(cin, str2);
			if (str2[0] == '\0') break;
			if (h.find(str2) == h.end())
				cout << "eh" << endl;
			else
				cout << h[str2] << endl;
		}
	}

	return 0;
}
