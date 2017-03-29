#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int CMax = 1000;
int RaD, Rasa[CMax], RiD, Rimas[CMax];

void Skaityti();
void Iterpti(string zmogus, int indeksas, int skaicius);
void Salinti(string zmogus, int indeksas);
void Spausdinti();
int TikrintiSkaiciu(int skaicius); // 0 - dvizenklis 1 - trizenklis
int RastiVietaMasyve(string zmogus, int skaicius);

ifstream fdRa("Rasa.txt");
ifstream fdRi("Rimas.txt");
ofstream fr("Rezultatas.txt");

int main() {
    Skaityti();
    Spausdinti();
    int i = 1;
    while(i <= RaD) {
        if(TikrintiSkaiciu(Rasa[i]) == 1) {
           int x = RastiVietaMasyve("Rimas", Rasa[i]);
           cout << "Skaicius: " << Rasa[i] << "ID: " << i << "Vieta pas Rima: " << x << "Is viso daiktu pas Rasa: " << RaD << endl;
           Iterpti("Rimas", x, Rasa[i]);
           Salinti("Rasa", i);
           Spausdinti();
           i = 1;
        }
        i++;
    }
    i = 1;
    while(i <= RiD) {
        if(TikrintiSkaiciu(Rimas[i]) == 0) {
           int x = RastiVietaMasyve("Rasa", Rimas[i]);
           cout << "Skaicius: " << Rimas[i] << "ID: " << i << "Vieta pas Rasa: " << x << "Is viso daiktu pas Rima:" << RiD <<  endl;
           Iterpti("Rasa", x, Rimas[i]);
           Salinti("Rimas", i);
           Spausdinti();
           i = 1;
        }
        i++;
    }
    Spausdinti();
    return 0;
}

void Skaityti() {
    fdRa >> RaD;
    for(int i = 1; i <= RaD; i++)
        fdRa >> Rasa[i];
    fdRi >> RiD;
    cout << endl;
    for(int i = 1; i <= RiD; i++)
        fdRi >> Rimas[i];
}


void Iterpti(string zmogus, int indeksas, int skaicius) {
    if(zmogus == "Rasa") {
        RaD++;
        for(int i = RaD; i >= indeksas;i--) {
            if(i == indeksas) {
                Rasa[i+1] = Rasa[i];
                Rasa[i] = skaicius;
            } else {
                Rasa[i+1] = Rasa[i];
            }
        }
        cout << "Iterpiame i Rasos kolekcija: " << indeksas << " Skaicius: " << skaicius << endl;
    }
    if(zmogus == "Rimas") {
        RiD++;
        for(int i = RiD; i >= indeksas;i--) {
            if(i == indeksas) {
                Rimas[i+1] = Rimas[i];
                Rimas[i] = skaicius;
            } else {
                Rimas[i+1] = Rimas[i];
            }
        }
        cout << "Iterpiame i Rimo kolekcija: " << indeksas << " Skaicius: " << skaicius << endl;
    }
}

void Salinti(string zmogus, int indeksas) {
    if(zmogus == "Rasa") {
        RaD--;
        for(int i = indeksas; i <= RaD;i++) {
            Rasa[i] = Rasa[i+1];
        }
        cout << "Saliname is Rasos kolekcijos indeksa: " << indeksas << endl;
    }
    if(zmogus == "Rimas") {
        RiD--;
        for(int i = indeksas; i <= RiD;i++) {
            Rimas[i] = Rimas[i+1];
        }
        cout << "Saliname is Rimo kolekcijos indeksa: " << indeksas << endl;
    }
}

void Spausdinti() {
    for(int i = 1; i <= RaD; i++) cout << " " << Rasa[i];
    cout << endl;
    for(int i = 1; i <= RiD; i++) cout << " " << Rimas[i];
    cout << endl;
}

int TikrintiSkaiciu(int skaicius) {
    if(skaicius >= 10 && skaicius <= 99) return 0;
    else if(skaicius >= 100 && skaicius <= 999) return 1;
}

int RastiVietaMasyve(string zmogus, int skaicius) {
    if(zmogus == "Rasa") {
        for(int i = 1; i <= RaD; i++) {
            if(Rasa[i] >= skaicius) return i;
        }

        return RaD-1;
    }
    if(zmogus == "Rimas") {
        for(int i = 1; i <= RiD; i++) {
            if(Rimas[i] >= skaicius) return i;
        }
        return RiD-1;
    }
}
