#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int
        namai[500],
        nskaicius,
        laikinaskintamasis,
        gyventojaisuma = 0,
        kairiojipuse = 0,
        desiniojipuse = 0,
        kairiojipusenamuskaicius = 0,
        desiniojipusenamuskaicius = 0;
    double
        kairiojipusevidurkis = 0.0,
        desiniojipusevidurkis = 0.0;

    ifstream fd("Duomenys.txt");                            // atidarome faila
    fd >> nskaicius;                                        // paimam pirmojo kintamojo reiksme, siuo atveju namu skaicius
    for ( int i = 0; i < nskaicius; i++ )                   // ciklas is visu esanciu namu
    {
      fd >> laikinaskintamasis;                             // pasiimam namo skaiciu
      fd >> namai[laikinaskintamasis];                      // pasiimam to namo gyventoju skaiciu
      gyventojaisuma += namai[laikinaskintamasis];          // prie visos gyventoju sumos pridedame to namo gyventoju skaiciu
      if(laikinaskintamasis % 2 == 0) {                     // tikriname ar namas dalijasi is dvieju, jei taip vadinasi jis yra desineje puseje
        desiniojipuse += namai[laikinaskintamasis];         // i desiniu namu puse pridedam gyventoju skaiciu
        desiniojipusenamuskaicius ++;                       // i globalu desinios puses namu kintamaji pridedame +1 nama
      }
      else {                                                // jeigu namas ne desineje, vadinasi kaireje
        kairiojipuse += namai[laikinaskintamasis];          // i kairiu namu puse pridedam gyventoju skaiciu
        kairiojipusenamuskaicius ++;                        // i globalu kairios puses namu kintamaji pridedame +1 nama
      }
    }
    fd.close(); // uzdarome faila
    kairiojipusevidurkis = (float)kairiojipuse / (float)kairiojipusenamuskaicius;               // apskaiciuojame kairios puses namu vidurki
    desiniojipusevidurkis = (float)desiniojipuse / (float)desiniojipusenamuskaicius;            // apskaiciuojame desinios puses namu vidurki
    ofstream fr("Rezultatas.txt");                                                              // atidarome rezultatu faila
    fr << "Is viso gyventoju gatveje: " << gyventojaisuma << endl;                              // spausdiname
    fr << "Is viso gyventoju kairiojoje gatves puseje: " << kairiojipuse << endl;               // spausdiname
    fr << "Is viso gyventoju desiniojoje gatves puseje: " << desiniojipuse << endl;             // spausdiname
    fr << "Vidutinis gyventoju skaicius name, esanciame kairiojoje gatves puseje: " << fixed << setprecision(2) << kairiojipusevidurkis << endl; // spausdiname
    fr << "Vidutinis gyventoju skaicius name, esanciame desiniojoje gatves puseje: " << fixed  << setprecision(2) << desiniojipusevidurkis << endl; //spausdiname
    fr.close();                                                                                 // uzdarome faila

    return 0;
}
