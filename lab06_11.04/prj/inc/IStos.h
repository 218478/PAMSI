// Copyright 2016 <Kamil Kuczaj>
#ifndef LAB03_14_03_PRJ_INC_ISTOS_H_
#define LAB03_14_03_PRJ_INC_ISTOS_H_

#include <string>

/*! \file IStos.h
 *
 * \brief Plik zawiera interfejs dla pojemnika Stos.
 *
 * \details Nie zdecydowano sie na uzycie szablonow, gdyz zbyt komplikuje to
 *          budowe programu.
 *
 * \author Kamil Kuczaj.
 */

/*! \brief Interfejs dla każdego pojemnika.
 *
 * \details Abstrakcyjna klasa, ktora zostala utworzona na potrzeby ADT
 *          Abstract Data Types.
 */
template <class Type>
class IStos {
 protected:
  /*! \brief Dodaje element na poczatek.
   *
   * \details Dodaje element na poczatek pojemnika.
   *
   * \param[in] element "Wpychany" element typu std::string.
   */
  virtual void push(Type element) = 0;

  /*! \brief Usuwa element z pojemnika.
   *
   * \details Usuwa element z pojemnika i zwraca go uzytkownikowi.
   *          Metoda czysto wirtualna.
   *
   * \return Usuniety element.
   */
  virtual Type pop() = 0;

  /*! \brief Sprawdza czy pojemnika jest pusty.
   *
   * \details Sprawdza czy znajduja sie jakies elementy w pojemniku.
   *          Metoda czysto wirtualna.
   *
   * \retval true Pojemnik pusty.
   * \retval false Pojemnik nie jest pusty.
   */
  virtual bool empty() = 0;

  /*!
   * \brief Zwraca aktualny rozmiar pojemnika.
   *
   * \details Zwraca wartosc, ktora reprezentuje obecna ilosc elementow
   *          w pojemniku. Metoda czysto wirtualna.
   *
   * \return Ilosc elementow w pojemniku.
   */
  virtual int size() = 0;
};


#endif  // LAB03_14_03_PRJ_INC_ISTOS_H_
