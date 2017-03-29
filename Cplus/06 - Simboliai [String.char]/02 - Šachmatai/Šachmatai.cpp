#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int n;
char figuros[1000];
int p, b, z, r, v, k, komplektai, likutis;

ifstream fd("Duomenys.txt");
ofstream fr("Rezultatai.txt");

void Skaityti();
void Skaiciuoti();
void Spausdinti();

int main()
{
    Skaityti();
    Skaiciuoti();
    Spausdinti();
    return 0;
}

void Skaityti()
{
    fd >> n;
    for(int i = 0; i < n; i++) {
        fd >> figuros[i];
    }
}

void Skaiciuoti()
{
    for(int i = 0; i < n; i++) {
        if(figuros[i] == 'p') p++;
        if(figuros[i] == 'b') b++;
        if(figuros[i] == 'z') z++;
        if(figuros[i] == 'r') r++;
        if(figuros[i] == 'v') v++;
        if(figuros[i] == 'k') k++;
    }

}

void Spausdinti()
{
    cout << "p " << p << endl;
    cout << "b " << b << endl;
    cout << "z " << z << endl;
    cout << "r " << r << endl;
    cout << "v " << v << endl;
    cout << "k " << k << endl;
}
