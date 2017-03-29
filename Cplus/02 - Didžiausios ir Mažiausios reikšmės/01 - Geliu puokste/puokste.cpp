#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int g = 0,
        geles[100],
        didzskaicius = 0;
    ifstream fd("Duomenys.txt");
    ofstream fr("Rezultatas.txt");
    fd >> g;
    fr << "Puokðtës gëlës" << endl;
    fr << "-----------------------" << endl;
    fr << " G. Nr.   Þ. laikas" << endl;
    fr << "-----------------------" << endl;
    for(int i = 1; i <= g; i++)
    {
        fd >> geles[i];
        fr << "  " << i << "          " << geles[i] << endl;
        if(geles[i] > didzskaicius)
        {
            didzskaicius = geles[i];
        }
    }
    fr << "-----------------------" << endl;
    fr << "Visos gëlës nuvys po " << didzskaicius << " d." << endl;
    fr << "Gëliø, kurias reiktø dëti á puokðtæ, numeriai: " << endl;
    fr << "  ";
    for(int i = 1; i <= g; i++)
    {
        if(geles[i] == didzskaicius)
        {
            fr << i << " ";
        }
    }
    // skirtuma suzinot
    return 0;
}
