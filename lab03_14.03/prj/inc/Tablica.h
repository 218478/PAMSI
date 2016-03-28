// Copyright 2016 Kamil Kuczaj
#ifndef LAB03_14_03_PRJ_INC_TABLICA_H_
#define LAB03_14_03_PRJ_INC_TABLICA_H_

#include "ITablica.h"

#include <new>       // dla sprawdzenia poprawnosci alokacji pamieci
#include <iostream>  // to display error messages

/*! \file Tablica.h
 *
 * \brief Implementacja interfesju ITablca. Po konsultacji z prowadzacym
 *        zdecydowalem sie nie wykorzystywac szablonow.
 *
 * \author Kamil Kuczaj
 */

/*! \brief Klasa Tablica, w ktorej odbywa sie zapis dynamiczny elementow.
 *
 * \details Implementuje metody interfejsu ITablica. Zajmuje sie dynamiczna
 *          alokacja pamieci.
 */
class Tablica: ITablica  {
 private:
  /*! \brief Wskaznik do poczatku tablicy dynamicznej.
   *
   * \details Wskazuje na adres w pamieci sterty. Pole prywatne.
   */
  int *elements;

  /*! \brief Okresla aktualny rozmiar stosu.
   *
   * \details Pole prywatne typu int. Rozmiar nigdy nie powinien byc ujemny.
   */
  int current_size;

  /*! \brief Okresla pozadany rozmiar stosu.
   *
   * \details Pole prywatne typu int. Rozmiar nigdy nie powinien byc ujemny.
   *          Zadawane w funkcji prepare().
   */
  int desired_size;

  /*! \brief Okresla aktualny indeks.
   *
   * \details Pole prywatne typu int. Indeks nigdy nie powinien byc ujemny.
   *          Przechowuje indeks, pierwszego wolnego elementu tablicy,
   *          do ktorego mozliwy bedzie zapis.
   */
  int index;

 public:
  /*! \brief Pozwala prosto okreslic, czy nalezy przydzielic pamiec.
   *
   * \details Metoda prywatna. Sluzy do okreslania czy nalezy wywolac
   *          metode increaseSize().
   * 
   * \retval true Pamiec pelna. Nalezy zwiekszyc rozmiar.
   * \retval false Jest jeszcze wolne miejsce.
   */
  virtual bool isFull() { return ((index >= (current_size)) ?true:false); }

  /*! \brief Zwieksza rozmiar przydzielonej pamieci na stercie.
   *
   * \details Metoda prywatna. Kopiuje elementy starej pamieci do
   *          komorki z nowo-przydzielona pamiecia. Usuwa stara
   *          pamiec.
   */
  virtual void increaseSize() {
    int new_size = current_size * 2;
    try {
      int *new_elements = new int[new_size];
      for (int i=0; i < current_size; i++)
        new_elements[i] = elements[i];

      delete [] elements;
      current_size = new_size;
      elements = new_elements;
    }
    // if you fail to allocate memory
    catch (std::bad_alloc& ex) {
      std::cerr << ex.what() << std::endl;
    }
  }

  /*! \brief Konstruktor parametryczny.
   *
   * \details Umozliwia okreslenie poczatkowego rozmiaru tablicy. W przypadku
   *          braku okreslenia tego rozmiaru przyjmuje domyslna wartosc rowna 10.
   *
   * \param x Okresla poczatkowa wielkosc przydzielonej pamieci. Domyslna wartosc
   *          w przypadku braku podania to 10.
   */
  Tablica(int x = 10) { elements = new int[x]; current_size = x; index = 0; }

  /*! \brief Destruktor.
   *
   * \details Usuwa pamiec przypisana komorce, na ktora wskazuje pole *elements.
   */
  ~Tablica() { delete [] elements; }

  /*! \brief Zwraca aktualny rozmiar tablicy dynamicznej.
   *
   * \details Zwraca wartosc pola current_size.
   *
   * \return Zwraca wartosc typu int. Reprezentuje ilosc danych w tablilcy.
   */
  virtual int getSize() { return current_size; }
  virtual int getDesiredSize() const { return desired_size; }
  virtual void setDesiredSize(int t) { desired_size = t; }
  virtual int operator[] (int i) const {
    if (i < current_size)
      return elements[i];
    else
      throw("Index out of bounds");
  }
  virtual int& operator[] (int i) {
    if (i < current_size)
      return elements[i];
    else
      throw("Index out of bounds");
  }
};

#endif  // LAB03_14_03_PRJ_INC_TABLICA_H_
