// Copyright 2016 Kamil Kuczaj
#ifndef LAB03_14_03_PRJ_INC_IKOLEJKA_H_
#define LAB03_14_03_PRJ_INC_IKOLEJKA_H_

/*! \file IKolejka.h
 *
 * \brief Plik zawiera interfejs dla pojemnika Kolejka.
 *
 * \details Nie zdecydowano sie na uzycie szablonow, gdyz zbyt komplikuje to
 *          budowe programu.
 
 * * \author Kamil Kuczaj.
 */

/*! \brief Interfejs dla kolejki.
 *
 * \details Abstrakcyjna klasa, ktora zostala utworzona na potrzeby ADT
 *          Abstract Data Types.
 */
class IKolejka {
 protected:
  /*! \brief Dodaje element w okreslonym miejscu.
   *
   * \details Metoda czysto wirtualna. Dodaje element item w miejscu index
   *          pojemnika.
   *
   * \param[in] item    Dana, ktora ma byc wlozona.
   * \param[in] index   Indeks, w ktorym ma znalezc sie nowa dana.
   *
   * \retval true Udalo sie dodac element.
   * \retval false Nie udalo sie dodac elementu.
   */
  virtual bool add(int item, int index) = 0;

  /*! \brief Dodaje element na poczatek.
   *
   * \details Dodaje element na poczatek pojemnika.
   *
   * \param[in] element "Wpychany" element typu int.
   */
  virtual void push(int element) = 0;

  /*! \brief Usuwa element z pojemnika.
   *
   * \details Usuwa element z pojemnika i zwraca go uzytkownikowi.
   *          Metoda czysto wirtualna.
   *
   * \return Usuniety element.
   */
  virtual int pop() = 0;

  /*! \brief Sprawdza czy pojemnika jest pusty.
   *
   * \details Sprawdza czy znajduja sie jakies elementy w pojemniku.
   *          Metoda czysto wirtualna.
   *
   * \retval true Pojemnik pusty.
   * \retval false Pojemnik nie jest pusty.
   */
  virtual bool empty() = 0;

  /*! \brief Zwraca aktualny rozmiar pojemnika.
   *
   * \details Zwraca wartosc, ktora reprezentuje obecna ilosc elementow
   *          w pojemniku. Metoda czysto wirtualna.
   *
   * \return Ilosc elementow w pojemniku.
   */
  virtual int size() = 0;
};


#endif  // LAB03_14_03_PRJ_INC_IKOLEJKA_H_
