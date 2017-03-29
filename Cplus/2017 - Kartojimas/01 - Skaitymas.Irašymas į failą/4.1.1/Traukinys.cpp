#include <iostream>
#include <fstream>
#include <iomanip>


void Skaito(int a, int b, int c, int d, int v, int m);
using namespace std;

int main() {
    int a,b,c,d, v, m;
    Skaito(a, b, c, d, v, m);
    return 0;
}

void Skaito(int a, int b, int c, int d, int v, int m) {
    ifstream fd("Duomenys.txt");
    ofstream fr("Rezultatai.txt");
    fd >> a >> b >> c >> d;

    int atvykimas, p;
    atvykimas = ((a*60) + b) + ((c*60) + d);

    if(atvykimas > 24*60) {
        p = c / 24;
        if(p == 0) p = 1;
        v = (atvykimas - (24*p*60)) / 60;
        m = (atvykimas - (24*p*60)) - v * 60;
        fr << v << " " << m;
    } else {
        v = atvykimas / 60;
        m = atvykimas - v * 60;
        fr << v << " " << m;
    }
}
