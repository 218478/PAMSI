#ifndef LISTA_H
#define LISTA_H

#include "IRunnable.h"
#include "ILista.h"

#include <cstddef>  // to use the NULL macro
#include <string>   // to deal with words saving and searching

/*! \file Lista.h
 *
 * \brief Implementacja dwukierunkowej listy.
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
template <class Type> class Lista: IRunnable, ILista<Type> {
  /*! \brief Wezel dla listy.
   *
   * \details Bazowy element listy.
   */
  Node<Type> node;

  /*! \brief Pierwszy element listy.
   *
   * \details Wskazuje na pierwszy element listy.
   */
  Node<Type> *first;

  /*! \brief Ostatni element listy.
   *
   * \details Wskazuje na ostatni element listy.
   */
  Node<Type> *last;
 
 public:

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
   */
  virtual void run(std::string desired_element);

  /*! \brief Zapisuje liste slowami.
   *
   * \details Zapisuje liste slowami zaczerpnietymi ze slownika.
   *
   * \param[in] desired_size Ile elementow ma zostac wczytanych.
   */
  virtual void prepare(uint desired_size);

};


template <class Type> void Lista<Type>::add(Type item, uint index) {

}

template <class Type> bool Lista<Type>::isEmpty() {
  return (first == NULL) ? true : false;
}

template <class Type> Type Lista<Type>::get(uint index) {
  Node<Type> *temp;

  // we move until we hit the desired element from the nearest side
  // either from the end or from the beginning, depending on the index
  if(index < size()/2)
    {
      temp = &first;
      for(uint i = 0; i <= index; i++)
	temp=temp->next;
    }
  else
    {
      temp = &last;
      for(uint i = size()-1; i >= index; i--)
	temp=temp->previous;
    }
  return temp->element;
}

#endif
