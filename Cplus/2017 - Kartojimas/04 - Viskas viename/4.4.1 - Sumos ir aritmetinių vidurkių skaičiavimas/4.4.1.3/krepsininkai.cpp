#include <iomanip>
#include <fstream>
using namespace std;
ifstream fd("Duomenys.txt");
ofstream fr("Rezultatai.txt");
double kg[100], m[100], ka, kr, kb;
int a,r,b, n, kcal[100];
void Skaito();
double Vidurkis(double a[100]);
void Verte(int i, double & ka, double & kr, double & kb);
void Raso();
int main() {
    Skaito();
    Raso();
    return 0;
}
void Skaito() {
     fd >> a >> r >> b >> n;
     for(int i = 1; i <= n; i++) {
         fd >> kg[i] >> m[i] >> kcal[i];
     }
}
double Vidurkis(double a[100]) {
    double suma = 0;
    for(int i = 1; i <= n; i++) {
        suma += a[i];
    }
    return suma / n;
}

void Verte(int i, double & ka, double & kr, double & kb) {
    kb = (double)(b * kcal[i]) / 100;
    kr = (double)(r * kcal[i]) / 100;
    ka = (double)(a * kcal[i]) / 100;
}

void Raso() {
    for(int i = 1; i <= n; i++) {
        Verte(i, ka, kr, kb);
        fr << fixed << setprecision(2) << ka << " " << kr << " " << kb << endl;
    }
    fr << fixed << setprecision(1) << Vidurkis(kg) << " " << setprecision(2) << Vidurkis(m) << endl;
}
