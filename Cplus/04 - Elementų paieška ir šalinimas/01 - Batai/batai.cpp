#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    int batudydziai[500], batai = 0;
    char batutype[500];
    ifstream fd("Duomenys.txt");
    ofstream fr("Rezultatas.txt");
    fd >> batai;
    fr << "Batu sarasas" << endl;
    fr << "--------------" << endl;
    fr << " Tipas  Dydis " << endl;
    fr << "--------------" << endl;
    for(int i = 0; i < batai; i++) {
        fd >> batutype[i];
        fd >> batudydziai[i];
        fr << "   " << batutype[i] << "     " << batudydziai[i] << endl;
    }
    fr << "--------------" << endl;
    for(int i = batai; i > 0; i--) {
        if(batutype[i] == 'v' && batudydziai[i] == 43)
        {
            fr << "Mykolo 43-io dydzio batu indeksas masyve " << i << endl;
            for(int z = i; z <= batai; z++) {
                batudydziai[z] = batudydziai[z+1];
            }
            batai --;
            break;
        }
    }
    for(int i = batai; i > 0; i--) {
        if(batutype[i] == 'm' && batudydziai[i] == 38)
        {
            fr << "Marytes 38-o dydzio batu indeksas masyve " << i << endl;
            for(int z = i; z <= batai; z++) {
                batudydziai[z] = batudydziai[z+1];
            }
            batai --;
            break;
        }
    }
    fr << " Batu sarasas" << endl;
    fr << "--------------" << endl;
    fr << " Tipas  Dydis " << endl;
    fr << "--------------" << endl;
    for(int i = 0; i < batai; i++) {
        fr << "   " << batutype[i] << "     " << batudydziai[i] << endl;
    }
    return 0;
}
