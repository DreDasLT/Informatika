#include <fstream>
#include <iomanip>
using namespace std;
ifstream fd("Duomenys.txt");
ofstream fr("Rezultatai.txt");
int s, v, k, p[20], n, m[20];
double ks[20], kv[20];

void Skaito();
void Raso();
double Kaina(int i);
int Pigiausia();

int main() {
	Skaito();
	Raso();
	return 0;
}

void Skaito() {
	fd >> s >> v >> k >> n;
	for(int i = 1; i <= n; i++) fd >> ks[i] >> kv[i] >> p[i];
}

void Raso() {
	for(int i = 1; i <=n; i++) fr << i << " " << fixed << setprecision(2) << Kaina(i) << endl;
	fr << Pigiausia() << endl;
}

double Kaina(int i) {
	double kaina = 0;
	if(s+v > k) kaina = (double)(s * (ks[i] - ((ks[i] * p[i]) / 100))) + (v * (kv[i] - ((kv[i] * p[i]) / 100)));
	else kaina = (double)(s * ks[i]) + (v * kv[i]);
	return kaina;
}

int Pigiausia() {
	int x = 0;
	for(int i = 1; i < n; i++) {
		if(Kaina(i) < Kaina(i+1)) x = i;
	}
	return x;
}
