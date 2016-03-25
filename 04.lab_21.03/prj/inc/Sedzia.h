#ifndef SEDZIA_H
#define SEDZIA_H

#include "Stoper.h"
#include "Tablica.h"
#include "Lista.h"

#include <iostream>
#include <iomanip>
#include <sstream> // to convert int to string
#include <string>  // to deal with strings
#include <cstdlib>   // to deal with drawing random word from the dictionary

/*! \file Sedzia.h
 *
 * \brief Naglowek opisujacy implementacje Sedziego.
 * \author Kamil Kuczaj
 */


/*! \brief Skraca zapis.
 *
 * \details Zdefiniowanie wlasnego typu - pozwala na krotszy zapis
 */
typedef unsigned int uint;


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
  bool setOffTable(uint how_many);

  /*! \brief Funkcja, w ktorej odbywa sie pomiar czasu szukania w liscie.
   *
   * \details Losuje how_many slow a potem znajduje wylosowany.
   *
   * \retval true Wyscig zakonczony.
   */
  bool setOffList (uint how_many);

  /*! \brief Losuje slowo ze slownika.
   *
   * \details Wybiera slow z pelnego zakresu slownika.
   *
   * \return Losowe slowo typu string.
   */
  std::string getRandomWordFromTheDict(uint how_many);

  /*! \brief Odpala bubble sort tablicy intow.
   *
   * \details Bubble sort.
   *
   * \param[in] how_many Ile intow ma byc wczytane i posortowane.
   *                     W przedziale 1-100;
   */
  void setOffBubbleSortArray(int how_many) {
    Tablica<int> tab;
    try {
      tab.bubbleSort(how_many); }
    catch (const char *message) {
      std::cout << message << std::endl;
    }
    }
};

#endif
