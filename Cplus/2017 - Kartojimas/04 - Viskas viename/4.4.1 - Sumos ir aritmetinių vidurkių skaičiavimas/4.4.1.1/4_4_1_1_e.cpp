// Kelionės
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
//---------------------------------------------
void Skaitymas(int S[], int V[], double SK[], double VK[], int & n);
int Kiekis(int X[], int n);
double Kaina(int X[], double Y[], int n);
void Rasymas(int ss, int vs, double sk, double vk, double skv, double vkv);
//---------------------------------------------
int main ()
{
  int S[100], V[100];
  double SK[100], VK[100];
  int n;
  int ss, vs;
  double sk, vk, skv, vkv;
  Skaitymas(S, V, SK, VK, n);
  ss = Kiekis(S, n);
  vs = Kiekis(V, n);
  sk = Kaina(S, SK, n);
  vk = Kaina(V, VK, n);
  if (ss != 0) skv = sk / ss;
  else skv = 0;
  if (vs != 0) vkv = vk / vs;
  else vkv = 0;
  Rasymas(ss, vs, sk, vk, skv, vkv);
  return 0;
}
//---------------------------------------------
void Skaitymas(int S[], int V[], double SK[], double VK[], int & n) {
    ifstream fd(CDfv);
    fd >> n;
    for (int i = 0; i < n; i++){
      fd >> S[i] >> V[i] >> SK[i] >> VK[i];
    }
   fd.close();
}
//---------------------------------------------
int Kiekis(int X[], int n) {
   int k = 0;
   for (int i = 0; i < n; i++)
     k = k + X[i];
   return k;
}
//---------------------------------------------
double Kaina(int X[], double Y[], int n) {
   double s = 0;
   for (int i = 0; i < n; i++)
     s = s + X[i] * Y[i];
   return s;
}
//---------------------------------------------
void Rasymas(int ss, int vs, double sk, double vk, double skv, double vkv){
   ofstream fr(CRfv);
   fr << ss << " " << vs << endl;
   fr << fixed << setprecision(2) << sk << " " << vk << endl;
   fr << skv << " " << vkv << endl;
   fr.close();
}
