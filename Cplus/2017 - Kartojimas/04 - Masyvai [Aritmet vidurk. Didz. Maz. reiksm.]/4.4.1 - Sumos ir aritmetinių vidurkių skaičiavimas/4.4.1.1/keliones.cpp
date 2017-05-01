#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
ifstream fd("Duomenys.txt");
ofstream fr("Rezultatai.txt");
int n, ssk[10], vsk[10];
double sk[10], vk[10];
void Skaityti();
void Rasyti();
int Keleiviai(int a[]);
double Suma(double a[], int b[]);

int main() {
    Skaityti();
    Rasyti();
    return 0;
}

void Skaityti() {
    fd >> n;
    for(int i = 1; i <= n; i++) {
        fd >> ssk[i] >> vsk[i] >> sk[i] >> vk[i];
    }

}

void Rasyti() {
    fr << Keleiviai(ssk) << " " << Keleiviai(vsk) << endl;
    fr << fixed << setprecision(2) << Suma(sk, ssk) << " " << Suma(vk, vsk) << endl;
    fr << Suma(sk, ssk) / Keleiviai(ssk) << " " << Suma(vk, vsk) / Keleiviai(vsk) << endl;
}

int Keleiviai(int a[]) {
    int k = 0;
    for(int i = 1; i <= n; i++) {
        k += a[i];
    }
    return k;

}

double Suma(double a[], int b[]) {
    double s = 0;
    for(int i = 1; i <= n; i++) {
        s += a[i] * b[i];
    }
    return s;
}
