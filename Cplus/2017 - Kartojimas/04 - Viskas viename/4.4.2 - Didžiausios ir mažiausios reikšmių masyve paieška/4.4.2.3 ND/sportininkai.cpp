#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
ifstream fd("Duomenys.txt");
ofstream fr("Rezultatai.txt");
int a, r, b, n, kcal[20];
double u[20], m[20];

void Skaito();
int Didziausias(double a[]);
int Maziausias(double a[]);
void Raso();

int main() {
    Skaito();
    Raso();
    return 0;
}

void Skaito() {
    fd >> a >> r >> b >> n;
    for(int i = 1; i <= n; i++) fd >> m[i] >> u[i] >> kcal[i];
}

int Didziausias(double a[]) {
    double d = 0.0; int x = 1;
    for(int i = 1; i <= n; i++) if(a[i] > d) d = a[i], x = i;
    return x;
}

int Maziausias(double a[]) {
    int x = n-1; double maz = a[n-1];
    for(int i = 1; i <= n; i++) if(a[i] < maz) x = i, maz = a[i];
    return x;
}

void Raso() {
    for(int i = 1; i <= n; i++) fr << i << " " << fixed << setprecision(0) << m[i] / (u[i]*u[i]) << endl;
    int x = 0;
    x = Didziausias(u);
    fr << x << " " << fixed << setprecision(2) << m[x] << " " << u[x] << " " <<  kcal[x] <<  setprecision(0) << " " << m[x] / (u[x]*u[x]) << endl;
    x = Maziausias(u);
    fr << x << " " << fixed << setprecision(2) << m[x] << " " << u[x] << " " <<  kcal[x] <<  setprecision(0) << " " << m[x] / (u[x]*u[x]) << endl;
    x = Maziausias(m);
    fr << x << " " << fixed << setprecision(2) << m[x] << " " << u[x] << " " <<  kcal[x] <<  setprecision(0) << " " << m[x] / (u[x]*u[x]) << endl;
    x = Didziausias(m);
    fr << x << " " << fixed << setprecision(2) << m[x] << " " << u[x] << " " <<  kcal[x] <<  setprecision(0) << " " << m[x] / (u[x]*u[x]) << endl;
    
}
