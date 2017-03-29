// Aritmetika
#include <fstream>
#include <iomanip>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
//---------------------------------------------
bool Tikrinimas(int a, int b, int c, char o);
//---------------------------------------------
int main ()
{
  int  n;                        // užduočių skaičius
  int a, b, c;                   // sveikieji skaičiai
  bool t1, t2, t3, t4;           // rezultatai
  ifstream fd(CDfv);
  ofstream fr(CRfv);
  fd >> n;
  for (int i = 1; i <= n; i++){
    fd >> a >> b >> c;
    t1 = Tikrinimas(a, b, c, '+');
    t2 = Tikrinimas(a, b, c, '-');
    t3 = Tikrinimas(a, b, c, '*');
    t4 = Tikrinimas(a, b, c, '/');
    if (t1) fr << a << " + " << b << " = " << c << endl;
    if (t2) fr << a << " - " << b << " = " << c << endl;
    if (t3) fr << a << " * " << b << " = " << c << endl;
    if (t4) fr << a << " / " << b << " = " << c << endl;
    if (t1 + t2 + t3 + t4 == 0) fr << a << " " << b << " " << c << " KLAIDINGA " << endl;
  }
  fd.close();
  fr.close();
  return 0;
}
//---------------------------------------------
bool Tikrinimas(int a, int b, int c, char o){
   if ((o == '+') && (a + b == c)) return true;
   else if ((o == '-') && (a - b == c)) return true;
        else if ((o == '*') && (a * b == c)) return true;
             else if ((o == '/') && (a % b == 0) && (a / b == c)) return true;
                  else return false;
}
//---------------------------------------------
