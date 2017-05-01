#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;

int n, k, ls[20], lk[20];

void Skaito();
int Truksta(int x, int a[], int b[]);
int Didziausias(int a[]);
int Maziausias(int a[]);
void Raso();

int main() {
	Skaito();
	Raso();
	return 0;
}
void Skaito() {
	ifstream fd("Duomenys.txt");
	fd >> n >> k;
	int x;
	for(int i = 0; i < 11; i++) ls[i] = i, lk[i] = 0;
	for(int i = 0; i < k; i++) fd >> x, fd >> lk[x];
	fd.close();
}
int Truksta(int x, int a[], int b[]) {
    for(int i = 1; i <= k; i++) if(a[i] == x) return n - b[i];
    return n;
}
int Didziausias(int a[]) {
    int d = 0, x = 0;
    for(int i = 0; i < 11; i++) if(a[i] > d) d = a[i], x = i;
    return x;
}
int Maziausias(int a[]) {
    int x = 10, m = a[10];
    for(int i = 0; i < 11; i++) if(a[i] < m) x = i, m = a[i];
    return x;
}
void Raso() {
	ofstream fr("Rezultatai.txt");
	int x = Truksta(Maziausias(lk), ls, lk);
	fr << x;
	for(int i = 0; i < 11; i++) if(lk[i] == n - x) fr << " " << i;
	fr << endl;
	x = Truksta(Didziausias(lk), ls, lk);
	fr << x;
	for(int i = 0; i < 11; i++) if(lk[i] == n - x) fr << " " << i;
	fr.close();
}
