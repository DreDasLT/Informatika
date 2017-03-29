#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main()
{
    int n,
        mergaites = 0,
        berniukai = 0,
        mergaiciuugiai[30],
        berniukuugiai[30],
        mergaiciuugiusuma = 0,
        berniukuugiusuma = 0,
        laikinaskintamasis = 0,
        mokiniuugiusuma = 0;
    double
        mokiniuvidutinisugis = 0.0,
        mergaiciuvidutinisugis = 0.0,
        berniukuvidutinisugis = 0.0;
    ifstream fd("Duomenys.txt");
    fd >> n;
    for(int i = 0; i < n; i++)
    {
        fd >> laikinaskintamasis;
        if(laikinaskintamasis > 0)
        {
            mergaites++;
            mergaiciuugiai[mergaites-1] = abs(laikinaskintamasis);
            mergaiciuugiusuma += abs(laikinaskintamasis);
        }
        else
        {
            berniukai++;
            berniukuugiai[berniukai-1] = abs(laikinaskintamasis);
            berniukuugiusuma += abs(laikinaskintamasis);
        }
        mokiniuugiusuma += abs(laikinaskintamasis);
    }
    mokiniuvidutinisugis = (float)mokiniuugiusuma / n;
    mergaiciuvidutinisugis = (float)mergaiciuugiusuma / mergaites;
    berniukuvidutinisugis = (float)berniukuugiusuma / berniukai;
    ofstream fr("Rezultatas.txt");
    fr << fixed << setprecision(1) << mokiniuvidutinisugis << endl;
    fr << fixed << setprecision(2) << mergaiciuvidutinisugis << endl;
    fr << fixed << setprecision(2) << berniukuvidutinisugis << endl;
    laikinaskintamasis = 0;
    for(int i = 0; i < mergaites; i++)
    {
        if(mergaiciuugiai[i] >= 175) laikinaskintamasis++;
    }
    if(laikinaskintamasis >=7)
        fr << "Galima sudaryti merginu komanda" << endl;
    else
        fr << "Merginu komandos sudaryti negalima" << endl;
    laikinaskintamasis = 0;
    for(int i = 0; i < berniukai; i++)
    {
        if(berniukuugiai[i] >= 175) laikinaskintamasis++;
    }
    if(laikinaskintamasis >= 7)
        fr << "Galima sudaryti berniuku komanda" << endl;
    else
        fr << "Berniuku komandos sudaryti negalima" << endl;
    return 0;
}
