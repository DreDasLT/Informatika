#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
int rm, rv, rr, m[10], v[10], r[10], n;
double rk, k[10], s;
ifstream fd("Duomenys.txt");
ofstream fr("Rezultatai.txt");

void Skaito();
void Raso(int a, double s);
bool Tikrinti(int ai);
void Kiek(int & a, double & s);

int main() {
    int a = 0;
    double s = 0;
    Skaito();
    Raso(a, s);
    return 0;
}

void Skaito() {
    fd >> rm >> rv >> rr >> rk >> n;
    for(int i = 1; i <= n; i++) {
        fd >> m[i] >> v[i] >> r[i] >> k[i];
    }
}

bool Tikrinti(int ai) {
    if(m[ai] >= rm && v[ai] >= rv && r[ai] <= rr && k[ai] <= rk) return true;
    return false;
}

void Kiek(int & a, double & s) {
    for(int i = 1; i <= n; i++) {
        if(Tikrinti(i)) a++, s += k[i];
    }
}

void Raso(int a, double s) {
    Kiek(a, s);
    fr << a << " " << fixed << setprecision(2) << s << endl;
    for(int i = 1; i <= n; i++) {
        if(Tikrinti(i)) fr << i << " " << m[i] << " " << v[i] << " " << r[i] << " " << k[i] << endl;
    }
}
