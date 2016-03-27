#include <iostream>
#include <chrono> // requires C++11 standard
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
  chrono::time_point<chrono::system_clock> start, stop;


  start = chrono::system_clock::now();
  for(unsigned long i=0; i < ilosc; i++) {
    kontener.zapisz(123);
  }
  //  kontener.wypisz(); // for debug
  stop = chrono::system_clock::now();
  chrono::duration<double> elapsed_seconds = stop - start;
  cout << setw(15) << kontener.zwroc_rozmiar() << " el."
       << setw(20) << elapsed_seconds.count()*1000 << showpoint <<" ms" << endl;
}
