// Copyright 2016 Kamil Kuczaj
#ifndef LAB03_14_03_PRJ_INC_LISTA_H_
#define LAB03_14_03_PRJ_INC_LISTA_H_

#include "ILista.h"


#include <cstddef>   // to use the NULL macro
#include <string>    // to deal with words saving and searching
#include <iostream>  // to print the contents of the list
#include <fstream>   // to deal with loading words from the dictionary
#include <algorithm>    // std::iter_swap
#include <vector>   // to simulate dynamic array because mine sucks

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
template <class Type>
class Lista: ILista<Type> {
 private:
   /*! \brief Zawartosc listy
   */
  std::vector<Type> list;

  /*! \brief Wskazuje na ineks nastepny wolny wezel.
   *
   * \details Wskazuje na indeks wezel, do ktorego moga zostac zaladowane dane.
   */
  int next_free;

 public:
  /*! \brief Wstawia element w dowolnym miejscu listy.
   *
   * \details Wstawia element typu Type w miejsce wskazywane przez zmienna
   *          index. Wyjatki:
   *          "Index out of bounds" (const char*) - chcesz zapisac na miejscu
   *                                                poza lista
   *
   * \param[in] item Element wstawiany. Slowo typu string.
   * \param[in] index Miejsce, w ktore ma byc wstawiony element item.
   */
  virtual void add(Type item, int n) {
    int sz = list.size();
    if (n > sz)
      throw("Index out of bounds");

    if (sz == 0 || sz == n) {
      list.push_back(item);
      return;
    }

    if (n < sz) 
      list.emplace(list.begin()+n, item);
  }

  /*! \brief Dodaje element na samym koncu listy.
   *
   * \details Uzyteczne i bardzo wygodne, gdzy taki sam mechanizm
   *              stosuje sie w bibliotece STL.
   */
  virtual void push_back(Type item) {
    add(item, list.size());
  }

  /*! \brief Usuwa element z dowolnego miejsca listy.
   *
   * \details Usuwa element z miejsca wskazywanego przez zmienna index.
   *
   * \return Zwraca slowo, ktore znajdowalo sie na tym indeksie.
   */
  virtual Type remove(int n) {
    Type word;
    int size = list.size();

    if (size == 0)
      throw("List is empty");
    if (n < size) {
      word = list[n];
      for (int i = n; i < size; i++)
        list[i] = list[i+1];
    } else
      throw("Index out of bounds");

    list.erase(list.end()-1);
    next_free--;
    return word;
  }


  /*! \brief Sprawdza czy lista jest pusta.
   *
   * \details Sprawdza czy w liscie sa jakies elementy.
   *
   * \retval true Lista jest pusta.
   * \retval false Lista nie jest pusta.
   */
  virtual bool isEmpty() {
    if (list.size() > 0)
      return false;
    else
      return true; }

  /*! \brief Zwraca element z dowolnego miejsca listy.
   *
   * \details Zwraca element z miejsca wskazywanego przez zmienna index.
   *          Wyjatki sa typu: const char *
   *          "Empty list"          - pusta lista
   *          "Index out of bounds" - przekroczono zakres, nie ma tylu elementow
   *
   * \return Zwraca element typu std::string.
   */
  virtual Type get(int n) {
    Type temp;
    int size = list.size();

    if (size == 0)
      throw("Empty list");

    if (n < size) {
          temp = list[n];
    } else {
      throw("Index out of bounds"); }

    return temp;
  }

  /*! \brief Zwraca rozmiar listy.
   *
   * \details Zwraca ilosc elementow w liscie.
   *
   * \return Rozmiar listy.
   */
  virtual int size() { return list.size(); }

  /*! \brief Wypisuje zawartosc listy.
   *
   * \details Wypisuje kazdy element listy w osobnej linii.
   *          Na gorze znajduje sie poczatek listy.
   */
  void print() {
    for (Type& e: list)
      std::cout << e << std::endl;
  }

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
  int search(Type searched_word) {
    int index;

    if (isEmpty())
      return -1;  // list is empty

    for (index = 0; index < size(); index++) {
      if (list[index] == searched_word)
        return index;
    }

    return -2;   // we didn't find anything
  }
};

#endif  // LAB03_14_03_PRJ_INC_LISTA_H_
