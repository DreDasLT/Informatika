#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct Mokiniai {
	string vardas;
	int korteles[11];
}A[10];

int n, k;

void Skaito();
void Raso();
int Skaiciuoti(Mokiniai A[], int sk, int i);

int main() {
	Skaito();
	Raso();
	return 0;
}

void Skaito() {
	ifstream fd("Duomenys.txt");
	char a[15];
	fd >> n >> k;
	fd.ignore(80, '\n');
	for(int i = 0; i < n; i++) {
		fd.get(a, 15);
		A[i].vardas = a;
		for(int j = 1; j <= k; j++) {
			fd >> A[i].korteles[j];
		}
		fd.ignore(80, '\n');
	}
	fd.close();
}

int Skaiciuoti(Mokiniai A[], int sk, int i) {
	int sum = 0;
    for(int j = 1; j <= k; j++) {
        if(A[i].korteles[j] == sk) sum++;
    }
	return sum;
}

void Raso() {
	ofstream fr("Rezultatai.txt");
	for(int i = 0; i < n; i++) {
		fr << A[i].vardas << " ";
		for(int j = 1; j <= k; j++) {
			fr << Skaiciuoti(A, j, i) << " ";
		}
		fr << endl;
	}
	fr.close();
}
