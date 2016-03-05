#ifndef POJEMNIK_H
#define POJEMNIK_H

#include <new> // dla sprawdzenia poprawnosci alokacji pamieci
#include <iostream> // dla wyswietlenia bledu

class pojemnik  {
  int *elementy;
  unsigned int rozmiar;
  unsigned int indeks;

 public:

  pojemnik(int x=10);

  ~pojemnik();

  bool czy_pelne();

  void zapisz(int dana);
  
  int zwieksz_rozmiar();
  
  int zwroc_rozmiar();


};

#endif
