// Atrinkti, kuriu ugis ne mazesnis 1.90, atpsausdinti kiek komandoje nariu ir ju duomenis.


#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

ifstream fd("Duomenys.txt");
ofstream fr("Rezultatas.txt");



struct Krepsininkais {
    string vardas;
    double ugis;
    int metai;
};

void Skaityti(Krepsininkais Krepsininkai[], int & mokiniai);
void Atrinkti();

int main()
{
    int mokiniai;
    Krepsininkais Krepsininkai[10];
    Skaityti(Krepsininkai, mokiniai);
    return 0;
}

void Skaityti(Krepsininkais Krepsininkai[],  int & mokiniai)
{
    int i = 0;
    while(!fd.eof()) {
        fd >> Krepsininkai[i].vardas >> Krepsininkai[i].ugis >> Krepsininkai[i].metai;
        cout << Krepsininkai[i].vardas << " " << Krepsininkai[i].ugis << " " << Krepsininkai[i].metai << endl;
        i++;
    }
}
