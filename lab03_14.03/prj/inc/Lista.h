// Copyright 2016 Kamil Kuczaj
#ifndef LAB03_14_03_PRJ_INC_LISTA_H_
#define LAB03_14_03_PRJ_INC_LISTA_H_

#include "ILista.h"

#include <cstddef>   // to use the NULL macro
#include <string>    // to deal with words saving and searching
#include <iostream>  // to print the contents of the list
#include <fstream>   // to deal with loading words from the dictionary

/*! \file Lista.h
 *
 * \brief Implementacja jednokierunkowej listy.
 *
 * \details Ze wzledu na komplikacje implementacji mechanizmow przy uzyciu
 *          szablonow, zdecydowalem sie je usunac z konstrukcji programu.
 *
 * \author Kamil Kuczaj.
 */


/*! \brief Klasa Lista, ktora symuluje zachowanie klasy list z biblioteki STL.
 *
 * \details Zajmuje sie dynamiczna alokacja pamieci. Lista jest jednokierunkowa.
 *          Mamy dostep do pierwszego elementu w liscie
 */
class Lista: ILista {
 private:
  /*! \brief Imlementacja wezlow dla listy.
   *
   * \details Potrzebne do implementacji interfejsu listy. Zawiera pole
   *          typu string.
   */
  struct Node {
    /*! \brief Element w wezle.
     *
     * \details Co jest w wezle. Ma przechowywac pojedyncze slowo.
     */
    std::string element;

    /*! \brief Wskaznik na nastepny wezel.
     *
     * \details Wskazuje na nastepny wezel.
     */
    Node* next;
  };


  /*! \brief Pierwszy element listy.
   *
   * \details Wskazuje na pierwszy element listy.
   */
  Node *head;

  /*! \brief Przechowuje rozmiar listy.
   *
   * \details Dzieki zastosowaniu tej zmiennej, o wiele latwiej debugowac Lista.
   *          Pozwala to na kontrole mechanizmow sprawdzania. Powinien byc
   *          zawsze dodatni.
   */
  int size_of_list;

 public:
  /*! \brief Konstruktor.
   *
   * \details Tworzy poczatek listy. Alokuje dla niego pamiec.
   */
  Lista();

  /*! \brief Destruktor.
   *
   * \details Usuwa cala pamiec listy "skaczac" po jej elementach.
   */
  ~Lista();

  /*! \brief Wstawia element w dowolnym miejscu listy.
   *
   * \details Wstawia element typu Type w miejsce wskazywane przez zmienna index.
   *
   * \param[in] item Element wstawiany. Slowo typu string.
   * \param[in] index Miejsce, w ktore ma byc wstawiony element item.
   */
  virtual void add(std::string item, int index);

  /*! \brief Usuwa element z dowolnego miejsca listy.
   *
   * \details Usuwa element z miejsca wskazywanego przez zmienna index.
   *
   * \return Zwraca slowo, ktore znajdowalo sie na tym indeksie.
   */
  virtual std::string remove(int index);

  /*! \brief Sprawdza czy lista jest pusta.
   *
   * \details Sprawdza czy w liscie sa jakies elementy.
   *
   * \retval true Lista jest pusta.
   * \retval false Lista nie jest pusta.
   */
  virtual bool isEmpty();

  /*! \brief Zwraca element z dowolnego miejsca listy.
   *
   * \details Zwraca element z miejsca wskazywanego przez zmienna index.
   *          Wyjatki sa typu: const char *
   *          "Empty list"          - pusta lista
   *          "Index out of bounds" - przekroczono zakres, nie ma tylu elementow
   *
   * \return Zwraca element typu std::string.
   */
  virtual std::string get(int index);

  /*! \brief Zwraca rozmiar listy.
   *
   * \details Zwraca ilosc elementow w liscie.
   *
   * \return Rozmiar listy.
   */
  virtual int size();

  /*! \brief Wypisuje zawartosc listy.
   *
   * \details Wypisuje kazdy element listy w osobnej linii.
   *          Na gorze znajduje sie poczatek listy.
   */
  void print();

  /*! \brief Wyszukuje podane slowo i zwraca jego indeks
  *
  * \details Wyszukuje w liscie podane slowo ypu std::string. Zwraca liczbe,
  *          ktora reprezentuje indeks z podanym slowem.\
  *
  * \param[in] searched_word Szukane slowo.
  *
  * \retval -1 Lista pusta.
  * \retval -2 Nie ma takiego elementu w liscie.
  *
  * \return Indeks, na ktorym znajduje sie szukane slowo.
  */
  int search(std::string searched_word);
};

#endif  // LAB03_14_03_PRJ_INC_LISTA_H_
