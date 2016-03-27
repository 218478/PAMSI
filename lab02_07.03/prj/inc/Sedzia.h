// Copyright 2016 Kamil Kuczaj
#ifndef LAB02_07_03_PRJ_INC_SEDZIA_H_
#define LAB02_07_03_PRJ_INC_SEDZIA_H_

#include "Stoper.h"
#include "Tablica.h"

#include <iostream>
#include <sstream>   // to convert int to string
#include <string>    // to deal with strings
#include <cstdlib>   // to deal with drawing random word from the dictionary

/*! \file Sedzia.h
 *
 * \brief Naglowek opisujacy implementacje Sedziego.
 * \author Kamil Kuczaj
 */

/*! \brief Implementacja klasy Sedzia.
 *
 * \details Sedzia wykorzystuje elementy klasy Stoper oraz klasy Tablica.
 *          Mierzy czas wypelniania elemntow Tablicy.
 */
class Sedzia {
 public:
  /*! \brief Funkcja, w ktorej odbywa sie bieg.
   *
   * \details Podczas wykonywania tej funkcji uruchamiany jest Stoper oraz
   *          wypelniany jest element klasy TablicA po uprzednim jej
   *          przygotowaniu.
   *
   * \param how_many Informacja iloma elementami ma zostac wypelniona tablica.
   * \retval true Wyscig zakonczony.
   */
  bool setOffTable(int how_many);
};

#endif  // LAB02_07_03_PRJ_INC_SEDZIA_H_
