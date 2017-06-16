#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;
void Skaito(int & a, int & b); // a - ilgis, b - plotis
void Raso(int a, int b);
string Sesioliktainis(int ind); // ind - kodo vieta masyve
char Konvertuoti(int sk); // sk - desimtainis skaicius
int rr[10001],gg[10001], bb[10001]; // rr - r komponentë, gg - g komponentë, bb - b komponentë

int main() {
    int a, b; // a - ilgis, b - plotis
    Skaito(a, b); // Nuskaitome duomenis ið failo
    Raso(a, b); // Áraðome rezultatus á failà
    return 0;
}

void Skaito(int & a, int & b) {
    ifstream fd("U1.txt");
    fd >> a >> b;
    for(int i = 1; i <= a*b; i++) {
        fd >> rr[i] >> gg[i] >> bb[i];
    }
}

char Konvertuoti(int sk) {
    char kodas;
    if(sk == 10) kodas = 'A';
    else if(sk == 11) kodas = 'B';
    else if(sk == 12) kodas = 'C';
    else if(sk == 13) kodas = 'D';
    else if(sk == 14) kodas = 'E';
    else if(sk == 15) kodas = 'F';
    return kodas;
}
// jei skaicius maziau tai tada pats suformatuoji, jei ne tai naudoji f-ja
string Sesioliktainis(int ind) {
    char skaicius[6]; string skaiciusstring;
    skaicius[0] = rr[ind] > 9 ? Konvertuoti(rr[ind] / 16) : rr[ind];
    skaicius[1] = rr[ind] > 9 ? Konvertuoti(rr[ind] % 16) : rr[ind];
    skaicius[2] = gg[ind] > 9 ? Konvertuoti(gg[ind] / 16) : gg[ind];
    skaicius[3] = gg[ind] > 9 ? Konvertuoti(gg[ind] % 16) : gg[ind];
    skaicius[4] = bb[ind] > 9 ? Konvertuoti(bb[ind] / 16) : bb[ind];
    skaicius[5] = bb[ind] > 9 ? Konvertuoti(bb[ind] % 16) : bb[ind];
    skaiciusstring = skaicius;
    return skaiciusstring;
}

void Raso(int a, int b) {
    ofstream fr("U1rez.txt");
    for(int i = 1; i <= a; i++) {
        for(int z = 1; z <= b; z++) {
            fr << Sesioliktainis(z) << ";";
        }
        fr << endl;
    }
}
