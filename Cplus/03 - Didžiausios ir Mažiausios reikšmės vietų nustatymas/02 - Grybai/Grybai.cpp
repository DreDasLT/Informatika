#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n, menuo[100], diena[100], baravykai[100], raudonvirsiai[100], didzel = 0, didzsk = 0;
    double mase[100], didz = 0;
    ifstream fd("Duomenys.txt");
    ofstream fr("Rezultatas.txt");
    fd >> n;
    for(int i = 0; i < n; i++)
    {
        fd >> menuo[i];
        fd >> diena[i];
        fd >> mase[i];
        fd >> baravykai[i];
        fd >> raudonvirsiai[i];
    }
    for(int i = 0; i < n; i++)
    {
        if(mase[i] > didz)
        {
            didz = mase[i];
            didzel = i;
        }
    }
    fr << "Derlingiausia diena: " << menuo[didzel] << " " << diena[didzel] << endl;
    didzel = 0;
    for(int i = 0; i < n; i++)
    {
        if(baravykai[i] > didzsk)
        {
            didzsk = baravykai[i];
            didzel = i;
        }
    }
    if(didzsk == 0) fr << "Derlingiausia baravyku diena: nera" << endl;
    else fr << "Derlingiausia baravyku diena: " << menuo[didzel] << " " << diena[didzel] << endl;
    didzel = 0;
    didzsk = 0;
    for(int i = 0; i < n; i++)
    {
        if(raudonvirsiai[i] > didzsk)
        {
            didzsk = raudonvirsiai[i];
            didzel = i;
        }
    }
    if(didzsk == 0) fr << "Derlingiausia raudonvirsiu diena: nera" << endl;
    else fr << "Derlingiausia raudonvirsiu diena: " << menuo[didzel] << " " << diena[didzel] << endl;
    return 0;
}
