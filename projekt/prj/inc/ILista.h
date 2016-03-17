#ifndef ILISTA_H
#define ILISTA_H

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
template <class Type> class Node {
  /*! \brief Element w wezle.
   *
   * \details Co jest w wezle.
   */
  Type element;

  /*! \brief Wskaznik na nastepny wezel.
   *
   * \details Wskazuje na nastepny wezel.
   */
  Node *next;

  /*! \brief Wskaznik na poprzedni wezel.
   *
   * \details Wskazuje na poprzedni wezel.
   */
  Node *previous;

  /*! \brief Konstruktor parametryczny.
   *
   * \details Stworzony w celu szybkiej inicjalizacji nowego wezla dana.
   *
   * \param[in] x Dana, ktora ma zostac zapisana.
   */
  Node<Type>(Type x): element(x){}

  /*! \brief Zaprzyjaznienie interfejsu ILista.
   *
   * \details Umozliwia dostep do wezlow dla listy.
   */
  friend class ILista;
};


/*! \brief Interfejs dla pojemnika Lista.
 *
 * \details Abstrakcyjna klasa, ktora zostala utworzona na potrzeby ADT
 *          Abstract Data Types.
 */
template <class Type> class ILista {
 protected:

  /*! \brief Wstawia element w dowolnym miejscu listy.
   *
   * \details Wstawia element typu Type w miejsce wskazywane przez zmienna index.
   *
   * \param[in] item Element wstawiany.
   * \param[in] index Miejsce, w ktore ma byc wstawiony element item.
   */
  virtual void add(Type item, uint index)=0;

  /*! \brief Usuwa element z dowolnego miejsca listy.
   *
   * \details Usuwa element z miejsca wskazywanego przez zmienna index.
   *
   * \return Zwraca element typu Type.
   */
  virtual Type remove(uint index)=0;

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
  virtual Type get(uint index)=0;

  /*! \brief Zwraca rozmiar listy.
   *
   * \details Zwraca ilosc elementow w liscie.
   *
   * \return Rozmiar listy.
   */
  virtual uint size()=0;
};

#endif
