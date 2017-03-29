#include <fstream>
#include <iostream>
using namespace std;
ifstream fd("Duomenys.txt");
int z, d, dt = 0, a, ni = 0;
double dp;
int Neismoko(int ismoko, int ismoktiviso);

int main() {
    fd >> d >> z;
    for(int i = 1; i <= d; i++) {
        fd >> a;
        dt = a < z ? dt + 1 : dt;
        ni = a < z ? ni + Neismoko(a, d) : ni;
    }
    dp = ni / z;
    cout << dt << endl << ni << endl << dp << endl;
    return 0;
}

int Neismoko(int ismoko, int ismoktiviso) {
    return ismoktiviso - ismoko;
}
