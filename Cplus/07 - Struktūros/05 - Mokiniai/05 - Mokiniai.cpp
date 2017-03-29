#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;
ifstream fd("Duom2.txt");
ofstream fr("Rez2.txt");
int n, p;
double v;
struct mokiniai {
    string vp;
    int pazymiai[15];
} m[20];
void Skaityti();
double Vidurkis(int mokinys);
int Pirmunai();
int main() {
    Skaityti();
    cout << endl << setprecision(3) << Vidurkis(1) << endl;
    cout << Pirmunai();
    return 0;
}
void Skaityti() {
    fd >> n >> p >> v;
    char simb[20];
    fd.ignore();
    for(int i = 1; i <= n; i++) {
        fd.get(simb, 20);
        m[i].vp = simb;
        cout << m[i].vp
        for(int z = 1; z <= p; z++) {
            fd >> m[i].pazymiai[z];
            cout << m[i].pazymiai[z] << " ";
        }
        cout << endl;
    }
}

double Vidurkis(int mokinys)
{
   int skaicius;
   for(int i = 1; i <= p; i++) {
        skaicius += m[mokinys].pazymiai[i];
   }
   return skaicius / p;
}

int Pirmunai()
{
    int skaicius = 0;
    for(int i = 1; i <= n; i++) {
        if(Vidurkis(i) >= v) {
            skaicius++;
            cout << skaicius << endl;
        }
    }
    return skaicius;
}
