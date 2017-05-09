// Ilgiausia kelionė
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
//---------------------------------------------
struct Marsrutai {
         string pav;
         int    t;
};
//---------------------------------------------
struct Etapas {
          string pav;
          int t;
          int tt;
          string M[100];
};
//---------------------------------------------
void Skaitymas(Etapas E[], int & n);
int Didziausia(Marsrutai M[], int t);
void Rasymas(Etapas E[], int n);
//---------------------------------------------
int main ()
{
  int  n;
  Etapas E[1000];
  Skaitymas(E, n);
  Rasymas(E, n);
  return 0;
}
//---------------------------------------------
int Didziausia(Marsrutai M[], int t) {
  int m = 0;
  for (int i = 0; i < t; i++)
    if (M[i].t > M[m].t) m = i;
    return m;
}
//---------------------------------------------
void Skaitymas(Etapas E[], int & n)
{
  char eil[21]; char eil1[16]; int v, m, d, t; Marsrutai M[100];
  ifstream fd (CDfv);
  fd >> n;
  fd.ignore(80, '\n');
  for (int i = 0; i < n; i++) {
    fd.get(eil, 20);
    E[i].pav = eil;
    fd >> t;
    fd.ignore(80, '\n');
    for (int j = 0; j < t; j++) {
        fd.get(eil1, 15);
        M[j].pav = eil1;
        fd >> v >> m;
        M[j].t = v * 60 + m;
        fd.ignore(80, '\n');
    }
    d = Didziausia(M, t);
    E[i].tt = 0;
    for (int j = 0; j < t; j++)
        if (M[j].t == M[d].t) {
        E[i].M[E[i].tt] = M[j].pav;
        E[i].t = M[j].t;
        E[i].tt++;
        }

  }
  fd.close();
}

void Rasymas(Etapas E[], int n)
{
  ofstream fr (CRfv);
  for (int i = 0; i < n; i++){
    fr << E[i].pav << E[i].t / 60 << " " << E[i].t % 60 << endl;
    for (int j = 0; j < E[i].tt; j++)
       fr << E[i].M[j] << endl;
  }
  fr.close();
}
