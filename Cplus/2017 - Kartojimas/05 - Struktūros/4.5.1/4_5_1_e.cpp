// Studentai
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
//---------------------------------------------
struct Marsrutai {
         string pav;
         int    vi, mi;
         int    va, ma;
         long   t;
};
//---------------------------------------------
long Trukme(int vi, int mi, int va, int ma);
void Skaitymas(Marsrutai M[], int & n, long & s);
long Visa(Marsrutai M[], int n);
void Rasymas(Marsrutai M[], int n, long v, long t);
//---------------------------------------------
int main ()
{
  int  n; long v, s;
  Marsrutai M[100];
  Skaitymas(M, n, s);
  v = Visa(M, n);
  Rasymas(M, n, v, s);
  return 0;
}
//---------------------------------------------
long Trukme(int vi, int mi, int va, int ma){
    int t;
    if (vi * 60 + mi < va * 60 + ma) t = va * 60 + ma - vi * 60 - mi;
    else t = 24 * 60 - vi * 60 - mi + va * 60 + ma;
    return t;
}
//---------------------------------------------
void Skaitymas(Marsrutai M[], int & n, long & s)
{
  char eil[21]; s = 0;
  ifstream fd (CDfv);
  fd >> n;
  fd.ignore(80, '\n');
  for (int i = 0; i < n; i++) {
    fd.get(eil, 20);
    M[i].pav = eil;
    fd >> M[i].vi >> M[i].mi >> M[i].va >> M[i].ma;
    fd.ignore(80, '\n');
    M[i].t = Trukme(M[i].vi, M[i].mi, M[i].va, M[i].ma);
    s = s + M[i].t;
  }
  fd.close();
}
//---------------------------------------------
long Visa(Marsrutai M[], int n) {
  long v = 0;
  for (int i = 0; i < n - 1; i++)
    v = v + Trukme(M[i].va, M[i].ma, M[i + 1].vi, M[i + 1].mi);
    return v;
}
//---------------------------------------------
void Rasymas(Marsrutai M[], int n, long v, long t)
{
  ofstream fr (CRfv);
  for (int i = 0; i < n; i++)
  if (M[i].t % 60 < 10) fr << M[i].pav << " " << M[i].t / 60 << " 0" << M[i].t % 60 << endl;
  else fr << M[i].pav << " " << M[i].t / 60 << " " << M[i].t % 60 << endl;
  fr << (t + v) / 60 << " " << (t + v) % 60 << endl;
  fr.close();
}
