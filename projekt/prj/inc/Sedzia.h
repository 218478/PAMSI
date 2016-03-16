#ifndef SEDZIA_H
#define SEDZIA_H

#include "Stoper.h"
#include "Tablica.h"

#include <iostream>
#include <iomanip>


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
   */
  bool setOff(unsigned int how_many);

};

#endif
