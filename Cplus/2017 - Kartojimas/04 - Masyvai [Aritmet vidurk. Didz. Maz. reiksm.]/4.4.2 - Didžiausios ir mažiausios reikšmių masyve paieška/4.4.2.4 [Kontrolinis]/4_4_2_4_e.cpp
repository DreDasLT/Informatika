// Darbas
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
//---------------------------------------------
void Skaitymas(int K[]);
int Kiekis(int x, int y);
int Didziausias(int X[], int n);
int Maziausias(int X[], int n);
void Rasymas(int K[]);
//---------------------------------------------
int main ()
{
  int K[100];
  Skaitymas(K);
  Rasymas(K);
  return 0;
}
//---------------------------------------------
int Kiekis(int x, int y) {
  return x - y;
}
//---------------------------------------------
void Skaitymas(int K[]) {
    ifstream fd(CDfv);
    int k, n;
    fd >> n >> k;
    for (int i = 0; i <= 10; i++) K[i] = n;
    int sk, nr;
    for (int i = 0; i < k; i++){
      fd >> nr >> sk;
      K[nr] = Kiekis (K[nr], sk);
      }
   fd.close();
}
//---------------------------------------------
int Didziausias(int X[], int n) {
   int m = 0;
   for (int i = 0; i < n; i++)
     if (X[i] > X[m]) m = i;
   return m;
}
//---------------------------------------------
int Maziausias(int X[], int n) {
   int m = 0;
   for (int i = 0; i < n; i++)
     if (X[i] < X[m]) m = i;
   return m;
}
//---------------------------------------------
void Rasymas(int K[]) {
   ofstream fr(CRfv);
   int mm;
   mm = Didziausias(K, 11);
   fr << K[mm] << " ";
   for (int i = 0; i <= 10; i++)
   if (K[mm] == K[i]) fr << i << " ";
   fr << endl;
   mm = Maziausias(K, 11);
   fr << K[mm] << " ";
   for (int i = 0; i <= 10; i++)
   if (K[mm] == K[i]) fr << i << " ";
   fr << endl;
   fr.close();
}
