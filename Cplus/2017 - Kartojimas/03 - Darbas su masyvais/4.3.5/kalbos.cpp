#include <fstream>
#include <iostream>
using namespace std;
ifstream fd("Duomenys.txt");
ofstream fr("Rezultatas.txt");

void Skaityti(int (&kg)[100], int (&ks)[100], int & kalbos);
int Skaiciuoti(int kg[100], int ks[100], int grupe, int kalbos);
void Rezultatas(int kg[100], int ks[100], int kalbos);
int main() {
    int kg[100], ks[100], kalbos; // Kalbos grupe , Kalbos skaicius, isviso kalbu
    Skaityti(kg, ks, kalbos);
    Rezultatas(kg, ks, kalbos);
    return 0;
}

void Skaityti(int (&kg)[100], int (&ks)[100], int & kalbos) {
    int x = 0, a = 0, b = 1;
    while(!fd.eof()) {
        x++;
        if(a == 4) {
            a = 1;
            b++;
        } else a ++;
        fd >> ks[x];
        kg[x] = b;
    }
    kalbos = x;
}

int Skaiciuoti(int kg[100], int ks[100], int grupe, int kalbos) {
    int ats = 0;
    for(int i = 1; i < kalbos; i++) {
        if(grupe == kg[i]) {
            ats += ks[i];
        }
    }
    return ats;
}

void Rezultatas(int kg[100], int ks[100], int kalbos) {
    for(int i = 1; i <= 5; i++) {
        fr << Skaiciuoti(kg, ks, i, kalbos) << endl;
    }
}
