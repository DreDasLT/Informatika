#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;
///////////////////////////////////////////////
struct Degalines {
    string pav;
    double bk, dk;
} D[10];
///////////////////////////////////////////////
double b, d, m; int n;
///////////////////////////////////////////////
void Skaito();
void Raso();
double Islaidos(Degalines D[], int i, int t); // 1 - Benzinas 2 - Dujos
///////////////////////////////////////////////
int main() {
    Skaito();
    Raso();
    return 0;
}

void Skaito() {
    ifstream fd("Duomenys.txt");
    char a[15];
    fd >> b >> d >> m >> n;
    for(int i = 1; i <= n; i++) {
        fd.ignore();
        fd.get(a, 15);
        D[i].pav = a;
        fd >> D[i].bk >> D[i].dk;
    }
}

double Islaidos(Degalines D[], int i, int t) {
    double sum;
    if(t == 1) sum = (m / 100) * b * D[i].bk;
    else if(t == 2) sum = (m / 100) * d * D[i].dk;
    return sum;
}

void Raso() {
    ofstream fr("Rezultatai.txt");
    for(int i = 1; i <= n; i++) {
        fr << D[i].pav << Islaidos(D, i, 1) << " " << Islaidos(D, i, 2) << endl;
    }
}
