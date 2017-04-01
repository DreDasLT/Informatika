#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
ifstream fd("Duomenys.txt");
ofstream fr("Rezultatai.txt");
int n, m[20], v[20];
double k[20], p[20];
void Skaito();
int Didziausias(int a[]);
int Maziausias(double a[]);
void Raso();
int main() {
    Skaito();
    Raso();
    return 0;
}

void Skaito() {
    fd >> n;
    for(int i = 1; i <= n; i++) fd >> m[i] >> v[i] >> k[i] >> p[i];
}

int Didziausias(int a[]) {
    int d = 0, x = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] > d) d = a[i], x = i;
    }
    return x;
}

int Maziausias(double a[]) {
    int x = n-1, maz = a[n-1];
    for(int i = 1; i <= n; i++) {
        if(a[i] < maz) x = i;
    }
    return x;
}

void Raso() {
    int x = 0;
    x = Didziausias(m);
    fr << m[x] << " " << v[x] << " " << fixed << setprecision(2) << k[x] << " " << p[x] << endl;
    x = Didziausias(v);
    fr << m[x] << " " << v[x] << " " << fixed << setprecision(2) << k[x] << " " << p[x] << endl;
    x = Maziausias(k);
    fr << m[x] << " " << v[x] << " " << fixed << setprecision(2) << k[x] << " " << p[x] << endl;
    x = Maziausias(p);
    fr << m[x] << " " << v[x] << " " << fixed << setprecision(2) << k[x] << " " << p[x] << endl;
}
