// Trumpiausios kelionės
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const char CDfv[] = "Duomenys.txt";
const char CRfv[] = "Rezultatai.txt";
//---------------------------------------------
struct Marsrutai {
         string pav;
         int    v, m;
};
//---------------------------------------------
struct Etapas {
          string pav;
          int t;
          Marsrutai M[100];
};
//---------------------------------------------
void Skaitymas(Etapas E[], int & n);
void Rikiavimas(Marsrutai M[], int n);
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
void Rikiavimas(Marsrutai M[], int n) {
  int m; Marsrutai t;
  for (int i = 0; i < n - 1; i++){
    m = i;
    for (int j = i + 1; j < n; j++)
       if (M[j].v * 60 + M[j].m < M[m].v * 60 + M[m].m) m = j;
    t = M[i]; M[i] = M[m]; M[m] = t;
  }
}
//---------------------------------------------
void Skaitymas(Etapas E[], int & n)
{
  char eil[21]; char eil1[16]; Marsrutai M[100];
  ifstream fd (CDfv);
  fd >> n;
  fd.ignore(80, '\n');
  for (int i = 0; i < n; i++) {
    fd.get(eil, 20);
    E[i].pav = eil;
    fd >> E[i].t;
    fd.ignore(80, '\n');
    for (int j = 0; j < E[i].t; j++) {
        fd.get(eil1, 15);
        M[j].pav = eil1;
        fd >> M[j].v >> M[j].m;
        fd.ignore(80, '\n');
    }
    Rikiavimas(M, E[i].t);
    for (int j = 0; j < E[i].t; j++) {
        E[i].M[j].pav = M[j].pav;
        E[i].M[j].v = M[j].v;
        E[i].M[j].m = M[j].m;
    }
  }
  fd.close();
}
//---------------------------------------------
void Rasymas(Etapas E[], int n)
{
  ofstream fr (CRfv);
  for (int i = 0; i < n; i++){
    fr << E[i].pav << endl;
    for (int j = 0; j < E[i].t; j++)
       fr << E[i].M[j].pav << E[i].M[j].v << " " << E[i].M[j].m << endl;
  }
  fr.close();
}
