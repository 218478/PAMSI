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
   /*! \brief Funkcja, gdzie odbywa sie zapis phonebook'a do tablicy haszowej.
   *
   * \details Podczas wykonywania tej funkcji uruchamiany jest Stoper oraz
   *          wypelniany jest element klasy HashTable po uprzednim jej
   *          przygotowaniu. Slowa pobiera z tego samego slownika co lista.
   *
   * \param[in] how_many  Informacja iloma elementami ma zostac wypelniona
   *                      tablica.
   */
  void setOffHashTable(int how_many);

  void setOffGraphDFS(int how_many);

  void setOffGraphBFS(int how_many);
};

#endif  // LAB03_14_03_PRJ_INC_SEDZIA_H_
