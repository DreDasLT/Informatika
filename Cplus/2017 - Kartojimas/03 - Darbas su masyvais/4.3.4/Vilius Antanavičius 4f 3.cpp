#include <iostream>
#include <fstream>
using namespace std;
ifstream fd("Duomenys.txt");
ofstream fr("Rezultatai.txt");
void Skaityti(int & k, int & n, int (&s)[100], int (&ks)[100]);
int Skaiciuoti(int n, int k, int sk, int s[100], int ks[100]);
void Raso(int k, int n, int s[100], int ks[100]);
int main() {
    int n, k, s[100], ks[100];
    Skaityti(k, n, s, ks);
    Raso(k, n, s, ks);
    return 0;
}

void Skaityti(int & k, int & n, int (&s)[100], int (&ks)[100]) {
    fd >> k >> n;
    for(int i = 1; i <= k; i++) {
        fd >> s[i] >> ks[i];
    }
}

int Skaiciuoti(int n, int k, int sk, int s[100], int ks[100]) {
    for(int i = 1; i <= k; i++ ) {
        if(s[i] == sk) {
            return n - ks[i];
        }
    }
}

void Raso(int k, int n, int s[100], int ks[100]) {
    for(int i = 1; i <= 10; i++) {
        fr << i << " " << Skaiciuoti(n, k, i, s, ks) << endl;
    }
}
