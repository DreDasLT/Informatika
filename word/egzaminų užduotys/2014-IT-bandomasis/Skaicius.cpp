// EgzaminoUzduotis
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const char RezF[]  = "U2rez.txt";
typedef int skaiciaiMas[1001];   

//----------------------------------------------------------
void GaukSkaicius(skaiciaiMas visi, int& dydis);
void Apversk(skaiciaiMas rez);
void RasykRezultata();
//----------------------------------------------------------
int main()
{
int i, kiek=0, num;
skaiciaiMas  duomenys, rezultatai;
for (i = 0; i<rand() % 999+10;i++)
{
    GaukSkaicius(duomenys, kiek);
}   
Apversk(rezultatai);
RasykRezultata();
  return 0;
}
//-------------------------------------------------------
void Apversk(skaiciaiMas rez)
{

}

void RasykRezultata()
{

}
void GaukSkaicius(skaiciaiMas visi, int& dydis) // visada kuria skirtingus skaièius 
{
     int i, j, sk, m;
     bool nera;
 do
 {
    nera=true;
    sk=rand() % 9999 + 1; // funkcija rand generuoja atsitiktinius skaièius
    i = 0;
     while (i < dydis && nera) {
        
            i++;
            if (visi[i] == sk) nera = false;
            }
 }
 while (!nera);
 dydis++;
 visi[dydis] = sk;
}
