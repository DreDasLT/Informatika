// Traukinys
#include <fstream>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
int main ()
{
  long a, b, c, d;
  int v, m;
  ifstream fd(CDfv);
  fd >> a >> b >> c >> d;
  fd.close();
  v = (a * 60 + b + c * 60 + d) / 60 % 24;
  m = (a * 60 + b + c * 60 + d) % 60;
  ofstream fr(CRfv);
  fr << v << " " << m << endl;
  fr.close();
  return 0;
}
