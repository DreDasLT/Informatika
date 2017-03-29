// Žaidimas
#include <fstream>
#include <iomanip>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
int main ()
{
  int n;          // kortelių skaičius
  int p, a;       // pirma ir antra kortelė
  int smax;       // didžiausia suma
  int pmax, amax; // didžiausios sumos dėmenys

  ifstream fd(CDfv);
  fd >> n;
  fd >> p >> a;
  smax = p + a;
  pmax = p; amax = a;
  for (int i = 2; i <= n / 2; i++){
    fd >> p >> a;
    if (p + a > smax) { smax = p + a; pmax = p; amax = a; }
  }
  fd.close();
  ofstream fr(CRfv);
  fr << smax << " " << pmax << " " << amax << endl;
  if (pmax == amax) fr << "1 2" << endl;
  else if (pmax > amax) fr << "1" << endl;
       else fr << "2" << endl;
  fr.close();
  return 0;
}
