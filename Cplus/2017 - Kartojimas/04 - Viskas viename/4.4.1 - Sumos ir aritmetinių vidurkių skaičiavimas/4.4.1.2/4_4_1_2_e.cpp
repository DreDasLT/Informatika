// Pirkimai
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
//---------------------------------------------
void Skaitymas(int & m, int & v, int & r, double & k, int AM[], int AV[], int AR[], double AK[], int & n);
bool Tinkamas(int m, int v, int r, double k, int ma, int va, int ra, double ka);
void Kiekis(int m, int v, int r, double k, int AM[], int AV[], int AR[], double AK[], int n, int & a, double & s);
void Rasymas(int m, int v, int r, double k, int AM[], int AV[], int AR[], double AK[], int n, int a, double s);
//---------------------------------------------
int main ()
{
  int m, v, r, n, a;
  double k, s;
  int AM[100], AV[100], AR[100];
  double AK[100];
  Skaitymas(m, v, r, k, AM, AV, AR, AK, n);
  Kiekis(m, v, r, k, AM, AV, AR, AK, n, a, s);
  Rasymas(m, v, r, k, AM, AV, AR, AK, n, a, s);
  return 0;
}
//---------------------------------------------
void Skaitymas(int & m, int & v, int & r, double & k, int AM[], int AV[], int AR[], double AK[], int & n) {
    ifstream fd(CDfv);
    fd >> m >> v >> r >> k;
    fd >> n;
    for (int i = 0; i < n; i++){
      fd >> AM[i] >> AV[i] >> AR[i] >> AK[i];
    }
   fd.close();
}
//---------------------------------------------
bool Tinkamas(int m, int v, int r, double k, int ma, int va, int ra, double ka) {
   if ((m >= ma) && (v >= va) && (r >= ra) && (k >= ka)) return true;
   else return false;
}
//---------------------------------------------
void Kiekis(int m, int v, int r, double k, int AM[], int AV[], int AR[], double AK[], int n, int & a, double & s) {
   a = 0; s = 0;
   for (int i = 0; i < n; i++)
     if (Tinkamas(m, v, r, k, AM[i], AV[i], AR[i], AK[i])) {a = a + 1; s = s + AK[i];}
}
//---------------------------------------------
void Rasymas(int m, int v, int r, double k, int AM[], int AV[], int AR[], double AK[], int n, int a, double s) {
   ofstream fr(CRfv);
   fr << a << " " << fixed << setprecision(2) << s << endl;
   for (int i = 0; i < n; i++)
     if (Tinkamas(m, v, r, k, AM[i], AV[i], AR[i], AK[i])) fr << i + 1 << " " << AM[i] << " " << AV[i] << " " << AR[i] << " " << fixed << setprecision(2) << AK[i] << endl;
   fr.close();
}
