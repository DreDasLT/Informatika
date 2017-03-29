// Energija
#include <fstream>
#include <iomanip>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
//---------------------------------------------
void Produktas(double rv, double bv, double av, double r, double b, double a, double p, double & er, double & eb, double & ea);
//---------------------------------------------
int main ()
{
  int  n;             // produktų skaičius
  double rv, bv, av;  // viename grame riebalų, baltymų ir angliavandenių esantys kcal kiekiai
  double r, b, a;     // produkto 100 gramų esantys riebalų, baltymų ir angliavandenių kiekiai gramais
  double p;           // produkto kiekis gramais, reikalingas gaminant pateikalą
  double er, eb, ea;  // riebalų, baltymų ir angliavandenių energetinė vertė kcal
  double pp = 0;      // pagaminto patiekalo energetinė vertė kcal
  ifstream fd(CDfv);
  ofstream fr(CRfv);
  fd >> rv >> bv >> av;
  fd >> n;
  for (int i = 1; i <= n; i++){
    fd >> r >> b >> a >> p;
    Produktas(rv, bv, av, r, b, a, p, er, eb, ea);
    fr << fixed << setprecision(2) << er << " " << eb << " " << ea << endl;
    pp = pp + er + eb + ea;
  }
  fr << fixed << setprecision(2) << pp << endl;
  fd.close();
  fr.close();
  return 0;
}
//---------------------------------------------
void Produktas(double rv, double bv, double av, double r, double b, double a, double p, double & er, double & eb, double & ea){
   er = (p / 100) * r * rv;
   eb = (p / 100) * b * bv;
   ea = (p / 100) * a * av;
}
