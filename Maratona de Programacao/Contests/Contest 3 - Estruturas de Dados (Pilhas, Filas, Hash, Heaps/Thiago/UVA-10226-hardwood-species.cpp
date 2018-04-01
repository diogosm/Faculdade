#include <iostream>
#include <string>
#include <map>
#include <limits>
#include <iomanip>

using namespace std;

int main() {
	
	int testes;
	
	cin >> testes;
	
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
	for (int i = 0; i < testes; i++) {
		string linha;
		map<string, int> numeros;
		int quant = 0;
		
		getline(cin, linha);
		
		while (linha.length() > 0) {
			numeros[linha]++;
			quant++;
			
			getline(cin, linha);
		}
		
		cout << fixed << setprecision(4);
		
		for (map<string, int>::iterator it = numeros.begin(); it != numeros.end(); it++){
			cout << it->first << " " << static_cast<float> (it->second * 100) / quant << endl;
		}
		
		if (i < testes -1)
			cout << endl;
	}
	
	return 0;
}

