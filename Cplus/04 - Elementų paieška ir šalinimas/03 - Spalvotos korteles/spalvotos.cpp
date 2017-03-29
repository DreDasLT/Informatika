// Spalvotos kortelës
#include <iostream>
#include <fstream>
using namespace std;
const int CMax = 1000;
//-------------
void Skaityti(int M[], int R[], int J[], int G[], int n);
void Sekos(char a, int x[], int Si[], int P[], int Pb[], int & k);

//-------------
int main()
{
   int M[CMax]; int R[CMax]; int J[CMax]; int G[CMax]; int n;
   int x[CMax]; int Si[CMax]; int P[CMax]; int Pb[CMax]; int k;
   Skaityti(M, R, J, G, n);
   ofstream fr;
   fr.open("Rezultatai9_u2.txt");
   fr.close();
   fr.open("Rezultatai9_u2.txt", ios::app);
   Sekos('G', G, Si, P, Pb, k);
   Sekos('M', M, Si, P, Pb, k);
   Sekos('R', R, Si, P, Pb, k);
   Sekos('J', J, Si, P, Pb, k);
   fr.close();
   return 0;
}
//-------------
void Skaityti(int M[], int R[], int J[], int G[], int n)
{
   M[13]; R[13]; J[13]; G[13];
   char x; int y;
   ifstream fd("Duomenys.txt");
   for (int i = 1; i <= 13; i++) {
      M[i] = 0; J[i] = 0; R[i] = 0; G[i] = 0;
   }
   fd >> n;
   for (int i = 1; i <= n; i++) {
      fd >> x >> y;
      if (x == 'M') M[y] = M[y] + 1;
      else if (x == 'J') J[y] = J[y] + 1;
      else if (x == 'R') R[y] = R[y] + 1;
      else G[y] = G[y] + 1;
   }
   fd.close();
}
//-------------
void Sekos(char a, int x[], int Si[], int P[], int Pb[], int & k)
{
   int i, j, silgis;
   i = 1;
   ofstream fr("Rezultatai9_u2.txt", ios::app);
   k = 0;
   while (i <= 13) {
      silgis = 0;
      while ((x[i] == 0) && (i <= 13))
      i = i + 1;
      k = k + 1;
      P[k] = i;

      silgis = silgis + 1;

      while ((x[i] != 0)&& (i <= 13)) {
         silgis = silgis + 1;
         i = i + 1;
      }
      Pb[k] = i - 1;
      Si[k] = silgis;
      if (silgis >= 3) {
         for (int j = P[k]; j <= Pb[k]; j++ ) fr << a << " "<< j << " ";
         fr << endl;
      }
   }
}
//-----------------
