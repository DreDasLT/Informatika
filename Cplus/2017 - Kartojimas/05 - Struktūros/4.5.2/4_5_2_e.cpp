// Iœlaidos
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
//---------------------------------------------
struct Degaline {
         string pav;
         double b, d;
};
//---------------------------------------------
double Kaina(double x, double y);
void Skaitymas(Degaline D[], int & n);
void Rasymas(Degaline D[], int n);
//---------------------------------------------
int main ()
{
  int  n;
  Degaline D[100];
  Skaitymas(D, n);
  Rasymas(D, n);
  return 0;
}
//---------------------------------------------
double Kaina(double x, double y){
return (x / 100) * y;
}
//---------------------------------------------
void Skaitymas(Degaline D[], int & n)
{
  char eil[16]; double b, d, m; double kb, kd;
  ifstream fd (CDfv);
  fd >> b >> d >> m >>  n;
  fd.ignore(80, '\n');
  for (int i = 0; i < n; i++) {
    fd.get(eil, 15);
    D[i].pav = eil;
    fd >> kb >> kd;
    fd.ignore(80, '\n');
    D[i].b = Kaina(m, b) * kb;
    D[i].d = Kaina(m, d) * kd;
  }
  fd.close();
}
//---------------------------------------------
void Rasymas(Degaline D[], int n)
{
  ofstream fr (CRfv);
  for (int i = 0; i < n; i++)
    fr << D[i].pav << " " << fixed << setprecision(2) << D[i].b << " " << D[i].d << endl;
  fr.close();
}
