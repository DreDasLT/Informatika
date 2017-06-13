#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;
//////////////////////////////
double ak, bk, rk; int n;

struct darzoves {
	string pav;
	double a,b,r,ev,bevk,revk,vkp;
} D[10];
//////////////////////////////
void Skaito();
int Didziausias();
int Maziausias();
void Raso();

int main() {
	Skaito();
	return 0;
}

void Skaito() {
	char a[15];
	ifstream fd("Duomenys.txt");
	fd >> ak >> bk >> rk >> n;
	for(int i = 1; i <= n; i++) {
		fd.ignore();
		fd.get(a, 15);
		D[i].pav = a;
		fd >> D[i].a >> D[i].b >> D[i].r;
		//cout << D[i].pav << D[i].a << " " << D[i].b << " " << D[i].r << endl;
		D[i].ev = D[i].a * ak + D[i].b * bk + D[i].r * rk;
		D[i].bevk = D[i].b * bk;
		D[i].revk = D[i].r * rk;
		D[i].vkp = 100 - D[i].a - D[i].b - D[i].r;
		//cout << D[i].ev << " " << D[i].bevk << " " << D[i].revk << " " << D[i].vkp << endl;
	}
}

double Didziausias()
