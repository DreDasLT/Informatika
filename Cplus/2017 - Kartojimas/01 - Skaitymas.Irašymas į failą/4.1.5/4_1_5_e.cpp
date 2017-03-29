// Kalba
#include <fstream>
#include <iomanip>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
int main ()
{
  int n;          // dažniausiai vartojamų žodžių skaičius
  int d;          // po kelių dienų iœvyksta
  int z;          // pirmą dieną iœmoktų žodžių skaičius
  int k;          // keliais žodžiais daugiau iœmokdavo kiekvieną kitą dieną, negu prieœ tai buvusią
  int dt = 0;     // per kiek dienų iœmoks n žodžių
  int s = 0;      // iœmoktų žodžių suma
  ifstream fd(CDfv);
  fd >> n >> d >> z >> k;
  fd.close();
  while (s < n) {
    s = s + z;
    dt ++;
    z = z+ k;
  }
  ofstream fr(CRfv);
  fr << dt << endl;
  if (dt <= d) fr << "TAIP" << endl;
     else fr << "NE" << endl;
  fr.close();
  return 0;
}
