#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
    int
        n = 0,
        k = 1,
        masyvas[50][50],                                                    // Pradiniai duomenys
        masyvas1[50][50];                                                   // Galutiniai duomenys
    ifstream fd("Duomenys.txt");                                            // Duomen� failas
    fd >> n;                                                                // Eilu�i� i�gavimas
    fd >> k;                                                                // Element� skai�ius eilut�je
    for(int i = 0; i < n; i++) {                                            // Ciklas i� eilu�i�
        for(int x = 1; x <= k; x++) {                                       // Antras ciklas i� kiekvieno elemento eilut�je
            fd >> masyvas[i][x];                                            // I�gauname eilut�s element� i� failo
        }
    }
    ofstream fr("Rezultatas.txt");                                          // Rezultato failas
    for(int i = 0; i < n; i++) {                                            // Ciklas i� eilu�i�
        for(int x = 1; x <= k; x++) {                                       // Antras ciklas i� kiekvieno elemento eilut�je
            if(x == 1) {                                                    // Jeigu elementas yra pirmas
                masyvas1[i][x] = (masyvas[i][x] + masyvas[i][x+1]) / 2;     // Pirm�j� element� pakei�iame jo ir gretimo skai�iaus vidurkiu
            }
            else if(x == k) {                                               // Jeigu elementas yra paskutinis
                masyvas1[i][x] = (masyvas[i][x] + masyvas[i][x-1]) / 2;     // Paskutin�j� element� pakei�iame jo ir gretimo skai�iaus vidurkiu
            }
            else {                                                          // Jeigu elementas nei pirmas nei paskutinis
                masyvas1[i][x] = (masyvas[i][x] + masyvas[i][x-1] + masyvas[i][x+1]) / 3; // Element� pakei�iame jo ir dviej� �alia jo esan�i� skai�i� vidurkiu
            }
            fr << masyvas1[i][x] << " ";                                                  // Spausdiname pakeisto elemento reik�m� � fail�
        }
        fr << endl;                                                                       // Element� sekai pasibaigus faile padarome nauj� eilut�
    }
    return 0;
}
