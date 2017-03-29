// Kelionė
#include <fstream>
#include <iomanip>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
//---------------------------------------------
double Bilietai(int n, double b);
//---------------------------------------------
int main ()
{
  double k;        // kuro sąnaudos 100 km
  int  n;          // œeimos narių skaičius
  double m;        // marœruto ilgis km
  double kk;       // kuro litro kaina
  double b;        // bilieto kaina vykstant visuomeniniu transportu
  int a;           // autobusų, vykstančių pasirinktu marœrutu, skaičius
  double s;        // iœlaidos vykstant nuosavu transportu
  ifstream fd(CDfv);
  ofstream fr(CRfv);
  fd >> k >> m >> kk >> n;
  fd >> a;
  s = (m / 100) * k * kk;
  for (int i = 1; i <= a; i++){
    fd >> b;
    fr << fixed << setprecision(2) << s - Bilietai(n, b)<< endl;
  }
  fr.close();
  return 0;
}
//---------------------------------------------
double Bilietai(int n, double b){
  return n * b;
}
//---------------------------------------------
