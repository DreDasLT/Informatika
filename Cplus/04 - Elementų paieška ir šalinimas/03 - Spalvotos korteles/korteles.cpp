#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

struct korteliu_struct {
    char raide;
    int skaicius;
} korteles[104];
int k = 0;
int main()
{
    ifstream fd("Duomenys.txt");
    ofstream fr("Rezultatas.txt");
    fd >> k;
    for(int i = 1; i <= k; i++) {
        fd >> korteles[i].raide;
        fd >> korteles[i].skaicius;
        //cout << korteles[i].raide << " " << korteles[i].skaicius << endl;
    }
    for(int i=1;i<=k;i++) {
        if(korteles[i].raide == 'G') {
            for(int y=1; y<=k;y++) {
                if(korteles[y].raide == korteles[i].raide && korteles[i].skaicius+1 == korteles[y].skaicius+1)
                {
                    cout << korteles[y].raide << " " << korteles[y].skaicius << " ";
                }
            }
        }
    }
    return 0;
}
