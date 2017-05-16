// Populiariausios kalbos
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
//---------------------------------------------
struct Kalba {
         string pav;
         int p;
};
//---------------------------------------------
int Pokytis(int x, int y);
void Skaitymas(Kalba K[], int & n);
int Daugiausia(Kalba K[], int n);
int Maziausia(Kalba K[], int n);
void Rasymas(Kalba K[], int n);
//---------------------------------------------
int main ()
{
  int  n;
  Kalba K[100];
  Skaitymas(K, n);
  Rasymas(K, n);
  return 0;
}
//---------------------------------------------
int Pokytis(int x, int y){
return x - y;
}
//---------------------------------------------
void Skaitymas(Kalba K[], int & n)
{
  char eil[26]; int n1, n2;
  ifstream fd (CDfv);
  fd >> n;
  fd.ignore(80, '\n');
  for (int i = 0; i < n; i++) {
    fd.get(eil, 25);
    K[i].pav = eil;
    fd >> n1 >> n2;
    fd.ignore(80, '\n');
    K[i].p = Pokytis(n2, n1);
  }
  fd.close();
}
//---------------------------------------------
int Daugiausia(Kalba K[], int n) {
   int m = 0;
   for (int i = 0; i < n; i++)
     if (K[i].p > K[m].p) m = i;
return m;
}
//---------------------------------------------
int Maziausia(Kalba K[], int n) {
   int m = 0;
   for (int i = 0; i < n; i++)
     if (K[i].p < K[m].p) m = i;
return m;
}
//---------------------------------------------
void Rasymas(Kalba K[], int n)
{
  ofstream fr (CRfv);
  int m;
  m = Daugiausia(K, n);
  fr << K[m].p << endl;
  for (int i = 0; i < n; i++)
    if (K[i].p == K[m].p) fr << K[i].pav << endl;
  m = Maziausia(K, n);
  fr << fabs(K[m].p) << endl;
  for (int i = 0; i < n; i++)
    if (K[i].p == K[m].p) fr << K[i].pav << endl;
  fr.close();
}
