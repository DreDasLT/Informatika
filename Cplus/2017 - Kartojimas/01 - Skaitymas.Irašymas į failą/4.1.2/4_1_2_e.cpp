// Automobilis
#include <fstream>
#include <iomanip>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
int main ()
{
  double k, m, kk; // automobilio sunaudojamas kuro kiekis 100 km, kelion�s ilgis km, 1 litro kuro kaina
  int n;           // keliautoj� skai�ius
  double s;        // vieno �mogaus kelion�s kaina
  ifstream fd(CDfv);
  fd >> k >> m >> kk >> n;
  fd.close();
  s = ((m / 100) * k) * kk / n;
  ofstream fr(CRfv);
  fr << fixed << setprecision(1) << s << endl;
  fr.close();
  return 0;
}
