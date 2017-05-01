// Mokymasis
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
//---------------------------------------------
void Skaitymas(int ZP[], int ZI[]);
int Didziausias(int X[], int Y[], int n);
int Maziausias(int X[], int Y[], int n);
void Rasymas(int ZP[], int ZI[]);
//---------------------------------------------
int main ()
{
  int ZP[50], ZI[50];
  Skaitymas(ZP, ZI);
  Rasymas(ZP, ZI);
  return 0;
}
//---------------------------------------------
void Skaitymas(int ZP[], int ZI[]) {
    ifstream fd(CDfv);
    int n, z1, z2, d;
    fd >> n;
    for (int i = 1; i <= 31; i++) { ZP[i] = 0; ZI[i] = 0; }
    for (int i = 0; i < n; i++) {
      fd >> z1 >> z2 >> d;
      ZP[d] = z1; ZI[d] = z2;
    }
   fd.close();
}
//---------------------------------------------
int Didziausias(int X[], int n) {
   int m = 1;
   while (X[m] == 0) m++;
   for (int i = 1; i <= n; i++)
     if (X[i] > X[m]) m = i;
   return m;
}
//---------------------------------------------
int Maziausias(int X[], int n) {
   int m = 1;
   while (X[m] == 0) m++;
   for (int i = 1; i <= n; i++)
     if ((X[i] < X[m]) && (X[i] != 0)) m = i;
   return m;
}
//---------------------------------------------
void Rasymas(int ZP[], int ZI[]) {
   ofstream fr(CRfv);
   int mm;
   mm = Didziausias(ZI, 31);
   cout << mm << endl;
   fr << ZI[mm] << " ";
   for (int i = 1; i <= 31; i++)
     if (ZI[i] == ZI[mm]) fr << i << " ";
   fr << endl;
   mm = Maziausias(ZP, 31);
   cout << mm << endl;
   fr << ZP[mm] << " ";
   for (int i = 1; i <= 31; i++)
     if (ZP[i] == ZP[mm]) fr << i << " ";
   fr << endl;
   fr.close();
}
