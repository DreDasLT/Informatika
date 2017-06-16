#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;

struct staciakampiai {
    int x, y, dx, dy, r, g, b;
} S[101];
void Skaito(int & n);
void Raso();

int main() {
    int n;
    Skaito(n);
    Raso();
    return 0;
}

void Skaito(int & n) {
    ifstream fd("U2.txt");
    fd >> n;
    for(int i = 1; i <= n; i++) {
        fd >> S[i].x >> S[i].y >> S[i].dx >> S[i].dy >> S[i].r >> S[i].g >> S[i].b;
    }
}

void Raso() {
    ofstream fr("U2rez.txt");
}
