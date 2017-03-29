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
    fr << "Puok�t�s g�l�s" << endl;
    fr << "-----------------------" << endl;
    fr << " G. Nr.   �. laikas" << endl;
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
    fr << "Visos g�l�s nuvys po " << didzskaicius << " d." << endl;
    fr << "G�li�, kurias reikt� d�ti � puok�t�, numeriai: " << endl;
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
