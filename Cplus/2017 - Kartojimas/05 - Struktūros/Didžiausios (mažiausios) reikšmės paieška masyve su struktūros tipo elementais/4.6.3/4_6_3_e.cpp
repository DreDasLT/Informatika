// Naudingiausios darþovës
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
//---------------------------------------------
struct Darzove {
         string pav;
         double aa, bb, rr, p, e;
         double a, b, r;
};
//---------------------------------------------
double Verte(double x, double y);
double Procentai(double a, double b, double r);
void Skaitymas(Darzove D[], int & n);
int  Maziausia(Darzove D[], int n, int k);
int  Daugiausia(Darzove D[], int n, int k);
void Rasymas(Darzove D[], int n);
//---------------------------------------------
int main ()
{
  int  n;
  Darzove D[100];
  Skaitymas(D, n);
  Rasymas(D, n);
  return 0;
}
//---------------------------------------------
double Verte(double x, double y){
return x * y;
}
//---------------------------------------------
double Procentai(double a, double b, double r) {
return 100 - a - b - r;
}
//---------------------------------------------
void Skaitymas(Darzove D[], int & n)
{
  char eil[16]; double ak, bk, rk, a, b, r;
  ifstream fd (CDfv);
  fd >> ak >> bk >> rk;
  fd.ignore(80, '\n');
  fd >> n;
  fd.ignore(80, '\n');
  for (int i = 0; i < n; i++) {
    fd.get(eil, 15);
    D[i].pav = eil;
    fd >> D[i].aa >> D[i].bb >> D[i].rr;
    fd.ignore(80, '\n');
    D[i].a = Verte(D[i].aa, ak);
    D[i].b = Verte(D[i].bb, bk);
    D[i].r = Verte(D[i].rr, rk);
    D[i].p = Procentai(D[i].aa, D[i].bb, D[i].rr);
    D[i].e = D[i].aa * ak + D[i].bb * bk + D[i].rr * rk;
  }
  fd.close();
}
//---------------------------------------------
int  Daugiausia(Darzove D[], int n, int k) {
  int m = 0;
  if (k == 1)
    for (int i = 0; i < n; i++)
      if (D[i].e > D[m].e) m = i;
  if (k == 2)
      for (int i = 0; i < n; i++)
        if (D[i].bb > D[m].bb) m = i;
  return m;
}
//---------------------------------------------
int  Maziausia(Darzove D[], int n, int k) {
  int m = 0;
  if (k == 1)
    for (int i = 0; i < n; i++)
      if (D[i].p < D[m].p) m = i;
  if (k == 2)
      for (int i = 0; i < n; i++)
        if (D[i].rr < D[m].rr) m = i;
  return m;
}
//---------------------------------------------
void Rasymas(Darzove D[], int n)
{
  ofstream fr (CRfv);
  int m;
  m = Daugiausia(D, n, 1);
  for (int i = 0; i < n; i++)
    if (D[i].e == D[m].e)
    fr << D[i].pav << " " << fixed << setprecision(1) << D[i].e << endl;
  m = Daugiausia(D, n, 2);
  for (int i = 0; i < n; i++)
    if (D[i].b == D[m].b)
    fr << D[i].pav << " " << fixed << setprecision(1) << D[i].bb << " " << D[i].b << endl;
   m = Maziausia(D, n, 2);
  for (int i = 0; i < n; i++)
    if (D[i].r == D[m].r)
    fr << D[i].pav << " " << fixed << setprecision(1) << D[i].rr << " " << D[i].r << endl;
  m = Maziausia(D, n, 1);
  for (int i = 0; i < n; i++)
    if (D[i].p == D[m].p)
    fr << D[i].pav << " " << fixed << setprecision(1) << D[i].p << endl;
  fr.close();
}
