// Copyright 2016 Kamil Kuczaj
#ifndef LAB03_14_03_PRJ_INC_ILISTA_H_
#define LAB03_14_03_PRJ_INC_ILISTA_H_

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


/*! \brief Interfejs dla pojemnika Lista.
 *
 * \details Abstrakcyjna klasa, ktora zostala utworzona na potrzeby ADT
 *          Abstract Data Types.
 */
template <class Type>
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
  virtual void add(Type item, int index) = 0;

  /*! \brief Usuwa element z dowolnego miejsca listy.
   *
   * \details Usuwa element z miejsca wskazywanego przez zmienna index.
   *
   * \return Zwraca zawartosc komorki o tej indeksie.
   */
  virtual Type remove(int index) = 0;

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
  virtual Type get(int index) = 0;

  /*! \brief Zwraca rozmiar listy.
   *
   * \details Zwraca ilosc elementow w liscie.
   *
   * \return Rozmiar listy.
   */
  virtual int size() = 0;
};

#endif  // LAB03_14_03_PRJ_INC_ILISTA_H_
