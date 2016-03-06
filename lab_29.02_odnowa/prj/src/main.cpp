#include <iostream>
#include <ctime>
#include <iomanip>
#include "pojemnik.h"

using namespace std;

void zapiszDoPojemnika(unsigned long ilosc);

int main(int argc, char **argv) {
  // dziesiec, tysiac, sto tysiecy, milion, milard
  unsigned int rozmiary_danych [5]= {10,1000,100000,1000000,1000000000};

  for(int i = 0; i < 5; i++)
    zapiszDoPojemnika(rozmiary_danych[i]);
}

void zapiszDoPojemnika(unsigned long ilosc) {
  pojemnik kontener;

  clock_t start = clock();
  for(unsigned long i=0; i < ilosc; i++) {
    kontener.zapisz(123);
  }

  //  kontener.wypisz();

  clock_t koniec = clock();
  float czas = float(koniec - start)/CLOCKS_PER_SEC*100000;
  cout << setw(15) << kontener.zwroc_rozmiar() << " el."
       << setw(20) << czas/100.0 << " ms" << endl;
}
