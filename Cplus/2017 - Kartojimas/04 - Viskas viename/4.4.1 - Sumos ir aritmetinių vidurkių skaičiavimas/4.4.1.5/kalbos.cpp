#include <fstream>
#include <iostream>
using namespace std;
ifstream fd("Duomenys.txt");
ofstream fr("Rezultatai.txt");
int k1[20], k2[20], k3[20], k4[20];
void Skaito();
int Suma();
void Raso();


int main() {
	Skaito();
	Raso();
	return 0;
}

void Skaito() {
	for(int i = 1; i <= 5; i++) {
		fd >> k1[i] >> k2[i] >> k3[i] >> k4[i];
	}
}

int Suma(int k[]) {
	int suma = 0;
	for (int i = 0; i <= 5; i++) {
		suma += k[i];
	}
	return suma;
}

void Raso() {
	int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
	s1 = Suma(k1);
	s2 = Suma(k2);
	s3 = Suma(k3);
	s4 = Suma(k4);
	fr << s1 << endl << s2 << endl << s3 << endl << s4 << endl;
}
