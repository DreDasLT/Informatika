#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;
ifstream fd("Duomenys.txt");
ofstream fr("Rezultatai.txt");

int main() {
    double m, n, k, s, kk;
    fd >> k >> m >> kk >> n;
    s = ((k / 100) * m * kk) / n;
    fr << fixed << setprecision(1) << s << endl;
    return 0;
}
