// Copyright 2016 Kamil Kuczaj
#ifndef LAB03_14_03_PRJ_INC_STOS_TEST_H_
#define LAB03_14_03_PRJ_INC_STOS_TEST_H_

#include "IRunnable.h"
// #include "Stos.h"

class Stos_test: IRunnable {
 private:
  //  Stos stack;

 public:
  /*! \brief Przygotowuje pojemnik przed wykonaniem czynnosci.
   *
   * \details Funkcja, ktora ma wykonac wszystkie dodatkowe czynnosci,
   *          ktorych czasu nie bedziemy mierzyc. Polega ona na
   *          wczytaniu konkretnej ilosci elementow.
   *
   * \param[in] size Ilosc elementow.
   */
  virtual void prepare(int size);

  /*! \brief Odpalenie badanej czynnosci.
   *
   * \details Funkcja, ktorej cialem maja byc instrukcje, ktorych czas
   *          chcemy zmierzyc.
   */
  virtual void run();
};

#endif  // LAB03_14_03_PRJ_INC_STOS_TEST_H_
