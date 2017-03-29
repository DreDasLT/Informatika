// Planas
#include <fstream>
#include <iomanip>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
//---------------------------------------------
int Kiekis(int a, int b);
//---------------------------------------------
int main ()
{
  int  d;            // dienų skaičius
  int  z;            // kiek žodžių turi iœmokti per dieną
  int dz;            // per dieną iœmoktų žodžių skaičius
  int dn = 0;        // kelias dienas nevykdytas planas
  int zn = 0;        // neiœmoktų žodžių skaičius
  int dp;            // kelias dienas mokysis papildomai
  ifstream fd(CDfv);
  fd >> d >> z;
  for (int i = 1; i <= d; i++){
    fd >> dz;
    if (Kiekis(z, dz) > 0) dn++;
    zn = zn + Kiekis(z, dz);
  }
  fd.close();
  ofstream fr(CRfv);
  fr << dn << endl;
  fr << zn << endl;
  if (zn % z == 0) dp = zn / z;
  else dp = zn / z + 1;
  fr << dp << endl;
  fr.close();
  return 0;
}
//---------------------------------------------
int Kiekis(int a, int b){
    return a - b;
}
//---------------------------------------------
