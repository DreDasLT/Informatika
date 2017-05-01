// Atostogų kelionės
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
//---------------------------------------------
void Skaitymas(int  & s, int & v, int & k, int & n, double SK[], double VK[], int P[], double K[]);
double Kaina(int s, int v, int k, double sk1, double vk1, int p1);
int Pigiausia(double X[], int n);
void Rasymas(double K[], int n);
//---------------------------------------------
int main ()
{
  int P[100];
  double SK[100], VK[100], K[100];
  int s, v, k, n, m;
  Skaitymas(s, v, k, n, SK, VK, P, K);
  Rasymas(K, n);
  return 0;
}
//---------------------------------------------
double Kaina(int s, int v, int k, double sk1, double vk1, int p1) {
   double ss = 0;
     if (s + v >= k) ss = (s * sk1 + v * vk1) * (100 - p1) * 0.01;
     else ss = s * sk1 + v * vk1;
   return ss;
}
//---------------------------------------------
void Skaitymas(int  & s, int & v, int & k, int & n, double SK[], double VK[], int P[], double K[]) {
    ifstream fd(CDfv);
    fd >> s >> v >> k;
    fd >> n;
    for (int i = 0; i < n; i++){
      fd >> SK[i] >> VK[i] >> P[i];
      K[i] = Kaina(s, v, k, SK[i], VK[i], P[i]);
    }
   fd.close();
}
//---------------------------------------------
int Pigiausia(double X[], int n) {
   int m = 0;
   for (int i = 0; i < n; i++)
     if (X[i] <= X[m]) m = i;
   return m;
}
//---------------------------------------------
void Rasymas(double K[], int n){
   ofstream fr(CRfv);
   for (int i = 0; i < n; i++)
   fr << i + 1 << " " << fixed << setprecision(2) << K[i] << endl;
   fr << Pigiausia(K, n) + 1 << endl;
   fr.close();
}
