#ifndef ILISTA_H
#define ILISTA_H

#include <cstddef> // to use the NULL macro

/*! \file ILista.h
 *
 * \brief Plik zawiera interfejs dla pojemnika Lista oraz dla klasy Wezel.
 *
 * \details Wskutek zastosowania szablonow wszystkie definicje musza znajdowac
 *          sie w pliku naglowkowym, a nie zrodlowym. Wezel jest elementem listy.
 *
 * \author Kamil Kuczaj.
 */


/*! \brief Skraca zapis.
 *
 * \details Zdefiniowanie wlasnego typu - pozwala na krotszy zapis.
 */
typedef unsigned int uint;


/*! \brief Imlementacja wezlow dla listy.
 *
 * \details Potrzebne do implementacji interfejsu listy.
 */
template <class NodeType> class Node {
  public:
  /*! \brief Element w wezle.
   *
   * \details Co jest w wezle.
   */
  NodeType element;

  /*! \brief Wskaznik na nastepny wezel.
   *
   * \details Wskazuje na nastepny wezel.
   */
  Node<NodeType>* next;

  /*! \brief Zaprzyjaznienie interfejsu ILista.
   *
   * \details Umozliwia dostep do wezlow dla listy.
   */
  template <class ListType>
  friend class ILista;

 public:
  
  /*! \brief Dostep do pola element.
   *
   * \details Wymuszone poprzez hermetyzacje.
   *
   * \return Zwraca element typu Type.
   */
  NodeType getElem() { return element; }

  /*! \brief Dostep do nastepnego wezla.
   *
   * \details Wymuszone poprzez hermetyzacje.
   *
   * \return Zwraca element typu Node.
   */
  Node getNext() { return next; }

  /*! \brief Ustawia pole element.
   *
   * \details Wymuszone poprzez hermetyzacje.
   *
   * \param[in] Wartosc, ktora ma zostac zapisana do pola element.
   */
  void setElem(const NodeType t) { element=t; }

  /*! \brief Ustawia nastepny wezel.
   *
   * \details Wymuszone poprzez hermetyzacje.
   *
   * \param[in] t Wezel, ktory ma zostac przypisany do pola next.
   */
  void setNext(Node<NodeType>* t) { next=t; }
};


/*! \brief Interfejs dla pojemnika Lista.
 *
 * \details Abstrakcyjna klasa, ktora zostala utworzona na potrzeby ADT
 *          Abstract Data Types.
 */
template <class ListType> class ILista {
 protected:

  /*! \brief Wstawia element w dowolnym miejscu listy.
   *
   * \details Wstawia element typu Type w miejsce wskazywane przez zmienna index.
   *
   * \param[in] item Element wstawiany.
   * \param[in] index Miejsce, w ktore ma byc wstawiony element item.
   */
  virtual void add(ListType item, uint index)=0;

  /*! \brief Usuwa element z dowolnego miejsca listy.
   *
   * \details Usuwa element z miejsca wskazywanego przez zmienna index.
   *
   * \return Zwraca element typu Type.
   */
  virtual ListType remove(uint index)=0;

  /*! \brief Sprawdza czy lista jest pusta.
   *
   * \details Sprawdza czy w liscie sa jakies elementy.
   *
   * \retval true Lista jest pusta.
   * \retval false Lista nie jest pusta.
   */
  virtual bool isEmpty()=0;

  /*! \brief Zwraca element z dowolnego miejsca listy.
   *
   * \details Zwraca element z miejsca wskazywanego przez zmienna index.
   *
   * \return Zwraca element typu Type.
   */
  virtual ListType get(uint index)=0;

  /*! \brief Zwraca rozmiar listy.
   *
   * \details Zwraca ilosc elementow w liscie.
   *
   * \return Rozmiar listy.
   */
  virtual uint size()=0;
};

#endif
