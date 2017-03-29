#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main ()
{
    int a = 0,
        arbuzai[100],
        suma = 0,
        elementas = 0;
    double vidurkis = 0.0,
        skirtumas = 0.0,
        mazskirtumas = 0.0;
    ifstream fd("Duomenys.txt");
    ofstream fr("Rezultatas.txt");
    fd >> a;
    for(int i = 1; i <= a; i++ )
    {
        fd >> arbuzai[i];
        suma += arbuzai[i];
    }
    vidurkis = (float)suma / a;
    mazskirtumas = abs(vidurkis - (float)arbuzai[1]);
    elementas = 1;
    for(int i = 2; i <= a; i++)
    {
        skirtumas = vidurkis - (float)arbuzai[i];
        if(abs(skirtumas) <  mazskirtumas)
        {
            mazskirtumas = abs(skirtumas);
            elementas = i;
        }
    }
    fr << elementas << " " << fixed << setprecision(2) << (float)arbuzai[elementas] << endl;
    return 0;
}
