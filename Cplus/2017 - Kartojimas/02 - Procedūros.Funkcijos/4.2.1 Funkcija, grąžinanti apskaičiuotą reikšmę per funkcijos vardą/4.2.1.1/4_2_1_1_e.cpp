// Susitikimas
#include <fstream>
#include <iomanip>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
//---------------------------------------------
bool Tikrinimas(long t1, long t2);
//---------------------------------------------
int main ()
{
  int  a, b, c;    // traukinio iœvykimo diena, valanda, minutė
  int  d, e;       // kelionės trukmė valandomis ir minutėmis
  int  ds, v, m;   // susitikimo pradžios laikas: diena, valanda, minutė
  long t1, t2;     // atvykimo ir susitikimo laikas minutėmis
  int da, va, ma;  // atvykimo laikas: diena, valanda, minutė
  ifstream fd(CDfv);
  fd >> a >> b >> c >> d >> e;
  fd >> ds >> v >> m;
  fd.close();
  t1 = a * 24 * 60 + b * 60 + c + d * 60 + e;
  t2 = ds * 60 * 24 + v * 60 + m;
  da = t1 / 60 / 24;
  va = t1 / 60 % 24;
  ma = t1 % 60;
  ofstream fr(CRfv);
  fr << da << " " << va << " " << ma << endl;
  if (Tikrinimas(t1, t2)) fr << "TAIP" << endl;
  else fr << "NE" << endl;
  fr.close();
  return 0;
}
bool Tikrinimas(long t1, long t2){
  if (t1 <= t2) return true;
  else return false;
}
