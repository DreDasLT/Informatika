#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;

struct grybautojai {
    string vardas;
    int b, r, l;

}g[100];

int n = 0, d = 0;
ifstream fd("U2.txt");
ofstream fr("U2rez.txt");

void Skaityti();

int main()
{
    Skaityti();
    return 0;
}

void Skaityti()
{
    fd >> n;
    cout << n << endl;
    int b1, r1, l1;
    for(int i = 1; i <= n; i++) {
        fd >> g[i].vardas;
        fd >> d;
        cout << g[i].vardas << "   " << d;
        for(int z = 1; z <= d; z++) {
            fd >> b1 >> r1 >> l1;
            g[i].b += b1;
            g[i].r += r1;
            g[i].l += l1;
        }
    }
}
