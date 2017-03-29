#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int
        mskaicius = 0,
        mokiniuperskaitytosknygos[30],
        isvisoknygu = 0;
    double
        perskaitytuknyguvidurkispermetus = 0.0,
        perskaitytuknyguvidurkispermenesi = 0.0;
    ifstream fd("Duomenys.txt");
    fd >> mskaicius;
    for(int i = 0; i < mskaicius; i++)
    {
        fd >> mokiniuperskaitytosknygos[i];
        isvisoknygu += mokiniuperskaitytosknygos[i];
    }
    perskaitytuknyguvidurkispermetus = (float)isvisoknygu / (float)mskaicius;
    perskaitytuknyguvidurkispermenesi = (float)perskaitytuknyguvidurkispermetus / 10;
    ofstream fr("Rezultatas.txt");
    fr << isvisoknygu << endl;
    fr << fixed << setprecision(0)<< perskaitytuknyguvidurkispermetus << endl;
    fr << fixed << setprecision(1)<< perskaitytuknyguvidurkispermenesi << endl;
    return 0;
}
