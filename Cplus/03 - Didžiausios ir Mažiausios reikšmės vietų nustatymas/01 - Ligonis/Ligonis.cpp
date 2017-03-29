#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n, valanda[24], auksciausiavalanda = 0;
    double temperatura[24], auksciausia = 0;
    ifstream fd("Duomenys.txt");
    ofstream fr("Rezultatas.txt");
    fd >> n;
    fr << "Ligonio temperatura" << endl;
    fr << "-------------------" << endl;
    fr << " Valanda Temperatura" << endl;
    fr << "-------------------" << endl;
    for(int i = 0; i < n; i++)
    {
        fd >> valanda[i];
        fd >> temperatura[i];
        fr << setw(5)<< valanda[i] << "     " << temperatura[i] << endl;
    }
    for(int i = 0; i < n; i++)
    {
        if(temperatura[i] > auksciausia)
        {
            auksciausia = temperatura[i];
            auksciausiavalanda = valanda[i];
        }
    }
    fr << fixed << setprecision(1) << "Auksciausia temperatura " << auksciausia << " buvo " << auksciausiavalanda << " val." << endl;
    fr << "Auksta temperatura dar buvo: " << endl;
    for(int i = 0; i < n; i++)
    {
        if(auksciausia - temperatura[i] <= 0.5 && auksciausia - temperatura[i] >= -0.5)
        {
            fr << valanda[i] << " val. " << temperatura[i] << endl;
        }
    }
    return 0;
}
