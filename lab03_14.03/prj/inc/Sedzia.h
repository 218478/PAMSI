// Copyright 2016 Kamil Kuczaj
#ifndef LAB03_14_03_PRJ_INC_SEDZIA_H_
#define LAB03_14_03_PRJ_INC_SEDZIA_H_

#include <string>    // to deal with strings

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
   *
   * \retval true Wyscig zakonczony.
   */
  bool setOffTable(int how_many);

  /*! \brief Funkcja, w ktorej odbywa sie pomiar czasu szukania w liscie.
   *
   * \details Losuje how_many slow a potem znajduje wylosowany.
   *
   * \retval true Wyscig zakonczony.
   */
  bool setOffList(int how_many);

  /*! \brief Losuje slowo ze slownika.
   *
   * \details Wybiera slow z pelnego zakresu slownika.
   *
   * \return Losowe slowo typu string.
   */
  std::string getRandomWordFromTheDict(int how_many);
};

#endif  // LAB03_14_03_PRJ_INC_SEDZIA_H_
