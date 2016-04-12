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

 public:
  /*! \brief Konstruktor.
   *
   * \details Tworzy poczatek listy. Alokuje dla niego pamiec.
   */
  Lista()  { head = 0; }   // bad things happen if you dont do it

  /*! \brief Destruktor.
   *
   * \details Usuwa cala pamiec listy "skaczac" po jej elementach.
   */
  ~Lista() { list.~Array(); }

  /*! \brief Wstawia element w dowolnym miejscu listy.
   *
   * \details Wstawia element typu Type w miejsce wskazywane przez zmienna index.
   *
   * \param[in] item Element wstawiany. Slowo typu string.
   * \param[in] index Miejsce, w ktore ma byc wstawiony element item.
   */
  virtual void add(Type item, int n) {
    int current_size = list.getSize();
    if (n > current_size)  // if we want to add an element beyond list
      throw("Requested index out of bounds");

    if (isEmpty()) {  // if the list is empty
      Node* temp = new Node;
      temp->element = item;
      head = temp;
      head->next = 0;

    } else {  // and when it's not empty
      Node* temp = new Node;
      temp->element = item;

      if (n == 0) {  // when we adding at the beginning
        temp->next = head;
        head = temp;
      } else {
        Node *conductor = head;

        if (n < current_size) {  // when inserting
          for (int i = 0; i < (n-1); i++)
            conductor = conductor->next;

          temp->next = conductor->next;
          conductor->next = temp;
        }

        if (n == current_size) {  // when adding at the end
          // // for debug
          // std::cout << "Dolaczamy na koniec." << std::endl;
          for (int i = 0; i < (n-1); i++)
            conductor = conductor->next;

          temp->next = 0;
          conductor->next = temp;
        }
      }
    }
  }


  /*! \brief Usuwa element z dowolnego miejsca listy.
   *
   * \details Usuwa element z miejsca wskazywanego przez zmienna index.
   *
   * \return Zwraca slowo, ktore znajdowalo sie na tym indeksie.
   */
  virtual Type remove(int n) {
    std::string word;

    if (size() == 0)
      throw("List is empty");
    if (n < size()) {
      Node *conductor = head;

      if (n == 0) {  // if we want to remove at the beginning
        head = conductor->next;
        word = conductor->element;
        delete conductor;
      } else {
        // repeating this operation (n-1)-times
        for (int i = 0; i < n-1; i++)
          conductor = conductor->next;
        Node *after_cond = conductor->next;  // point to the next element
        // which is to be deleted
        conductor->next = after_cond->next;
        word = after_cond->element;
        delete after_cond; }
    }
    else
      throw("Index out of bounds");

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

    // error checking
    if (n >= list.getSize() )
      throw("Index out of bounds");
    if (isEmpty())
      throw("List is empty");

    return list[n].element;
  }

  /*! \brief Zwraca rozmiar listy.
   *
   * \details Zwraca ilosc elementow w liscie.
   *
   * \return Rozmiar listy.
   */
  virtual int size() { return list.getSize(); }

  /*! \brief Wypisuje zawartosc listy.
   *
   * \details Wypisuje kazdy element listy w osobnej linii.
   *          Na gorze znajduje sie poczatek listy.
   */
  void print() {
    for (int i = 0; i < list.getSize(); i++)
      std::cout << list[i].element << std::endl;
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

    if (isEmpty())
      return -1;  // list is empty

    while (list[searched_index] != searched_word)
      searched_index++;

    return -2;   // we didn't find anything
  }
};

#endif  // LAB03_14_03_PRJ_INC_LISTA_H_
