// Copyright 2016 Kamil Kuczaj
#ifndef LAB08_25_04_PRJ_INC_LISTA_H_
#define LAB08_25_04_PRJ_INC_LISTA_H_

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

 /*! \brief Imlementacja wezlow dla listy.
   *
   * \details Potrzebne do implementacji interfejsu listy. Zawiera pole
   *          typu string.
   */
   template <class Type>
   struct Node {
    /*! \brief Element w wezle.
     *
     * \details Co jest w wezle. Ma przechowywac pojedyncze slowo.
     */
     Type element;

     /*! \brief Waga krawedzi.
      *
      * \details Pole stworzone w celu implementacji grafu.
      *          Reprezentuje wage krawedzi pomiedzy wezlami.
      */
     int weight;

    /*! \brief Wskaznik na nastepny wezel.
     *
     * \details Wskazuje na nastepny wezel.
     */
     Node<Type>* next;

     /*! \brief Potrzebne do implementacji wyrazenia lambda w grafie.
      */
     friend class Graph;
   };


/*! \brief Klasa Lista, ktora symuluje zachowanie klasy list z biblioteki STL.
 *
 * \details Zajmuje sie dynamiczna alokacja pamieci. Lista jest jednokierunkowa.
 *          Mamy dostep do pierwszego elementu w liscie
 */
 template <class Type>
 class Lista: ILista<Type> {
 private:

  /*! \brief Pierwszy element listy.
   *
   * \details Wskazuje na pierwszy element listy.
   */
   Node<int> *head;

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
   Lista(): head(nullptr), size_of_list(0) {}

  /*! \brief Parametryczny konstruktor.
   *
   * \details Konstruktor dodany na potrzeby implementacji grafu.
   */
   Lista(Type x) : Lista() {
    add(x, 1, 0);
   }

  /*! \brief Wstawia element w dowolnym miejscu listy.
   *
   * \details Wstawia element typu Type w miejsce wskazywane przez zmienna index.
   *
   * \param[in] item Element wstawiany. Slowo typu string.
   * \param[in] w Waga krawedzi.
   * \param[in] n Miejsce, w ktore ma byc wstawiony element item.
   */
   virtual void add(Type item, int w, int n){
    int current_size = size();
  if (n > current_size)  // if we want to add an element beyond list
    throw("Requested index out of bounds");

  if (isEmpty()) {  // if the list is empty
    Node<int>* temp = new Node<int>;
    temp->element = item;
    temp->weight = w;
    head = temp;
    head->next = nullptr;
    size_of_list++;

  } else {  // and when it's not empty
  Node<int>* temp = new Node<int>;
  temp->element = item;
  temp->weight = w; 

    if (n == 0) {  // when we adding at the beginning
      temp->next = head;
      head = temp;
      size_of_list++;
    } else {
      Node<int> *conductor = head;

      if (n < current_size) {  // when inserting
        for (int i = 0; i < (n-1); i++)
          conductor = conductor->next;

        temp->next = conductor->next;
        conductor->next = temp;
        size_of_list++;
      }

      if (n == current_size) {  // when adding at the end
        for (int i = 0; i < (n-1); i++)
          conductor = conductor->next;

        temp->next = nullptr;
        conductor->next = temp;
      }
    }
  }
}

  /*! \brief Usuwa element z dowolnego miejsca listy.
   *
   * \details Usuwa element z miejsca wskazywanego przez zmienna index.
   *              Cos jest nie tak z ta funkcja bo nie usuwa dobrze i nie moge
   *              dojsc dlaczego tak jest. Jak chcesz jej uzyc to  lepiej
   *              napisz wlasna :D.
   *
   * \return Zwraca slowo, ktore znajdowalo sie na tym indeksie.
   */
   virtual Type remove(int n) {
    Type word;

    if (size() == 0)
      throw("List is empty");
    if (n < size()) {
      Node<int> *conductor = head;
      if (n == 0) {  // if we want to remove at the beginning
        head = conductor->next;
        word = conductor->element;
        delete conductor;
        }
      else
        {
        // repeating this operation (n-1)-times
        for (int i = 0; i < n-1; i++)
          conductor = conductor->next;
        Node<int> *after_cond = conductor->next;  // point to the next element
        // which is to be deleted
        conductor->next = after_cond->next;
        word = after_cond->element;
        delete after_cond; }
      }
    else
      throw("Index out of bounds");

    return word;
  }

  /*! \brief Usuwa wszystkie elementy listy.
   *
   * \details Nie korzysta z funkcji remove, wiec dziala super.
   */
  void clear() {
    Node<int> *conductor = head;
    head = nullptr;
    while(conductor != nullptr) {
      delete conductor;
      conductor = conductor->next;
    }
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
      Node<int> *conductor = head;
      if (conductor != nullptr) {
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

   virtual int getWeight(int n) {
    Type temp;
    if (n < size()) {
      Node<int> *conductor = head;
      if (conductor != nullptr) {
      // repeating this operation n-times
        for (int i = 0; i < n; i++)
          conductor = conductor->next;
        temp = conductor->weight;
      } else {
        throw("List is empty"); }
      } else {
        throw("Index out of bounds"); }

        return temp;
      }

  Lista<Type> getMinWeight() {
    if (isEmpty())
      throw ("Empty list");

    Lista<Type> temp;
    int min_weight = head->weight;  // must be initialized

    for (Node<int> *conductor = head; conductor != nullptr; conductor = conductor->next) {
      if (conductor->weight < min_weight) {
        temp.clear();
        min_weight = conductor->weight;
        temp.push_back(conductor->element, min_weight);
      }

      if (conductor->weight == min_weight)
        temp.push_back(conductor->element, min_weight);
    }

    return temp;
  }

  /*! \brief Dodaje na koniec.
   *
   * \details Dziala tak jak w STLu. Korzysta z metody add()
   */
  void push_back(Type item, int weight = 1) {
    add(item, weight, size());
  }

  /*! \brief Zwraca rozmiar listy.
   *
   * \details Zwraca ilosc elementow w liscie.
   *
   * \return Rozmiar listy.
   */
   virtual int size() {
    Node<int> *conductor = head;
    int temp_size = 0;
    while (conductor != nullptr) {
      conductor = conductor->next;
      temp_size++;
    }

    return temp_size;
  }

  /*! \brief Wypisuje zawartosc listy.
   *
   * \details Wypisuje kazdy element listy w osobnej linii.
   *          Na gorze znajduje sie poczatek listy.
   */
   void print() {
    if (isEmpty())
      std::cerr << "Empty list" << std::endl;

    Node<int> *conductor = head;
    while (conductor != nullptr) {
      std::cout << "vertex no: " << conductor->element << "(" 
      << conductor->weight << ")" << std::endl;
    conductor = conductor->next;  // jump to the next element
  }
}

  /*! \brief To wypadaloby poprawic.
   */
  void operator << (Lista<Type>) {
    print();
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
    Node<int> *conductor = head;
    int searched_index = 0;

    if (isEmpty())
    return -1;  // list is empty

  while (conductor != nullptr) {
    if (conductor->element == searched_word)
      return searched_index;

    searched_index++;
    conductor = conductor->next;
  }
  return -2;   // we didn't find anything
}

/*! \brief Choose min other than specified as an argument
*/
Type min (Lista other_than) {
  Node<int> *conductor = head;
  int temp = conductor->element;
  // a trick because my graph always has its own vertex on its adjacency list

  if (isEmpty())
    return -1;  // list is empty

  while (conductor != nullptr) {
    if (conductor->element < temp && other_than.search(conductor->element) < 0)
      temp = conductor->element;

    conductor = conductor->next;
  }
  return temp;
}

  /*! \brief Podlicza sume wag.
  */
  Type sum() {
    Type temp = 0;

    Node<Type>* conductor = head;
    while (conductor != nullptr) {
      temp += conductor->weight;
      conductor = conductor->next;
    }

    return temp;
  }

  /*! \brief Przeciazenie operatora porownania.
   *
   * \details Potrzebne do wyrazenia lambda w branch&boundzie grafu.
   *              Zwraca element, ktorego suma wszystkich elementow jest
   *              mniejsza.
   *
   * \param[in] Porownywana lista.
   */
    bool operator > (Lista<Type> second) {
    int temp1 = sum();
    int temp2 = second.sum();

    return (temp1 > temp2) ? true : false;

   }

};

#endif  // LAB08_25_04_PRJ_INC_LISTA_H_
