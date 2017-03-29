// Patiekalas
#include <fstream>
#include <iomanip>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
//---------------------------------------------
double Procentai(int y, double x);
//---------------------------------------------
int main ()
{
  int  n;                        // produktų skaičius
  double r, b, a;                // produkte esantys riebalų, baltymų ir angliavandenių kiekiai gramais
  int p;                         // produkto masė gramais
  double rr = 0, bb = 0, aa = 0; // bendra sudedamųjų dalių masė gramais
  int pp = 0;                    // bendra produktų masė gramais
  ifstream fd(CDfv);
  fd >> n;
  for (int i = 1; i <= n; i++){
    fd >> r >> b >> a >> p;
    rr = rr + r;
    bb = bb + b;
    aa = aa + a;
    pp = pp + p;
  }
  ofstream fr(CRfv);
  fr << fixed << setprecision(2) << Procentai(pp, rr) << endl;
  fr << fixed << setprecision(2) << Procentai(pp, bb) << endl;
  fr << fixed << setprecision(2) << Procentai(pp, aa) << endl;
  fr.close();
  return 0;
}
//---------------------------------------------
double Procentai(int y, double x){
   return (double) x * 100 / y;
}
//---------------------------------------------
