#ifndef LISTA_H
#define LISTA_H

#include "IRunnable.h"
#include "ILista.h"

#include <cstddef>  // to use the NULL macro
#include <string>   // to deal with words saving and searching
#include <iostream> // to print the contents of the list

/*! \file Lista.h
 *
 * \brief Implementacja jednokierunkowej listy.
 *
 * \details Wskutek zastosowania szablonow wszystkie definicje musza znajdowac
 *          sie w pliku naglowkowym, a nie zrodlowym.
 *
 * \author Kamil Kuczaj.
 */


/*! \brief Skraca zapis.
 *
 * \details Zdefiniowanie wlasnego typu - pozwala na krotszy zapis
 */
typedef unsigned int uint;


/*! \brief Klasa Lista, w ktorej odbywa sie zapis dynamiczny elementow typu int.
 *
 * \details Implementuje metody interfejsu IRunnable. Zajmuje sie dynamiczna
 *          alokacja pamieci. Lista jest dwukierunkowa oraz posiada mechanizm,
 *          dzieki ktoremu mamy dostep zarowno do pierwszego jak i ostatniego
 *          elementu.
 */
template <class Type> class Lista: /*IRunnable,*/ ILista<Type> {

  /*! \brief Pierwszy element listy.
   *
   * \details Wskazuje na pierwszy element listy.
   */
  Node<Type> *head;

  /*! \brief Ostatni element listy.
   *
   * \details Wskazuje na ostatni element listy.
   */
  Node<Type> *tail;

  /*! \brief Przechowuje rozmiar listy.
   *
   * \details Dzieki zastosowaniu tej zmiennej, o wiele latwiej poslugiwac sie
   *          lista.
   */
  uint size_of_list;

 public:

  /*! \brief Konstruktor.
   *
   * \details Tworzy poczatek listy.
   */
  Lista();

  /*! \brief Konstruktor.
   *
   * \details Tworzy poczatek listy.
   */
  ~Lista();

  /*! \brief Wstawia element w dowolnym miejscu listy.
   *
   * \details Wstawia element typu Type w miejsce wskazywane przez zmienna index.
   *
   * \param[in] item Element wstawiany.
   * \param[in] index Miejsce, w ktore ma byc wstawiony element item.
   */
  virtual void add(Type item, uint index);

  /*! \brief Usuwa element z dowolnego miejsca listy.
   *
   * \details Usuwa element z miejsca wskazywanego przez zmienna index.
   *
   * \return Zwraca element typu Type.
   */
  virtual Type remove(uint index);

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
   *          ! WAZNE ! Przed uzyciem nalezy sprawdzic, czy lista jest pusta.
   *          W metodzie na obecna chwile nie ma zabezpieczen.
   *
   * \return Zwraca element typu Type.
   */
  virtual Type get(uint index);

  /*! \brief Zwraca rozmiar listy.
   *
   * \details Zwraca ilosc elementow w liscie.
   *
   * \return Rozmiar listy.
   */
  virtual uint size();

  /*! \brief Szuka elementu.
   *
   * \details Szuka elementu wskazanego przez uzytkownika.
   *
   * \param[in] desired_element Poszukiwana fraza.
   *
   * \retval true Znalazl element i wyswietlil.
   * \retval false Nie znalazl i nie wyswietlil elementu.
   */
  bool find(Type desired_element);

  /*! \brief Zapisuje liste slowami.
   *
   * \details Zapisuje liste slowami zaczerpnietymi ze slownika.
   *
   * \param[in] desired_size Ile elementow ma zostac wczytanych.
   */
  //virtual void prepare(uint desired_size);


  /*! \brief Wypisuje zawartosc listy.
   *
   * \details Wypisuje kazdy element listy w osobnej linii.
   *          Na gorze znajduje sie poczatek listy.
   */
  void print();

};

template <class Type> Lista<Type>::Lista() {
  head = 0;
  size_of_list=0; }

template <class Type> Lista<Type>::~Lista() { 
  Node<Type> *conductor = head;
  while(conductor != 0) {
    conductor=conductor->next;
    delete conductor;
  }
}

template <class Type> uint Lista<Type>::size() { 
  Node<Type> *conductor;
  uint size_temp=0;

  conductor = head;
  if ( conductor != 0 ) {
    while ( conductor->next != 0) {
      conductor = conductor->next;
      size_temp++;
    }
    size_temp++; // it wasn't counting the last element, since this->next was
                 // pointing to NULL
  }

  return size_temp;
}

template <class Type> void Lista<Type>::add(Type item, uint index) {
  uint size_temp = size();

  // if we want to add it at first
  if (index == 0)
    {
      Node<Type> *temp = new Node<Type>;
      temp->element=item;
      temp->next = head;
      head=temp;
    }
  else if(size_temp > index)
    {
      Node<Type> *temp = new Node<Type>;
      temp->element=item;
      Node<Type> *conductor = head;
      
      // just at the element before indexed one
      for(uint i=0; i < index; i++) {
	conductor=conductor->next;
      }

      temp->next=conductor->next;
      conductor->next=temp;
    }
  else if(size_temp == index)
    {
      Node<Type> *temp = new Node<Type>;
      temp->element=item;
      Node<Type> *conductor = head;
      
      // just at the element before indexed one
      for(uint i=0; i < index-1; i++) {
	conductor=conductor->next;
      }
      
      conductor->next = temp;
      temp->next = 0;
    }
  else
    {
      std::cerr << "Can't add '" << item << "': index out of bounds" << std::endl;
    }
  
  // Trying to implement a solution using methods failed, multiple times.
  // That's why I have decided to resign.
  //  temp->setElem(item);
  //  head->setNext(temp->getNext());
}

template <class Type> void Lista<Type>::print() {
  Node<Type> *conductor;
  conductor = head;

  while(conductor != 0) {
    std::cout << conductor->element << std::endl;
    conductor=conductor->next;
  }
}

template <class Type> Type Lista<Type>::remove(uint index) { return Type();}
template <class Type> Type Lista<Type>::get(uint index) {return Type();}

template <class Type> bool Lista<Type>::isEmpty() {
  return (head == NULL) ? true : false;
}

template <class Type> bool Lista<Type>::find(Type desired_element) {
  return true;}
//template <class Type> void Lista<Type>::prepare(uint desired_size) {}


#endif
