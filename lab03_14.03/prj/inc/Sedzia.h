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
   * \param[in] how_many  Informacja iloma elementami ma zostac wypelniona
   *                      tablica.
   */
  void setOffTable(int how_many);

  /*! \brief Funkcja, w ktorej odbywa sie pomiar czasu szukania w liscie.
   *
   * \details Losuje how_many slow a potem znajduje wylosowany.
   *
   * \param[in] how_many     Ilosc slow jaka ma zostac wczytana do listy.
   * \param[in] trials_count Ile razy ma zostac wylosowane slowo ze slownika
   *                         oraz ile razy ma zostac podjeta proba znalezenia
   *                         go w liscie.
   */
  void setOffList(int how_many, int trials_count);
};

#endif  // LAB03_14_03_PRJ_INC_SEDZIA_H_
