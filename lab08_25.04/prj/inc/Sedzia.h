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
  /*! \brief Funkcja, w ktorej odbywa sie zapis intow.
   *
   * \details Podczas wykonywania tej funkcji uruchamiany jest Stoper oraz
   *          wypelniany jest element klasy Tablica po uprzednim jej
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

  /*! \brief Funkcja, w ktorej odbywa sie zapis stringow do stosu.
   *
   * \details Podczas wykonywania tej funkcji uruchamiany jest Stoper oraz
   *          wypelniany jest element klasy Stos po uprzednim jej
   *          przygotowaniu. Slowa pobiera z tego samego slownika co lista.
   *
   * \param[in] how_many  Informacja iloma elementami ma zostac wypelniona
   *                      tablica.
   */
  void setOffStack(int how_many);

   /*! \brief Funkcja, w ktorej odbywa sie zapis stringow do kolejki.
   *
   * \details Podczas wykonywania tej funkcji uruchamiany jest Stoper oraz
   *          wypelniany jest element klasy Kolejka po uprzednim jej
   *          przygotowaniu. Slowa pobiera z tego samego slownika co lista.
   *
   * \param[in] how_many  Informacja iloma elementami ma zostac wypelniona
   *                      tablica.
   */
  void setOffQueue(int how_many);

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

  void setOffGraphDFS(int how_many);

  void setOffGraphBFS(int how_many);
};

#endif  // LAB03_14_03_PRJ_INC_SEDZIA_H_
