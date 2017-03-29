#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main()
{
    int n,
        S[3000],
        Y[3000],
        M[3000],
        D[3000],
        numeris[3000];
    char c[7];
    long long int skaicius;
    ifstream fd("Duomenys.txt");
    ofstream fr("Rezultatas.txt");
    fd >> n;
    cout << n << endl;
    for(int i = 0; i < n; i++)
    {
        /*fd >> skaicius;
        S[i] = div(skaicius, 10);
        cout << S[i] << endl;*/
        for(int z = 0; z < 7; z++)
        {
            fd >> c[z];
            if(z == 0) S[i] = c[z];

        }
        cout << S[i];
        cout << endl;

    }
    return 0;
}
