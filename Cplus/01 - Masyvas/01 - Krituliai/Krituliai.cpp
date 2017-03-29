#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int dskaicius, dienos[10], isvisokrituliu = 0, nelijodienu = 0, lietingosdienos = 0, krituliuvidurkis = 0;
    ifstream fd("Duomenys.txt");
    fd >> dskaicius;
    for ( int i = 0; i < dskaicius; i++ )
    {
      fd >> dienos[i];
      isvisokrituliu += dienos[i];
      if(dienos[i] == 0) nelijodienu ++;
      else lietingosdienos++;
    }
    fd.close();
    krituliuvidurkis = isvisokrituliu / lietingosdienos;
    cout << "Krituliai (lietus)" << endl;
    cout << "-------------------------------------" << endl;
    cout << "Diena" << setw(22) << "Krituliu kiekis (mm)" << endl;
    cout << "-------------------------------------" << endl;
    for ( int i = 0; i < dskaicius; i++)
    {
       cout << setw(3) << i+1 << setw(12) << dienos[i] << endl;
    }
    cout << "-------------------------------------" << endl;
    cout << "Is viso krituliu (mm): " << isvisokrituliu << endl;
    cout << "Nelijo (dienas): " << nelijodienu << endl;
    cout << "Vidutiniskai kiekviena lietinga diena iskrito krituliu (mm): " << krituliuvidurkis << endl;
    return 0;
}
