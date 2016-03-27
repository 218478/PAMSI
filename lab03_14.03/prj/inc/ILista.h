// Copyright 2016 Kamil Kuczaj
#ifndef LAB03_14_03_PRJ_INC_ILISTA_H_
#define LAB03_14_03_PRJ_INC_ILISTA_H_

#include <cstddef>  // to use the NULL macro
#include <string>   // to insert words

/*! \file ILista.h
 *
 * \brief Plik zawiera interfejs dla pojemnika Lista oraz dla klasy Wezel.
 *
 * \details Wezel jest elementem listy. Uzycie szablonow zbytnio komplikuje
 *          implementacje, wiec odrzucilem ich zastosowanie.
 *
 * \author Kamil Kuczaj.
 */

/*! \brief Imlementacja wezlow dla listy.
 *
 * \details Potrzebne do implementacji interfejsu listy. Zawiera pole
 *          typu string.
 */
class Node {
 public:
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

  /*! \brief Zaprzyjaznienie interfejsu ILista.
   *
   * \details Umozliwia dostep do wezlow dla listy.
   */
  friend class ILista;

 public:
  /*! \brief Dostep do pola element.
   *
   * \details Wymuszone poprzez hermetyzacje.
   *
   * \return Zwraca element typu String.
   */
  std::string getElem() { return element; }

  /*! \brief Dostep do nastepnego wezla.
   *
   * \details Wymuszone poprzez hermetyzacje.
   *
   * \return Zwraca wskaznik typu Node*.
   */
  const Node* getNext() const { return next; }

  /*! \brief Ustawia pole element.
   *
   * \details Wymuszone poprzez hermetyzacje.
   *
   * \param[in] t Wartosc, ktora ma zostac zapisana do pola element.
   */
  void setElem(const std::string t) { element = t; }

  /*! \brief Ustawia nastepny wezel.
   *
   * \details Wymuszone poprzez hermetyzacje.
   *
   * \param[in] t Wezel, ktory ma zostac przypisany do pola next.
   */
  void setNext(Node* t) { next = t; }
};


/*! \brief Interfejs dla pojemnika Lista.
 *
 * \details Abstrakcyjna klasa, ktora zostala utworzona na potrzeby ADT
 *          Abstract Data Types.
 */
class ILista {
 protected:

  /*! \brief Wstawia element w dowolnym miejscu listy.
   *
   * \details Wstawia element typu std::string w miejsce wskazywane przez
   *          zmienna index.
   *
   * \param[in] item Element wstawiany. Slowo.
   * \param[in] index Miejsce, w ktore ma byc wstawiony element item.
   */
  virtual void add(std::string item, int index) = 0;

  /*! \brief Usuwa element z dowolnego miejsca listy.
   *
   * \details Usuwa element z miejsca wskazywanego przez zmienna index.
   *
   * \retval true Udalo sie usunac.
   * \retval false Nie udalo sie usunac wskazanego elementu.
   */
  virtual bool remove(int index) = 0;

  /*! \brief Sprawdza czy lista jest pusta.
   *
   * \details Sprawdza czy w liscie sa jakies elementy.
   *
   * \retval true Lista jest pusta.
   * \retval false Lista nie jest pusta.
   */
  virtual bool isEmpty() = 0;

  /*! \brief Zwraca element z dowolnego miejsca listy.
   *
   * \details Zwraca element z miejsca wskazywanego przez zmienna index.
   *
   * \return Zwraca element typu Type.
   */
  virtual std::string get(int index) = 0;

  /*! \brief Zwraca rozmiar listy.
   *
   * \details Zwraca ilosc elementow w liscie.
   *
   * \return Rozmiar listy.
   */
  virtual int size() = 0;
};

#endif  // LAB03_14_03_PRJ_INC_ILISTA_H_
