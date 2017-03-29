#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n = 1,
        g = 1,
        gamintojai[1000],
        talpa[100],
        laikinas,
        konteineriai = 0;

    ifstream fd("Duomenys.txt");
    ofstream fr("Rezultatas.txt");
    fd >> n;
    fd >> g;
    for(int i = 1; i <= g; i++) talpa[i] = 0;
    for(int i = 1; i <= n; i++)
    {
        fd >> gamintojai[i];
        talpa[g] += (int)gamintojai[i] / g;
        laikinas = gamintojai[i] % g;
        talpa[laikinas]++;
        konteineriai += (int)gamintojai[i] / g + 1;
    }
    fr << konteineriai << endl;
    for(int i = g; i <=g && i >= 1; i--)
    {
        fr << talpa[i] << endl;
    }
    return 0;
}
