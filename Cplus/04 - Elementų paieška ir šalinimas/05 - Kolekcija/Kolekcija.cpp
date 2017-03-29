#include <iostream>
#include <fstream>
using namespace std;
const int CMax = 1001;
int ausra[CMax], ruta[CMax], a = 0, r = 0;
bool buveskaiciai[CMax];
void Skaityti();
int Zenkluskaicius(string savininke, int skaicius);
int main()
{
    ofstream fr("Rezultatas.txt");
    for(int i=0;i<=CMax;i++) buveskaiciai[i] = false;
    Skaityti();
    for(int i=1;i<=a;i++) {
        if(Zenkluskaicius("Ausra", ausra[i]) > 1) {
            if(Zenkluskaicius("Ruta", ausra[i]) == 0) {
                if(buveskaiciai[ausra[i]] == false) {
                    fr << ausra[i] << endl;
                    buveskaiciai[ausra[i]] = true;
                }
            }
        }
    }
    return 0;
}

void Skaityti()
{
    ifstream f1("Ausra.txt");
    ifstream f2("Ruta.txt");
    for(int i=1; i <= CMax; i++) { ausra[i] = 0; ruta[i] = 0;}
    f1 >> a;
    f2 >> r;
    for(int i=1; i <= a; i++) f1 >> ausra[i];
    for(int i=1; i <= r; i++) f2 >> ruta[i];
}

int Zenkluskaicius(string savininke, int skaicius)
{
    int kiekis = 0;
    if(savininke == "Ausra") {
        for(int i=1;i<=a;i++) {
            if(ausra[i] == skaicius) kiekis++;
        }
    }
    else if(savininke == "Ruta") {
        for(int i=1;i<=r;i++) {
            if(ruta[i] == skaicius) kiekis++;
        }
    }
    return kiekis;
}

