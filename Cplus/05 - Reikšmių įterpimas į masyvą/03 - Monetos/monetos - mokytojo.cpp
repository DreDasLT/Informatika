// Monetos
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;
const char CDfv[] = "Duomenys10_u3.txt";
const char CD1fv[] = "Duomenys10_u3_1.txt";
const char CRfv[] = "Rezultatai10_u3.txt";
const int CMax    = 1001;
//-------------------------------------------------------------------
void Skaityti(const char fv[], int A[], int & n);
void Spausdinti(const char fv[], int A[], int n);
int IeskotiKur(int A[], int n, int k);
void IterptiSkaiciu(int A[], int & n, int sk, int ind);
//-------------------------------------------------------------------
int main()
{
   int D[CMax]; int kur;
   int n; int gr; int k;
   Skaityti(CDfv, D, n);
   ifstream fd(CD1fv);
   fd >> gr;
   for (int i = 1; i <= gr; i++) {
      fd >> k;
      kur = IeskotiKur(D, n, k);
      IterptiSkaiciu(D, n, k, kur);
   }
   fd.close();
   ofstream fr;
   fr.open(CRfv); fr.close();
   Spausdinti(CRfv, D, n);
   fr.close();
   return 0;
}
//-------------------------------------------------------------------
// Skaito duomenis ið failo fv á masyvà A(n)
void Skaityti(const char fv[], int A[], int & n)
{
   ifstream fd(fv); // atidaromas ávesties srautas
   fd >> n; // perskaitomas masyvo reikðmiø kiekis
   for (int i = 0; i < n; i++)
      fd >> A[i];
   fd.close(); // uþdaromas ávesties srautas
}
//-------------------------------------------------------------------
void Spausdinti(const char fv[], int A[], int n)
{
   ofstream fr(fv, ios::app); // atidaromas iðvesties srautas papildyti
   for (int i = 0; i < n; i++)
      fr << A[i] << " ";
   fr << endl;
}
//-------------------------------------------------------------------
int IeskotiKur(int A[], int n, int k)
{
   int i = 0;
   while ((i < n) && (A[i] < k)) i++;
   return i;
}
//-------------------------------------------------------------------
void IterptiSkaiciu(int A[], int & n, int sk, int ind)
{
   for (int i = n-1; i >= ind; i--)
      A[i+1] = A[i];
   A[ind] = sk;
   n++;
}
//-------------------------------------------------------------------
