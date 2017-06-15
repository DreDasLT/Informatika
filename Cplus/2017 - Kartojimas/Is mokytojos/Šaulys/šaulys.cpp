#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
ofstream fr("Rezultatai.txt");
struct sauliai {
    string vard;
    double sk[10];
} S[10];
int n;

void Skaito();
void Raso();
void Burbulas();
double Vidurkis(int i);

int main() {
    Skaito();
    Burbulas();
    Raso();
    return 0;
}

void Skaito() {
    ifstream fd("Duomenys.txt");
    char a[20];
    fd >> n;
    fd.ignore();
    for(int i = 1; i <= n; i++) {
        fd.get(a, 20);
        S[i].vard = a;
        for(int z = 0; z < 10; z++) {
            fd >> S[i].sk[z];
        }
        fd.ignore();
    }
}

double Vidurkis(int i) {
    double sumkv = 0, sum = 0; int a = 9;
    for(int z = 0; z < 10; z++) {
        sumkv += S[i].sk[z] * a;
        sum += S[i].sk[z];
        a--;
    }
    return (double)sumkv/sum;
}

void Burbulas() {
    for(int i = 1; i <= n; i++) {
        for(int z = 1; z <= n; z++) {
            if(Vidurkis(i) > Vidurkis(z)) swap(S[i], S[z]);
        }
    }
}

void Raso() {
    for(int i = 1; i <= 3; i++) {
        cout << S[i].vard << Vidurkis(i) << endl;
    }
}
