#include <fstream>
using namespace std;
ifstream fd("Duomenys.txt");
ofstream fr("Rezultatas.txt");
int n, d, z, k, dt = 1, zt, zt1;
int main() {
    fd >> n >> d >> z >> k;
    zt = z;
    while(zt1 <= n) {
        dt++;
        zt = zt + k;
        zt1 += zt;
    }
    string ats = (dt < d) ? "TAIP" : "NE";
    fr << dt << endl << ats << endl;
    return 0;
}
