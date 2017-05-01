// Nykstančios kalbos
#include <fstream>
#include <iomanip>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
//---------------------------------------------
void Skaitymas(int K1[], int K2[], int K3[], int K4[]);
int Suma(int X[], int k);
void Rasymas(int s1, int s2, int s3, int s4);
//---------------------------------------------
int main ()
{
  int K1[20], K2[20], K3[20], K4[20];
  int s1, s2, s3, s4;
  Skaitymas(K1, K2, K3, K4);
  s1 = Suma(K1, 5);
  s2 = Suma(K2, 5);
  s3 = Suma(K3, 5);
  s4 = Suma(K4, 5);
  Rasymas(s1, s2, s3, s4);
  return 0;
}
//---------------------------------------------
void Skaitymas(int K1[], int K2[], int K3[], int K4[]) {
    ifstream fd(CDfv);
    for (int i = 1; i <= 5; i++)
      fd >> K1[i] >> K2[i] >> K3[i] >> K4[i];
   fd.close();
}
//---------------------------------------------
int Suma(int X[], int k) {
    int s = 0;
    for (int i = 1; i <= 5; i++)
       s = s + X[i];
  return s;
}
//---------------------------------------------
void Rasymas(int s1, int s2, int s3, int s4) {
   ofstream fr(CRfv);
   fr << s1 << endl;
   fr << s2 << endl;
   fr << s3 << endl;
   fr << s4 << endl;
   fr.close();
}
