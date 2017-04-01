// Kortelės
#include <fstream>
#include <iomanip>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
//---------------------------------------------
void Skaitymas(int S[]);
int Kiekis(int x, int y);
void Rasymas(int S[]);
//---------------------------------------------
int main ()
{
  int S[20];
  Skaitymas(S);
  Rasymas(S);
  return 0;
}
//---------------------------------------------
int Kiekis(int x, int y) {
  return x - y;
}
//---------------------------------------------
void Skaitymas(int S[]) {
    int k, n, kr, nr;
    ifstream fd(CDfv);
    fd >> k >> n;
    for (int i = 0; i <= 10; i++)
      S[i] = n;
    for (int i = 0; i < k; i++){
       fd >> nr >> kr;
       S[nr] = Kiekis(S[nr], kr);
    }
   fd.close();
}
//---------------------------------------------
void Rasymas(int S[]) {
   ofstream fr(CRfv);
   for (int i = 0; i <= 10; i++)
       fr << i << " " << S[i] << endl;
   fr.close();
}
