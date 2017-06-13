#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;
////////////////////////////////
struct darzoves {
    string pav;
    double a, b, r;
} D[10];
////////////////////////////////
double ak, bk, rk; int n;
////////////////////////////////
void Skaito();
double Verte(int i, int t);
double Vanduo(int i);
void Raso();
////////////////////////////////
int main() {
    Skaito();
    Raso();
    return 0;
}
void Skaito() {
    ifstream fd("Duomenys.txt");
    char a[15];
    fd >> ak >> bk >> rk >> n;
    for(int i = 1; i <= n; i++) {
        fd.ignore();
        fd.get(a, 15);
        D[i].pav = a;
        fd >> D[i].a >> D[i].b >> D[i].r;
    }
}

double Verte(int i, int t) {
    double sum;
    if(t == 1) sum = D[i].a * ak;
    else if(t == 2) sum = D[i].b * bk;
    else if(t == 3) sum = D[i].r * rk;
    return sum;
}

double Vanduo(int i) {
    double sum = 100 - D[i].a - D[i].b - D[i].r;
    return sum;
}

void Raso() {
    ofstream fr("Rezultatai.txt");
    for(int i = 1; i <= n; i++) {
        fr << D[i].pav << Verte(i, 1) << " " << Verte(i, 2) << " " << Verte(i, 3) << " " << Vanduo(i) << endl;
    }
}
