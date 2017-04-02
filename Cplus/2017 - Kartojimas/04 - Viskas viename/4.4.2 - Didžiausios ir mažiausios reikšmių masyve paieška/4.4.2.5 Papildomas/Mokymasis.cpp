#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;

int n, ZP[10], ZI[10], DN[10];

void Skaito();
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
    fd >> n;
    for(int i = 1; i <= n; i++) fd >> ZP[i] >> ZI[i] >> DN[i];
    fd.close();
}

int Didziausias(int a[]) {
    int d = 0, x = 0;
    for(int i = 1; i <= n; i++) if(a[i] > d) d = a[i], x = i;
    return x;
}

int Maziausias(int a[]) {
    int x = n-1, m = a[n-1];
    for(int i = 1; i <= n; i++) if(a[i] < m) x = i, m = a[i];
    return x;
}

void Raso() {
    ofstream fr("Rezultatai.txt");
    int x;
    x = Didziausias(ZI);
    fr << ZI[x];
    for(int i = 1; i <= n; i++) if(ZI[i] == ZI[x]) fr << " " << DN[i];
    fr << endl;
    x = Maziausias(ZP);
    fr << ZP[x];
    for(int i = 1; i <= n; i++) if(ZP[i] == ZP[x]) fr << " " << DN[i];
    fr.close();
}
