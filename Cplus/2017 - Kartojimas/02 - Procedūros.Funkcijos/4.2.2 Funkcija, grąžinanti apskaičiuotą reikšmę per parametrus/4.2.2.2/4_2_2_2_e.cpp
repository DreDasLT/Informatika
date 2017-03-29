// Iœlaidos
#include <fstream>
#include <iomanip>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
//---------------------------------------------
void Kaina(double b, double d, double m, double bk, double dk, double & kb, double & kd);
//---------------------------------------------
int main ()
{
  int  n;          // degalinių skaičius
  double b, d, m;  // benzino, dujų sąnaudos 100 km, kelionės ilgis km
  double bk, dk;   // benzino ir dujų litro kaina
  double kb, kd;   // kelionės kaina, kai automobilis varomas benzinu ir dujomis
  ifstream fd(CDfv);
  ofstream fr(CRfv);
  fd >> b >> d >> m >> n;
  for (int i = 1; i <= n; i++){
    fd >> bk >> dk;
    Kaina(b, d, m, bk, dk, kb, kd);
    fr << fixed << setprecision(2) << kb << " " << kd << endl;
  }
  fd.close();
  fr.close();
  return 0;
}
//---------------------------------------------
void Kaina(double b, double d, double m, double bk, double dk, double & kb, double & kd){
   kb = ((m / 100) * b) * bk;
   kd = ((m / 100) * d) * dk;
}
