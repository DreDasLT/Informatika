#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;

ifstream fd("U1.txt");
ofstream fr("U1rez.txt");

const int n = 50;

int g, e, gilai[n], eglai[n];

void skaityti();

int main()
{
    skaityti();
    return 0;
}

void skaityti()
{
    int nominalas[n];
    cout << "Gilai" << endl;
    fd >> g;
    for(int i=1; i<=g; i++) fd >> nominalas[i];
    for(int i=1; i<=g; i++) {
        int z = nominalas[i];
        fd >> gilai[z];
        cout <<"Moneta: " << z << " " << gilai[z] << " " << endl;
    }
    cout << "Eglai" << endl;
    fd >> e;
    for(int i=1; i<=e; i++) fd >> nominalas[i];
    for(int i=1; i<=e; i++) {
        int z = nominalas[i];
        fd >> eglai[z];
        cout <<"Moneta: " << z << " " << eglai[z] << " " << endl;
    }
}

void keisti()
{

}
