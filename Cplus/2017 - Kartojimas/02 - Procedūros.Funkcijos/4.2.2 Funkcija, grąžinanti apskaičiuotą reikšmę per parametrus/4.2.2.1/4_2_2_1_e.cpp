// Marœrutai
#include <fstream>
#include <iomanip>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
//---------------------------------------------
long Trukme1(int vi, int mi, int va, int ma);
void Trukme(int v1, int m1, int v2, int m2, int v3, int m3, int v4, int m4, int &v, int &m);
//---------------------------------------------
int main ()
{
  int  n;          // marœrutų skaičius
  int v1, m1;      // pirmojo traukinio iœvykimo valanda ir minutė
  int v2, m2;      // pirmojo traukinio atvykimo valanda ir minutė
  int v3, m3;      // antrojo traukinio iœvykimo valanda ir minutė
  int v4, m4;      // antrojo traukinio atvykimo valanda ir minutė
  int v, m;        // kelionės trukmė valandos ir minutės
  ifstream fd(CDfv);
  ofstream fr(CRfv);
  fd >> n;
  for (int i = 1; i <= n; i++){
    fd >> v1 >> m1 >> v2 >> m2 >> v3 >> m3 >> v4 >> m4;
    Trukme(v1, m1, v2, m2, v3, m3, v4, m4, v, m);
    fr << v << " " << m << endl;
  }
  fd.close();
  fr.close();
  return 0;
}
//---------------------------------------------
long Trukme1(int vi, int mi, int va, int ma){
    int t;
    if (vi * 60 + mi <= va * 60 + ma) t = va * 60 + ma - vi * 60 - mi;
    else t = 24 * 60 - vi * 60 - mi + va * 60 + ma;
return t;
}
//---------------------------------------------
void Trukme(int v1, int m1, int v2, int m2, int v3, int m3, int v4, int m4, int &v, int &m){
   long t;
   if ((v3 == 0) && (m3 == 0) && (v4 == 0) && (m4 == 0)) t = Trukme1(v1, m1, v2, m2);
   else t = Trukme1(v1, m1, v2, m2) + Trukme1(v3, m3, v4, m4);
   v = t / 60;
   m = t % 60;
}
