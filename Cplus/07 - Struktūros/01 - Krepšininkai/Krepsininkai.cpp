#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;
ifstream fd("Duomenys.txt");
ofstream fr("Rezultatas.txt");

const int CMax = 30;

struct Mokinys {
    string vardas;
    float ugis;
    int taskai;
};

void Skaityti(Mokinys A[], int & n, int & p, int & k, int & du, int & dt);
void Spausdinti(Mokinys A[], int & n, int & p, int & k, int & du, int & dt);

int main() {
    Mokinys A[CMax]; int n, p, k, du = 0, dt = 0;
    Skaityti(A, n, p, k, du, dt);
    Spausdinti(A, n, p, k, du, dt);
    return 0;
}

void Skaityti(Mokinys A[], int & n, int & p, int & k, int & du, int & dt) {
    fd >> n;
    for(int i = 1; i <= n; i++) {
        fd >> A[i].vardas >> A[i].ugis >> A[i].taskai;
        //cout << A[i].vardas << " " << " " << A[i].ugis << " " << A[i].taskai << endl;
        if(A[i].ugis > du) du = A[i].ugis;
        if(A[i].taskai > dt) dt = A[i].taskai;
    }
    fd >> p >> k;
    //cout << p << " " << k << endl;
}

void Spausdinti(Mokinys A[], int & n, int & p, int & k, int & du, int & dt) {
    cout << "----------------------------------------" << endl;
    cout << "Vardas          Ugis          Taskai" << endl;
    cout << "----------------------------------------" << endl;
    for(int i = 1; i <= n; i++) {
        if()
    }
}
