// Copyright 2016 Kamil Kuczaj
#ifndef LAB03_14_03_PRJ_INC_LISTA_TEST_H_
#define LAB03_14_03_PRJ_INC_LISTA_TEST_H_

#include "Lista.h"
#include "IRunnable.h"

#include <string>    // to deal with string words


class Lista_test: IRunnable {
 private:
  Lista<std::string> list;

 public:
/*! \brief Szuka elementu.
   *
   * \details Szuka elementu wskazanego przez uzytkownika. W funkcji nastepuje
   *          Segmentation fault, gdy probujemy znalezc element, ktorego tam
   *          nie ma. W ogole sposob kodowania bledow gdy na nie napotka jest
   *          debilny ale nie mialem wystarczajaco duzo czasu aby to przerobic.
   *
   * \param[in] desired_element Poszukiwana fraza.
   *
   * \retval >0         Znalazl element i wyswietlil.
   * \retval -1         Nie znalazl i nie wyswietlil elementu.
   * \retval -2         Lista pusta.
   */
  virtual void run();

  /*! \brief Zapisuje liste slowami.
   *
   * \details Zapisuje liste slowami zaczerpnietymi ze slownika. !!! WAZNE !!!!
   *          Funkcja powinna byc uzyta tylko na poczatku, gdy cala lista jest
   *          pusta. Inaczej nastapi nadpisanie elementow poczatkowych.
   *
   * \param[in] desired_size Ile elementow ma zostac wczytanych.
   */
  virtual void prepare(int desired_size);

  /*! \brief Losuje slowo ze slownika.
   *
   * \details Wybiera slow z pelnego zakresu slownika.
   *
   * \return Losowe slowo typu string.
   */
  std::string getRandomWordFromTheDict();
};

#endif  // LAB03_14_03_PRJ_INC_LISTA_TEST_H_
