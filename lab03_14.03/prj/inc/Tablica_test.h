// Copyright 2016 Kamil Kuczaj
#ifndef TABLICA_TEST_H
#define TABLICA_TEST_H

#include "Tablica.h"
#include "IRunnable.h"
#include <iostream>     // to deal with displaying messages

class Tablica_test: IRunnable {
 private:
  Tablica arr;
 public:
/*! \brief Implementacja funkcji prepare() interfesju IRunnable.
   *
   * \details Zapisuje pozadany rozmiar do pola desired_size.
   *
   * \param size Parametr typu unsigned int, gdyz rozmiar nie powinien nigdy byc
   *             ujemny. Jego wartosc zapisywana jest do pola desired_size.
   */
  virtual void prepare (int size) { arr.setDesiredSize(size); }

  /*! \brief Implementacja funkcji run() interfesju IRunnable.
   *
   * \details Uruchamia "bieg", w ktorym nastepuje zapis elementow do
   *          poszczegolnych elementow tablicy dynamicznej. Tam odbywa sie
   *          alokacja pamieci oraz instrukcje warunkowe.
   */
  virtual void run() {
    for(int index = 0; index < arr.getDesiredSize(); index++) {
      if(arr.isFull())
	      arr.increaseSize();
	      
	   try {
      arr[index] = 123;
	   }
	   catch (const char* message) {
	     std::cout << message << std::endl;
	   }
    }
  }
 
};

#endif