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
int Didziausias(etapai E[], int i);

int main() {
	Skaito();
	Raso();
	return 0;
}

void Skaito() {
	ifstream fd("Duomenys.txt");
	char a[20];
	fd >> n;
	for(int i = 1; i <= n; i++) {
		fd.ignore(80, '\n');
		fd.get(a, 20);
		E[i].pavadinimas = a;
		fd >> E[i].t;
		for(int z = 1; z <= E[i].t; z++) {
			fd.ignore();
			fd.get(a, 15);
			E[i].nr[z] = a;
			fd >> E[i].kv[z] >> E[i].km[z];
		}
	}
	fd.close();
}

int Didziausias(etapai E[], int i) {
	int d = 0;
	for(int z = 1; z <= E[i].t; z++) {
		if(E[i].kv[z] * 60 + E[i].km[z] > E[i].kv[d] * 60 + E[i].km[d]) d = z;
	}
	return d;
}

void Raso() {
	ofstream fr("Rezultatai.txt");
	for(int i = 1; i <= n; i++) {
		fr << E[i].pavadinimas << " " << E[i].kv[Didziausias(E, i)] << " " << E[i].km[Didziausias(E,i)] << endl;
		fr << E[i].nr[Didziausias(E,i)] << endl;
	}
	fr.close();
}
