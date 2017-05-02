#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
struct Marsrutai {
	string pav;
	int iv, im;
	int av, am;
	long t;
} M[100];
int n;
void Skaito();
void Raso();
long Trukme(int iv, int im, int av, int am);
long Visa(Marsrutai M[], int n);
int main() {
	Skaito();
	Raso();
	return 0;
}
void Skaito() {
	char eil[21];
	ifstream fd("Duomenys.txt");
	fd >> n;
	fd.ignore(80, '\n');
	for(int i = 1; i <= n; i++) {
		fd.get(eil, 20);
		M[i].pav = eil;
		fd >> M[i].iv >> M[i].im >> M[i].av >> M[i].am;
		M[i].t = Trukme(M[i].iv, M[i].im, M[i].av, M[i].am);
		fd.ignore(80, '\n');
	}
}

long Trukme(int iv, int im, int av, int am){
    int t;
    if (iv * 60 + im < av * 60 + am) t = av * 60 + am - iv * 60 - im;
    else t = 24 * 60 - iv * 60 - im + av * 60 + am;
    return t;
}

void Raso() {
	ofstream fr("Rezultatai.txt");
	for(int i = 1; i <= n; i++) {
		cout << M[i].pav << " ";
		if (M[i].t % 60 < 10) cout << M[i].t / 60 << " 0" << M[i].t % 60 << endl;
	    else cout << M[i].t / 60 << " " << M[i].t % 60 << endl;
	}
	cout << Visa(M, n) / 60 << " " << Visa(M,n) % 60 << endl;
}

long Visa(Marsrutai M[], int n) {
	long v = 0;
	for(int i = 1; i < n; i++) {
		v = v + M[i].t + Trukme(M[i].av, M[i].am, M[i+1].iv, M[i+1].im);
	}
	return v;
}
