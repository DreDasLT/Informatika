#include <iostream>
#include <fstream>
using namespace std;
const int CMax = 101;
int n, m, varztai[CMax], verzles[CMax]; bool tekstas = false;
void Skaityti();
int SkaiciuotiKieki(string tipas, int skersmuo);
int main() {
    Skaityti();
    for(int i = 2; i <= 20; i++) {
        if(SkaiciuotiKieki("varztai", i) < SkaiciuotiKieki("verzles", i)) {
            if(tekstas == false) cout << "Reikalingi varztai:" << endl, tekstas = true;
            cout << SkaiciuotiKieki("verzles", i) - SkaiciuotiKieki("varztai", i) << " " << i << endl;
        }
    }
    if(tekstas == false) {
        cout << "Varztu nereikia" << endl;
    }
    tekstas = false;
    for(int i = 2; i <= 20; i++) {
        if (SkaiciuotiKieki("varztai", i) > SkaiciuotiKieki("verzles", i)) {
            if(tekstas == false) cout << "Reikalingos verzles:" << endl, tekstas = true;
            cout << SkaiciuotiKieki("varztai", i) - SkaiciuotiKieki("verzles", i) << " " << i << endl;
        }
    }
    if(tekstas == false) {
        cout << "Verzliu nereikia" << endl;
    }
    return 0;
}

void Skaityti()
{
    ifstream fd("Duomenys.txt");
    for(int i = 1; i < CMax; i++) {
        varztai[i] = 0; verzles[i] = 0;
    }
    fd >> n;
    for(int i = 1; i <= n; i++) {
        fd >> varztai[i];
    }
    fd >> m;
    for(int i = 1; i <= m; i++) {
        fd >> verzles[i];
    }
}

int SkaiciuotiKieki(string tipas, int skersmuo)
{
   int kiekis = 0;
   if(tipas == "varztai") {
       for(int i = 1; i <=n; i++) {
            if(varztai[i] == skersmuo) kiekis++;
       }
   }
   else if(tipas == "verzles") {
       for(int i = 1; i <=m; i++) {
            if(verzles[i] == skersmuo) kiekis++;
       }
   }
   return kiekis;
}

