// Kalorijos
#include <fstream>
#include <iomanip>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
int main ()
{
  double a, r, b; // angliavandeniø, riebalø ir baltymø kiekis procentais
  int ak, rk, bk; // viename grame angliavandeniø, riebalø ir baltymø esantis kalorijø skaièius
  int k;          // þmogaus per parà suvartojamas kcal kiekis
  double gr, gb, ga; // riebalø, baltymø ir angliavandeniø kiekis gramais
  ifstream fd(CDfv);
  fd >> a >> r >> b;
  fd >> ak >> rk >> bk;
  fd >> k;
  fd.close();
  gr = (k * r * 0.01) / rk;
  gb = (k * b * 0.01) / bk;
  ga = (k * a * 0.01) / ak;
  ofstream fr(CRfv);
  fr << fixed << setprecision(2) << ga << endl;
  fr << fixed << setprecision(2) << gr << endl;
  fr << fixed << setprecision(2) << gb << endl;
  fr.close();
  return 0;
}
