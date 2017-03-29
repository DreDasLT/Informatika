#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;

const int CMax = 1000;
int s, m, seka[CMax], z;

void Skaityti();
void Spausdinti();
int Ieskoti(int skaicius);
void Iterpti(int indeksas, int skaicius);

ifstream fd("Duomenys.txt");
ofstream fr("Rezultatas.txt");

int main()
{
    for(int i=0; i<=CMax;i++) seka[i] = 0;
    cout << "Kokiu skaiciu papildyti? ";
    cin >> m;
    Skaityti();
    Spausdinti();
    z = Ieskoti(m);
    if(z != -1) {
        fr << "Skaiciaus " << m << " indeksas masyve " << z << endl;
        Iterpti(z, m);
    } else {
        Iterpti(s, m);
    }
    Spausdinti();
    return 0;
}

void Skaityti() {
    fd >> s;
    for(int i = 0; i < s; i++) {
        fd >> seka[i];
    }
}

void Spausdinti() {
    fr << "Skaiciu seka" << endl;
    fr << "-------------" << endl;
    for(int i = 0; i < s; i++) {
        fr << seka[i] << "  ";
        if(seka[i] != seka[i+1]) {
            fr << endl;
        }
    }
    fr << "-------------" << endl;
}

int Ieskoti(int skaicius) {
    for(int i = 0; i<s;i++) {
        if(seka[i] == skaicius) {
            return i;
        }
    }
    return -1;
}

void Iterpti(int indeksas, int skaicius) {
    s++;
    if(indeksas+1 == s) {
        seka[indeksas] = skaicius;
    } else {
        for(int i = s; i > indeksas;i--) {
            seka[i+1] = seka[i];
        }
    }
}
