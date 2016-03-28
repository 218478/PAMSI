// Copyright 2016 Kamil Kuczaj
#ifndef LAB03_14_03_PRJ_INC_STOS_H_
#define LAB03_14_03_PRJ_INC_STOS_H_

#include "IStos.h"
#include "Lista.h"


/*! \brief Implementacja klasy Stos, zlozonej z intow.
 *
 * \details Implementacja pojemnika, gdzie dostepny jest jedynie element
 *          bedacy "na gorze". Jej skladowe elementy to inty. Zdecydowalem
 *          sie nie stosowac szablonow ze wzgledu na niepotrzebna komplikacje.
 */
class Stos: IStos {
 private:
  /*! \brief Gora stosu.
   *
   * \details Wskaznik na wierzcholek stosu.
   */
  int *top;

  /*! \brief Stos.
   *
   * \details Reprezentacja stosu. Zwieksza pamiec dwukrotnie.
   */
  Lista *stack;

 public:
  /*! \brief Bezparametryczny konstruktor.
   *
   * \details Inicjalizuje wierzcholek *top jak wskaznik na NULL.
   */
  Stos(): top(0) {}

  /*! \brief Destruktor.
   *
   * \details Popuje wszystkie elementy.
   */

  /*! \brief Usuwa element z okreslonego miejsca.
   *
   * \details Usuwa i zwraca podany element znajdujacy sie w index-owym miejscu.
   *
   * \param[in] element "Wpychany" element typu int.
   */
  virtual void push(int element);

  /*! \brief Usuwa element z pojemnika.
   *
   * \details Usuwa element z pojemnika i zwraca go uzytkownikowi.
   *          Metoda czysto wirtualna.
   *
   * \return Usuniety element.
   */
  virtual int pop();

  /*! \brief Sprawdza czy pojemnika jest pusty.
   *
   * \details Sprawdza czy znajduja sie jakies elementy w pojemniku.
   *          Metoda czysto wirtualna.
   *
   * \retval true Pojemnik pusty.
   * \retval false Pojemnik nie jest pusty.
   */
  virtual bool empty();

  /*!
   * \brief Zwraca aktualny rozmiar pojemnika.
   *
   * \details Zwraca wartosc, ktora reprezentuje obecna ilosc elementow
   *          w pojemniku. Metoda czysto wirtualna.
   *
   * \return Ilosc elementow w pojemniku.
   */
  virtual int size();
};



#endif  // LAB03_14_03_PRJ_INC_STOS_H_
