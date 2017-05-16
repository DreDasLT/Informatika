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
double Pigiausia(double sb, double sd);

int main() {
	Skaitymas();
	Rasymas();
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
	}
}

void Rasymas() {
	ofstream fr("Rezultatai.txt");
	double sb, sd, sum;
	sb = (b * (m/2)) / 100;
	sd = (d * (m/2)) / 100;
	double p = Pigiausia(sb, sd);
	fr << p << endl;
	for(int i = 0; i<n; i++) {
		sum = sb * D[i].bk + sd * D[i].dk;
		if(sum == p) fr << D[i].pav << " " << D[i].bk << " " << D[i].dk << endl;
	}
}

double Pigiausia(double sb, double sd) {
	double sum = sb * D[0].bk + sd * D[0].dk, sum1, sum2;
	for(int i=0;i<n-1;i++) {
		sum1 = sb * D[i].bk + sd * D[i].dk;
		sum2 = sb * D[i+1].bk + sd * D[i+1].dk;
		if(sum1 >= sum2 ) sum = sum2;
	}
	return sum;
}
