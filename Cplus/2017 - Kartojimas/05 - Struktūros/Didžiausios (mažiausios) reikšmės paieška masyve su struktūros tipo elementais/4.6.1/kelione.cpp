#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;

struct etapai {
	string pavadinimas;
	int t;
	string nr[10];
	int kv[10], km[10];
} E[10];
int n;

void Skaito();
void Raso();

int main() {
	Skaito();
	return 0;
}

void Skaito() {
	ifstream fd("Duomenys.txt");
	char a[20];
	fd >> n;
	cout << n << endl;
	for(int i = 1; i <= n; i++) {
		fd.ignore(80, '\n');
		fd.get(a, 20);
		E[i].pavadinimas = a;
		fd >> E[i].t;
		cout << E[i].pavadinimas << "   " << E[i].t << endl;
		for(int z = 1; z <= E[i].t; z++) {
			fd.ignore();
			fd.get(a, 15);
			E[i].nr[z] = a;
			fd >> E[i].kv[z] >> E[i].km[z];
			cout << E[i].nr[z] << "  " << E[i].kv[z] << " " << E[i].km[z] << endl;
		}
	}
}
