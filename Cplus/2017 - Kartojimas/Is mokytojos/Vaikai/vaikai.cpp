#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
//////////////////////
int n;
string pav[10000];
string var[10000];
char lyt[10000];
int m[10000], mm[10000], d[10000];
//////////////////////
void Skaito();
int Skaicius(char l);
int Populiariausias(char l[]); // l - lytis
void Kiekviena();
void Raso();

int main() {
    Skaito();
    Raso();
    return 0;
}

void Skaito() {
    ifstream fd("Duomenys.txt");
    char a[14];
    fd >> n;
    for(int i=1; i <= n; i++) {
        fd.ignore();
        fd.get(a, 14);
        pav[i] = a;
        fd.get(a, 13);
        var[i] = a;
        fd >> lyt[i] >> m[i] >> mm[i] >> d[i];
    }
}

int Skaicius(char l) {
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        if(lyt[i] == l) sum++;
    }
    return sum;
}

int Populiariausias(char l) {
    int sum[10000], ind, didz = 0;
    for(int i = 1; i <= n; i++) {
        for(int z = i+1; z <= n; z++) {
            if(lyt[i] == l && lyt[z] == l && var[i] == var[z]) sum[i]++;
        }
    }
    for(int i = 1; i <= n; i++) {
        if(sum[i] > didz && lyt[i] == l) didz = sum[i], ind = i;
    }
    return ind;
}
void Kiekviena() {
    ofstream fr("Rezultatai.txt", ios::app);
    int sum = 0;
    for(int i = 1; i <= 12; i++) {
        for(int z = 1; z <= n; z++) {
            if(mm[z] == i) sum++;
        }
        fr << sum << " ";
        sum = 0;
    }
    fr << endl;
}

void Raso() {
    ofstream fr("Rezultatai.txt");
    fr << "Berniukai: " << Skaicius('v') << endl;
    fr << var[Populiariausias('v')] << endl;
    fr << "Mergaites: " << Skaicius('m') << endl;
    fr << var[Populiariausias('m')] << endl;
    Kiekviena();
    fr.close();
}
