// Copyright 2016 Kamil Kuczaj
#ifndef LAB03_14_03_PRJ_INC_STOS_H_
#define LAB03_14_03_PRJ_INC_STOS_H_

#include "IStos.h"


/*! \brief Implementacja klasy Stos.
 *
 * \details Implementacja pojemnika, gdzie dostepny jest jedynie element
 *          bedacy "na gorze".
 *
 */
class Stos: IStos {
 public:
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
