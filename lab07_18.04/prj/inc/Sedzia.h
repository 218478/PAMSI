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
   /*! \brief Funkcja, w ktorej odbywa sie zapis liczb do drzewa.
   *
   * \details Podczas wykonywania tej funkcji uruchamiany jest Stoper oraz
   *          wypelniany jest element klasy BinaryTree po uprzednim jej
   *          przygotowaniu. Liczby sa generowane w sposob pseudo losowy.
   *
   * \param[in] how_many  Informacja iloma elementami ma zostac wypelniona
   *                      kontener.
   */
  void setOffBinaryTree(int how_many);
};

#endif  // LAB03_14_03_PRJ_INC_SEDZIA_H_
