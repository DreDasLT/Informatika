#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int p, n, lentynos[50][50], prekiuskaicius[50],prekes = 0, didz[50], didz1 = 0, didz1masyv = 0;
    ifstream fd("Duomenys.txt"); ofstream fr("Rezultatas.txt"); fd >> p; fd >> n;
    for(int i=1; i<=n; i++) {
        fd >> prekiuskaicius[i];
        for(int z=1; z<=prekiuskaicius[i]; z++) {
            fd >> lentynos[i][z];
            if(lentynos[i][z] > didz[i]) {
                didz[i] = lentynos[i][z];
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(p >= didz[i]) {
            prekes ++;
            p -= didz[i];
        } else {
            for(int y=1; y<=prekiuskaicius[i]; y++) {
                if(p >= lentynos[i][y] && lentynos[i][y] >= didz1) {
                    didz1 = lentynos[i][y];
                    didz1masyv = y;
                }
            }
            if(didz1masyv != 0) {
                prekes++;
                p -= lentynos[i][didz1masyv];
                break;
            }
        }
    }
    fr << prekes << " " << p << endl;
    return 0;
}
