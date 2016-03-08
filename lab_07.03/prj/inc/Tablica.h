#ifndef TABLICA_H
#define TABLICA_H

#include "IRunnable.h"

#include <new> // dla sprawdzenia poprawnosci alokacji pamieci
#include <iostream> // dla wyswietlenia bledu

class Tablica: IRunnable  {
 private:
  int *elements;
  unsigned int current_size, desired_size, index;
  

  bool isFull();

 public:
  Tablica(int x=10);

  ~Tablica();

  virtual void prepare (unsigned int size);

  virtual void run();

  unsigned int getSize();
 
  void increaseSize();

};

#endif
