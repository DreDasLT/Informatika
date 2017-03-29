// Varþtai ir verþlës
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
const int CMax = 100;
//---------------
void Skaitymas(int Vr[], int Vrz[], int n, int m, int x);
void Skirtumas(int S[], int Vr[], int Vrz[]);
//---------------
int main()
{
   int Vr[CMax]; int Vrz[CMax]; int n; int m; int S[CMax]; int x;
   Skaitymas(Vr, Vrz, n, m, x);
   Skirtumas(S, Vr, Vrz);
   return 0;
}
//--------------
void Skaitymas(int Vr[], int Vrz[], int n, int m, int x)
{
   ifstream fd("Duomenys9_u3.txt");
   Vr[20];
   Vrz[20];
   for (int i = 1; i <= 20; i++) {
      Vr[i] = 0;
      Vrz[i] = 0;
   }
   fd >> n;
   for (int i = 1; i <= n; i++) {
      fd >> x;
      Vr[x] = Vr[x] + 1;
   }
   fd >> m;
   for (int i = 1; i <= m; i++) {
      fd >> x;
      Vrz[x] = Vrz[x] + 1;
   }
   fd.close();
}
//------
void Skirtumas(int S[], int Vr[], int Vrz[])
{
   ofstream fr("Rezultatai9_u3.txt");
   fr << "Reikalingi varþtai: " << endl;
   for (int i = 1; i <= 20; i++) {
      S[i] = Vr[i] - Vrz[i];
      if (S[i] < 0)
         fr << fabs(S[i]) << " " << i << endl;
   }
   fr << "Reikalingos verþlës: " << endl;
   for (int i = 1; i <= 20; i++) {
      S[i] = Vr[i] - Vrz[i];
      if (S[i] > 0)
         fr << fabs(S[i]) <<" " << i << endl;
   }
   fr.close();
}
