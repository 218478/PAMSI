#ifndef POJEMNIK_H
#define POJEMNIK_H

#include <new> // dla sprawdzenia poprawnosci alokacji pamieci
#include <iostream> // dla wyswietlenia bledu

class pojemnik  {
 private:
  int *elementy;
  unsigned long rozmiar;
  unsigned long indeks;

 public:
  pojemnik(int x=10);

  ~pojemnik();

  bool czy_pelne();

  void zapisz(int dana);
  
  int zwieksz_rozmiar();
  
  unsigned long zwroc_rozmiar();

  // w celu debuggowania
  void wypisz();
};

#endif
