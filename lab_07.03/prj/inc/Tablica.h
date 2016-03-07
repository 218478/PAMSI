#ifndef TABLICA_H
#define TABLICA_H

#include <new> // dla sprawdzenia poprawnosci alokacji pamieci
#include <iostream> // dla wyswietlenia bledu

class Tablica  {
 private:
  int *elementy;
  unsigned long rozmiar;
  unsigned long indeks;

 public:
  Tablica(int x=10);

  ~Tablica();

  bool czy_pelne();

  void zapisz(int dana);
  
  int zwieksz_rozmiar();
  
  unsigned long zwroc_rozmiar();

  // w celu debuggowania
  void wypisz();
};

#endif
