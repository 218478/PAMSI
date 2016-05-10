// Copyright 2016 Kamil Kuczaj
#ifndef LAB03_14_03_PRJ_INC_KOLEJKA_H_
#define LAB03_14_03_PRJ_INC_KOLEJKA_H_

#include "IKolejka.h"
#include "Lista.h"

#include <string>


/*! \brief Implementacja interfejsu IKolejka w postaci klasy Kolejka.
 *
 * \details Korzysta z klasy Lista, jako jej prywatne pole oraz calej
 *          jej funkcjonalnosci. W celu zrozumienia pelnej funkcjonalnosci
 *          klasy Kolejka, prosze odwolac sie do dokumentacji klasy Lista.
 */
class Kolejka: IKolejka {
 private:
  /*! \brief Zawartosc kolejki.
   *
   * \details Symuluje kolejke, poniewac jest to bardzo prosta implementacja.
   */
  Lista<std::string> queue;

 public:
  /*! \brief Dodaje element na poczatek.
   *
   * \details Dodaje element na poczatek pojemnika.
   *
   * \param[in] element "Wpychany" element typu string.
   */
  virtual void push(std::string element);

  /*! \brief Usuwa element z pojemnika.
   *
   * \details Usuwa element z pojemnika i zwraca go uzytkownikowi.
   *          Metoda czysto wirtualna.
   *
   * \return Usuniety element.
   */
  virtual std::string pop();

  /*! \brief Sprawdza czy pojemnika jest pusty.
   *
   * \details Sprawdza czy znajduja sie jakies elementy w pojemniku.
   *          Metoda czysto wirtualna.
   *
   * \retval true Pojemnik pusty.
   * \retval false Pojemnik nie jest pusty.
   */
  virtual bool empty();

  /*! \brief Zwraca aktualny rozmiar pojemnika.
   *
   * \details Zwraca wartosc, ktora reprezentuje obecna ilosc elementow
   *          w pojemniku. Metoda czysto wirtualna.
   *
   * \return Ilosc elementow w pojemniku.
   */
  virtual int size();

  /*! \brief Wyswietla zawartosc kolejki.
   *
   * \details Uzyteczna przy debugowaniu programu. Wyswietla kazde slowo
   *          w osobnej linii, zaczynajac od najstarszego.
   */
  void print();
};


#endif  // LAB03_14_03_PRJ_INC_KOLEJKA_H_
