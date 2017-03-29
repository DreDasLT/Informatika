#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;

void Skaityti();
void PirmaEilute();
int AntraEilute();
void RastiStoti();
int ApsilankeStotyje(int id);

const int q = 1000;
const int n = 100;
int stationid[q], stationday[q], entered[q], exit[q];
int m;
int EsanciosStotys[n];
ifstream fd("U1.txt");
ofstream fr("U1rez.txt");

int main()
{
    Skaityti();
    PirmaEilute();
    return 0;
}

void Skaityti()
{
    fd >> m;
    for(int i = 1; i <= m; i++) {
        fd >> stationid[i];
        fd >> stationday[i];
        fd >> entered[i];
        fd >> exit[i];
        EsanciosStotys[stationid[i]] = 1;
        //cout << stationid[i] << " " << stationday[i] << " " << entered[i] << " " << exit[i] << endl;
    }
}

void PirmaEilute()
{
    int temp[4];
    for(int i = 1; i <= m; i++) {
        for(int z = i+1; z <= m; z++) {
            if(stationid[z] <= stationid[i]) {
                temp[0] = stationid[i];
                temp[1] = stationday[i];
                temp[2] = entered[i];
                temp[3] = exit[i];
                stationid[i] = stationid[z];
                stationday[i] = stationday[z];
                entered[i] = entered[z];
                exit[i] = exit[z];
                stationid[z] = temp[0];
                stationday[z] = temp[1];
                entered[z] = temp[2];
                exit[z] = temp[3];
            }
        }
        if(EsanciosStotys[stationid[i]] == 1) {
            //cout << stationid[i] << "    ";
            EsanciosStotys[stationid[i]] = 2;
        }
    }
    cout << endl;
    for(int i = 1; i <= m; i++) {
        if(EsanciosStotys[stationid[i]] == 2) {
            ApsilankeStotyje(stationid[i]);
            EsanciosStotys[stationid[i]] = 0;
        }
    }
}

int ApsilankeStotyje(int id)
{
    int suma = 0;
    for(int i = 1; i <= m; i++) {
        if(stationid[i] == id) {
            cout << "Stoteles ID" << " " << id << " " << entered[id]<< endl;

            suma += entered[i];
        }
    }
    return suma;
}
