#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

ifstream fd("Duomenys.txt");
ofstream fr("Rezultatai.txt");

string eilutes[100];
int n;

void Skaityti();
void Rikiuoti();
void Spausdinti();

int main()
{
    Skaityti();
    Rikiuoti();
    Spausdinti();
    return 0;
}

void Skaityti()
{
    fd >> n;
    fr << "------------------------------" << endl;
    fr << "Pradiniai duomenys" << endl;
    fr << "------------------------------" << endl;
    for(int i = 0; i <= n; i++) {
        getline(fd, eilutes[i]);
        fr << eilutes[i] << endl;
    }

}

void Rikiuoti()
{
    for(int i = 0; i <= n; i++) {
        for(int z = 0; z <= n; z++) {
            if(eilutes[i] < eilutes[z]) {
                string laikinas = eilutes[z];
                eilutes[z] = eilutes[i];
                eilutes[i] = laikinas;
            }
        }
    }
}

void Spausdinti()
{
    fr << "------------------------------" << endl;
    fr << "Surikiuoti duomenys" << endl;
    fr << "------------------------------" << endl;
    for(int i = 0; i <= n; i++) {
        fr << eilutes[i] << endl;
    }
}
