#ifndef STOS_H
#define STOS_H

#include "IPojemnik.h"

template <class Type>
class Stos: IPojemnik<Type> {

  /*! \brief Usuwa element z okreslonego miejsca.
   *
   * \details Usuwa i zwraca podany element znajdujacy sie w index-owym miejscu.
   *
   */
  virtual Type push();

  /*! \brief Usuwa element z pojemnika.
   *
   * \details Usuwa element z pojemnika i zwraca go uzytkownikowi.
   *          Metoda czysto wirtualna.
   *
   * \return Usuniety element.
   */
  virtual Type pop();

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
  virtual uint size();
  
};

#endif
