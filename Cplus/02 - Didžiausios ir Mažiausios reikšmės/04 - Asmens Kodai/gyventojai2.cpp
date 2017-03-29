// Gyventojai
#include <iostream>
#include <fstream>
using namespace std;
const int CMax = 100;
//---------------------------
void Skaityti(int Vm[],int Vmen[], int Vd[], int Mm[], int Mmen[], int Md[], int & kv, int & km);
int Vyriausias(int X[], int Y[], int Z[], int k);
string Keitimas(int a);
//---------------------------
int main()
{
   int Vm[CMax];int Vmen[CMax]; int Vd[CMax]; int Mm[CMax]; int Mmen[CMax]; int Md[CMax]; int kv, km, vn, mn;
   ofstream fr("Rezultatai7_u3.txt");
   Skaityti(Vm, Vmen, Vd, Mm, Mmen, Md, kv, km);

   if ((kv != 0) && (km != 0)) { 
      vn = Vyriausias (Vm, Vmen, Vd, kv); mn = Vyriausias (Mm, Mmen, Md,km);
      fr << "Vyriausias vyras gim� " << Vm[vn] << " " << Keitimas(Vmen [vn] )<< " " << Vd [vn] << endl;
      fr << "Vyriausia moteris gim� " << Mm[mn] << " " << Keitimas(Mmen [mn]) << " " << Md [mn] << endl;
   }
   else if ((kv != 0) && (km == 0)) { 
      vn = Vyriausias (Vm, Vmen, Vd, kv);
      fr << "Vyriausias vyras gim� " << Vm[vn] << " " << Keitimas(Vmen [vn]) << " " << Vd [vn] << endl;
      fr << "Moter� n�ra " << endl;
   }
   else if ((kv == 0) && (km != 0)) { 
      mn = Vyriausias (Mm, Mmen, Md,km );
      fr << "Vyr� n�ra " << endl;
      fr << "Vyriausia moteris gim� " << Mm[mn] << " " << Keitimas(Mmen [mn]) << " " << Md [mn] << endl;
   }
   else if ((kv == 0) && (km == 0)) {
      fr << "Vyr� n�ra " << endl;
      fr << "Moter� n�ra "<< endl;
   }
   fr.close();
   return 0;
}
//--------------------
void Skaityti(int Vm[],int Vmen[], int Vd[], int Mm[], int Mmen[], int Md[], int & kv, int & km)
{
   long long x; int n;
   kv = 0;
   km = 0;
   ifstream fd("Duomenys7_u3.txt");
   fd >> n;
   for (int i = 1; i <= n; i++) {
      fd >> x;
      if ((x / 10000000000==3)||(x / 10000000000==5)) {
         kv = kv + 1;
         if (x / 10000000000==3)
            Vm[kv] = (x / 100000000 % 100) + 1900;
         else Vm[kv] = (x / 100000000 % 100) + 2000;
         Vmen[kv] = x / 1000000 % 100;
         Vd[kv] = x / 10000 % 100;
      }
      else {
         km = km + 1;
         if (x / 10000000000==4)
            Mm[km] = (x / 100000000 % 100) + 1900;
         else Mm[km] = (x / 100000000 % 100) + 2000;
         Mmen[km] = x / 1000000 % 100;
         Md[km] = x / 10000 % 100;
      }
   }
   fd.close();
}

int Vyriausias(int X[], int Y[], int Z[], int k)
{
   int m, i;
   m = 1;
   for (int i = 1; i <= k; i ++)
      if (X[i] < X[m]) m = i;
      else if ((X[i] == X[m])&&(Y[i] < Y[m])) m = i;
      else if ((X[i] == X[m])&&(Y[i] == Y[m])&&(Z[i] < Z[m])) m = i;
   return m;
}

string Keitimas(int a)
{
   string b;
   if (a == 1) b = "sausio";
   if (a == 2) b = "vasario";
   if (a == 3) b = "kovo";
   if (a == 4) b = "baland�io";
   if (a == 5) b = "gegu��s";
   if (a == 6) b = "bir�elio";
   if (a == 7) b = "liepos";
   if (a == 8) b = "rugpj��io";
   if (a == 9) b = "rugs�jo";
   if (a == 10) b = "spalio";
   if (a == 11) b = "lapkri�io";
   if (a == 12) b = "gruod�io";
   return b;
}
