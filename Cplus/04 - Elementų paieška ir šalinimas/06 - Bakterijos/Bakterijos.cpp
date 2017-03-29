#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;

const int CMax = 1001;
int n, d;
int bakterijos[CMax];

void Skaityti();
int main()
{
    Skaityti();
    return 0;
}

void Skaityti()
{
    ifstream fd("Duomenys.txt");
    fd >> n;
    fd >> d;
    for(int i=0; i<=n; i++) {
        fd >> bakterijos[i];
        cout << bakterijos[i] << endl;
    }
}
