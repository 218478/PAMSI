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
  virtual bool isFull();

  /*! \brief Zwieksza rozmiar przydzielonej pamieci na stercie.
   *
   * \details Metoda prywatna. Kopiuje elementy starej pamieci do
   *          komorki z nowo-przydzielona pamiecia. Usuwa stara
   *          pamiec.
   */
  virtual void increaseSize();

  /*! \brief Konstruktor parametryczny.
   *
   * \details Umozliwia okreslenie poczatkowego rozmiaru tablicy. W przypadku
   *          braku okreslenia tego rozmiaru przyjmuje domyslna wartosc rowna 10.
   *          Explicit oznacza tyle, ze nie moge stworzyc tablicy w ten sposob:
   *          Tablica t = 10;
   *
   * \param x Okresla poczatkowa wielkosc przydzielonej pamieci. Domyslna wartosc
   *          w przypadku braku podania to 10.
   */
  explicit Tablica(int x = 10);

  /*! \brief Destruktor.
   *
   * \details Usuwa pamiec przypisana komorce, na ktora wskazuje pole *elements.
   */
  ~Tablica();

  /*! \brief Zwraca aktualny rozmiar tablicy dynamicznej.
   *
   * \details Zwraca wartosc pola current_size.
   *
   * \return Zwraca wartosc typu int. Reprezentuje ilosc danych w tablilcy.
   */
  virtual int getSize();
  
  /*! \brief Zwraca wartosc desired_size.
   *
   * \details Zwraca rozmiar, ktory ma osiagnac tablica. Moze byc wieksza niz
   *          desired_size.
   */
  virtual int getDesiredSize() const;

  /*! \brief Ustawia wartosc desired_size.
   *
   * \details Ustawia rozmiar, ktory ma osiagnac tablica.
   */
  virtual void setDesiredSize(int t);

  /*! \brief Akcesor do tablicy.
   *
   * \details Umozliwia dostep do tablicy.
   *
   * \param[in] i Indeks, w ktorym wartosc tablicy ma zostac zwrocona.
   *
   * \return Wartosc komorki tablicy, wskazywana przez i-ty indeks.
   */
  virtual int operator[] (int i) const;

  /*! \brief Modyfikator do tablicy.
   *
   * \details Umozliwia dostep do zmiany i-tego elementu w tablicy.
   *
   * \param[in] i Wskazuje element, ktory ma zostac zmieniony.
   *
   * \return Referencja do i-tego elementu.
   */
  virtual int& operator[] (int i);

  /*! \brief Sortowanie babelkowe.
   *
   * \details Sortuje elementy metoda babelkowa. Zlozonosc obliczeniowa n^2.
   */
  void bubbleSort();
};

#endif  // LAB03_14_03_PRJ_INC_TABLICA_H_
