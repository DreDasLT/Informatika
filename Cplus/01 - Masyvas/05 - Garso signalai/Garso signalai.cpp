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
    ifstream fd("Duomenys.txt");                                            // Duomenø failas
    fd >> n;                                                                // Eiluèiø iðgavimas
    fd >> k;                                                                // Elementø skaièius eilutëje
    for(int i = 0; i < n; i++) {                                            // Ciklas ið eiluèiø
        for(int x = 1; x <= k; x++) {                                       // Antras ciklas ið kiekvieno elemento eilutëje
            fd >> masyvas[i][x];                                            // Iðgauname eilutës elementà ið failo
        }
    }
    ofstream fr("Rezultatas.txt");                                          // Rezultato failas
    for(int i = 0; i < n; i++) {                                            // Ciklas ið eiluèiø
        for(int x = 1; x <= k; x++) {                                       // Antras ciklas ið kiekvieno elemento eilutëje
            if(x == 1) {                                                    // Jeigu elementas yra pirmas
                masyvas1[i][x] = (masyvas[i][x] + masyvas[i][x+1]) / 2;     // Pirmàjá elementà pakeièiame jo ir gretimo skaièiaus vidurkiu
            }
            else if(x == k) {                                               // Jeigu elementas yra paskutinis
                masyvas1[i][x] = (masyvas[i][x] + masyvas[i][x-1]) / 2;     // Paskutinájá elementà pakeièiame jo ir gretimo skaièiaus vidurkiu
            }
            else {                                                          // Jeigu elementas nei pirmas nei paskutinis
                masyvas1[i][x] = (masyvas[i][x] + masyvas[i][x-1] + masyvas[i][x+1]) / 3; // Elementà pakeièiame jo ir dviejø ðalia jo esanèiø skaièiø vidurkiu
            }
            fr << masyvas1[i][x] << " ";                                                  // Spausdiname pakeisto elemento reikðmæ á failà
        }
        fr << endl;                                                                       // Elementø sekai pasibaigus faile padarome naujà eilutæ
    }
    return 0;
}
