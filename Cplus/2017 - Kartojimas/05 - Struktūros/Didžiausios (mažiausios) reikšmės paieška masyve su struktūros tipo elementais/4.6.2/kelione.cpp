#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
double b, d, m; int n;
struct degalines {
	string pav;
	double bk, dk;
}D[10];

void Skaitymas();
void Rasymas();
int Pigiausia();

int main() {
	Skaitymas();
	return 0;
}

void Skaitymas() {
	char a[15];
	ifstream fd("Duomenys.txt");
	fd >> b >> d >> m >> n;
	for(int i = 0;i<n; i++) {
		fd.ignore();
		fd.get(a, 15);
		D[i].pav = a;
		fd >> D[i].bk >> D[i].dk;
		cout << D[i].pav << " " << D[i].bk << " " << D[i].dk << endl;
	}
}

void Rasymas() {

}

int Pigiausia() {
	for(int i=0;i<n;i++) {
		if(D[i].bk)
	}
}
