#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n = 0,
        elementas[2];
    double augalas[1000],
        didzmase = 0.0;
    ifstream fd("Duomenys.txt");
    ofstream fr("Rezultatas.txt");
    fd >> n;
    for(int i = 1; i <= n; i++)
    {
        fd >> augalas[i];
    }
    for(int i = 1; i <= n; i++)
    {
        if(augalas[i] == 0 || augalas[i+1] == 0) continue;
        if(didzmase < augalas[i] + augalas[i+1])
        {
            didzmase = augalas[i] + augalas[i+1];
            elementas[0] = i;
            elementas[1] = i+1;
        }
    }
    if(didzmase == 0) fr << "Pora nesurasta" << endl;
    else {
        fr << elementas[0] << " " << augalas[elementas[0]] << endl;
        fr << elementas[1] << " " << augalas[elementas[1]] << endl;
    }
    return 0;
}
