// Copyright 2016 Kamil Kuczaj
#ifndef LAB03_14_03_PRJ_INC_LISTA_H_
#define LAB03_14_03_PRJ_INC_LISTA_H_

#include "ILista.h"
#include "Tablica.h"

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
template <class Type>
class Lista: ILista<Type> {
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
    Type element;

    /*! \brief Wskaznik na nastepny wezel.
     *
     * \details Wskazuje na nastepny wezel.
     */
    Node* next;
  };

  /*! \brief Zawartosc listy
   */
  Array<Node> list;

  /*! \brief Glowa listy.
   *
   * \details Wskazuje zawsze na pierwszy element listy.
   */
  Node *head;

  /*! \brief Wskazuje nastepny wolny wezel.
   *
   * \details Wskazuje na wezel, do ktorego moga zostac zaladowane dane.
   */
  int next_free;

 public:
  /*! \brief Konstruktor.
   *
   * \details Tworzy poczatek listy. Alokuje dla niego pamiec.
   */
  Lista()  { head = &list[0]; next_free = 0;}

  /*! \brief Destruktor.
   *
   * \details Usuwa cala pamiec listy "skaczac" po jej elementach.
   */
  // ~Lista() { list.~Array(); }

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
    std::cout << "Adres glowy: " << head << std::endl;

    if (n > next_free)  // if we want to add an element beyond list
      throw("Index out of bounds");

    if (isEmpty()) {  // if the list is empty
      list[0].element = item;
      list[0].next = 0;
      head = &list[0];

    } else {  // and when it's not empty
      if (n == 0) {  // when we adding at the beginning
        list[next_free].next = head;
        head = &list[next_free];
      } else {
        Node *conductor = head;

        if (n < next_free) {  // when inserting
          for (int i = 0; i < (n-1); i++)
            conductor = conductor->next;

          list[next_free].next = conductor->next;
          list[next_free].element = item;
          conductor->next = &list[next_free];
        }

        if (n == next_free) {  // when adding at the end
          for (int i = 0; i < (n-1); i++)
            conductor = conductor->next;

          list[next_free].next = 0;
          list[next_free].element = item;
          conductor->next = &list[next_free];
        }
      }
    }
    next_free++;
  }

  /*! \brief Dodaje element na samym koncu listy.
   *
   * \details Uzyteczne i bardzo wygodne, gdzy taki sam mechanizm
   *              stosuje sie w bibliotece STL.
   */
  virtual void push_back(Type item) {
    add(item, size());
  }

  /*! \brief Usuwa element z dowolnego miejsca listy.
   *
   * \details Usuwa element z miejsca wskazywanego przez zmienna index.
   *
   * \return Zwraca slowo, ktore znajdowalo sie na tym indeksie.
   */
  virtual Type remove(int n) {
    Type word;

    if (size() == 0)
      throw("List is empty");
    if (n < size()) {
      Node *conductor = head;

      if (n == 0) {  // if we want to remove at the beginning
        head = conductor->next;
        word = conductor->element;
        list[0] = list[next_free-1];
      } else {
        // repeating this operation (n-1)-times
        for (int i = 0; i < n-1; i++)
          conductor = conductor->next;
        Node *after_cond = conductor->next;  // point to the next element
        // which is to be deleted
        conductor->next = after_cond->next;
        word = after_cond->element;
        after_cond->element = list[next_free-1].element; }

      // list.decreaseSize(1);
    } else {
      throw("Index out of bounds"); }

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
    if (size() > 0)
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

    if (n < size()) {
      Node *conductor = head;
      if (conductor != 0) {
        // repeating this operation n-times
        for (int i = 0; i < n; i++)
          conductor = conductor->next;
        temp = conductor->element;
      } else {
        throw("List is empty"); }
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
  virtual int size() { return next_free; }

  /*! \brief Wypisuje zawartosc listy.
   *
   * \details Wypisuje kazdy element listy w osobnej linii.
   *          Na gorze znajduje sie poczatek listy.
   */
  void print() {
    Node *conductor = head;
    while (conductor != 0) {
      std::cout << conductor->element << std::endl;
      conductor = conductor->next;  // jump to the next element
    }
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
    int searched_index = 0;
    Node *conductor = head;

    if (isEmpty())
      return -1;  // list is empty

    while (conductor != 0) {
      if (conductor->element == searched_word)
        return searched_index;
      searched_index++;
      conductor = conductor->next;
    }

    return -2;   // we didn't find anything
  }
};

#endif  // LAB03_14_03_PRJ_INC_LISTA_H_
