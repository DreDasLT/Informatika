#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int CMax = 100;
int m, Monetos[CMax];

ifstream fd1("Duomenys1.txt");
ifstream fd2("Duomenys2.txt");
ofstream fr("Rezultatas.txt");

void Skaityti();
void Tvarkyti();
void Spausdinti();

int main() {
    Skaityti();
    Tvarkyti();
	return 0;
}

void Skaityti() {
    int s;
	fd1 >> m;
	fd2 >> s;
	for(int i = 1; i <= m; i++) fd1 >> Monetos[i];
	for(int i = m+1; i <= m+s; i++) fd2 >> Monetos[i];
	m += s;
}

void Tvarkyti() {
    int n = 0;
    for(int i = 1; i <= m; i++) {
        for(int z = 1; z <= m; z++) {
            if(Monetos[z] > Monetos[i]) {
                n = Monetos[i];
                Monetos[i] = Monetos[z];
                Monetos[z] = n;
            }
        }
    }
}

void Spausdinti() {
    for(int i = 1; i <= m; i++) fr << Monetos[i] << " ";
}
