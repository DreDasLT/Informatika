// Ketvirtokas
#include <fstream>
#include <iomanip>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
//---------------------------------------------
void Skaitmenys(int & s, int k, int & kk);
//---------------------------------------------
int main ()
{
  int  s;             // ant kortelės užraœytas skaičius
  int k5, k3, k1;     // sumoje esančių 5, 3 ir 1 kiekiai
  ifstream fd(CDfv);
  ofstream fr(CRfv);
  fd >> s;
  fd.close();
  Skaitmenys(s, 5, k5);
  Skaitmenys(s, 3, k3);
  k1 = s;
  fr << 5 << " " << k5 << endl;
  fr << 3 << " " << k3 << endl;
  fr << 1 << " " << k1 << endl;
  fr.close();
  return 0;
}
//---------------------------------------------
void Skaitmenys(int & s, int k, int & kk){
   kk = s / k;
   s = s % k;
}
