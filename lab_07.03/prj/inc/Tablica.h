#ifndef TABLICA_H
#define TABLICA_H

#include "IRunnable.h"

#include <new> // dla sprawdzenia poprawnosci alokacji pamieci
#include <iostream> // dla wyswietlenia bledu

class Tablica: IRunnable  {
 private:
  int *elementy;
  unsigned int rozmiar;
  unsigned int indeks;

 public:
  Tablica(int x=10);

  ~Tablica();

};

#endif
