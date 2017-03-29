#include <iostream>
#include <fstream>
using namespace std;
ifstream fd("Duomenys.txt");
ofstream fr("Rezultatai.txt");
int n, a, b, c;
int Tikrinti(int a, int b, int c);
int main() {

    fd >> n;
    for(int i = 1; i <= n; i++) {
        fd >> a >> b >> c;
        if(Tikrinti(a,b,c) == 1) fr << a << " + " << b << " = " << c << endl;
        if(Tikrinti(a,b,c) == 2) fr << a << " - " << b << " = " << c << endl;
        if(Tikrinti(a,b,c) == 3) fr << a << " * " << b << " = " << c << endl;
        if(Tikrinti(a,b,c) == 4) fr << a << " / " << b << " = " << c << endl;
        if(Tikrinti(a,b,c) == 0) fr << a << "  "  << b << "  " << c << " KLAIDINGA " << endl;
    }
    return 0;
}

int Tikrinti(int a, int b, int c) {
    if(a + b == c) return 1;
    else if(a - b == c) return 2;
    else if(a*b == c) return 3;
    else if(a/b == c) return 4;
    return 0;
}
