#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;
int n, k, f[30], sv[30], lk[30];
ifstream fd("Duomenys.txt");
ofstream fr("Rezultatai.txt");
void Skaito();
void Raso();
int Didz();
int main() {
    Skaito();
    Raso();
    return 0;
}

void Skaito() {
    fd >> n >> k;
    for(int i = 1; i <= n; i++) {
        fd >> f[i];
        sv[i] = f[i] / k;
        lk[i] = f[i] % k;
    }
}

void Raso() {
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += lk[i];
        fr << sv[i] << " " << lk[i] << endl;

    }
    sum = sum % k != 0 ? sum / k + 1 : sum / k;
    fr << sum  << endl;
    fr << sv[Didz()];
}

int Didz() {
    int didz = 0, ind = 0;
    for(int i = 1; i <= n; i++) {
        if(sv[i] > didz) didz = sv[i], ind = i;
    }
    return ind;
}
