// Kolekcijos
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;
const char CDfv[] = "Duomenys10_u2.txt";
const char CD1fv[] = "Duomenys10_u2_1.txt";
const char CRfv[] = "Rezultatai10_u2.txt";
const int CMax    = 1001;
//-------------------------------------------------------------------
void Skaityti(const char fv[], int A[], int & n);
void Spausdinti(const char fv[], string z, int A[], int n);
int IeskotiKur(int A[], int n, int k);
void IterptiSkaiciu(int A[], int & n, int sk, int ind);
void Salinti(int A[], int & n, int ind);
void Tvarkyti(int A[], int B[], int & m, int & n, int k);
//-------------------------------------------------------------------
int main()
{
   int Rs[CMax]; int Rm[CMax];
   int rsn; int rmn;
   Skaityti(CDfv, Rs, rsn);
   Skaityti(CD1fv, Rm, rmn);
   ofstream fr;
   Tvarkyti(Rm, Rs, rsn, rmn, 10);
   Tvarkyti(Rs,Rm, rmn, rsn, 100);
   fr.open(CRfv); fr.close();
   Spausdinti(CRfv, "Rasos kolekcija: ", Rs, rsn);
   Spausdinti(CRfv, "Rimo kolekcija: ", Rm, rmn);
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
void Spausdinti(const char fv[], string z, int A[], int n)
{
   ofstream fr(fv, ios::app); // atidaromas iðvesties srautas papildyti
   fr << z << endl;
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
void Salinti(int A[], int & n, int ind)
{
   for (int i = ind; i <= n; i++)
      A[i] = A[i+1];
   n--;
}
//-------------------------------------------------------------------
void Tvarkyti(int A[], int B[], int & m, int & n, int k)
{
   int i = 0; int x;
   while (i < n) {
      if (A[i] / k != 0) {
         x = IeskotiKur(B, m, A[i]);
         IterptiSkaiciu(B, m, A[i], x);
         Salinti(A, n, i);
      }
      else i++;
   }
}
