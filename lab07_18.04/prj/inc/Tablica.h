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
template <class Type>
class Array: ITablica<Type>  {
 private:
  /*! \brief Wskaznik do poczatku tablicy dynamicznej.
   *
   * \details Wskazuje na adres w pamieci sterty. Pole prywatne.
   */
  Type *elements;

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
      Type *new_elements = new Type[new_size];
      for (int i = 0; i < current_size; i++)
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
   *          Explicit oznacza tyle, ze nie moge stworzyc tablicy w ten sposob:
   *          Tablica t = 10;
   *
   * \param x Okresla poczatkowa wielkosc przydzielonej pamieci. Domyslna wartosc
   *          w przypadku braku podania to 10.
   */
  explicit Array(int x = 10) {
    elements = new Type[x]; current_size = x; index = 0;
  }

  /*! \brief Destruktor.
   *
   * \details Usuwa pamiec przypisana komorce, na ktora wskazuje pole *elements.
   */
  ~Array() { delete [] elements; }

  /*! \brief Zwraca aktualny rozmiar tablicy dynamicznej.
   *
   * \details Zwraca wartosc pola current_size.
   *
   * \return Zwraca wartosc typu int. Reprezentuje ilosc danych w tablilcy.
   */
  virtual int getSize() { return current_size; }

  /*! \brief Zmniejsza zmienna przechowujaca rozmiar tablicy.
   *
   * \details Zmniejsza rozmiar, zmienna current_size o n. Stworzenie
   *          tej funkcji zostalo wymuszone przez implementacje listy.
   *          Uzywanie funkcji remove(int n) z klasy Lista powodowalo to,
   *          ze jej rozmiar faktycznie malal o jeden element, ale klasa
   *          Tablica o tym nie wiedziala.
   *
   * \param[in] n O ile zmniejszyc zmienna current_size.
   */
  void decreaseSize(int n) { current_size -= n; }

  /*! \brief Zwraca wartosc desired_size.
   *
   * \details Zwraca rozmiar, ktory ma osiagnac tablica. Moze byc wieksza niz
   *          desired_size.
   */
  virtual int getDesiredSize() const { return desired_size; }

  /*! \brief Ustawia wartosc desired_size.
   *
   * \details Ustawia rozmiar, ktory ma osiagnac tablica.
   */
  virtual void setDesiredSize(int t) { desired_size = t; }

  /*! \brief Akcesor do tablicy.
   *
   * \details Umozliwia dostep do tablicy.
   *
   * \param[in] i Indeks, w ktorym wartosc tablicy ma zostac zwrocona.
   *
   * \return Wartosc komorki tablicy, wskazywana przez i-ty indeks.
   */
  virtual Type operator[] (int i) const {
    if (i < current_size)
      return elements[i];
    else
      throw("Index out of bounds");
  }

  /*! \brief Modyfikator do tablicy.
   *
   * \details Umozliwia dostep do zmiany i-tego elementu w tablicy.
   *
   * \param[in] i Wskazuje element, ktory ma zostac zmieniony.
   *
   * \return Referencja do i-tego elementu.
   */
  virtual Type& operator[] (int i) {
    std::cout << "i: " << i << "\tcurrent_size: " << current_size << std::endl;
    if (i < current_size) {
      index++;
      return elements[i]; }
    else
      throw("Index out of bounds");
  }

  /*! \brief Sortowanie babelkowe.
   *
   * \details Sortuje elementy metoda babelkowa. Zlozonosc obliczeniowa n^2.
   */
  void bubbleSort() {
    Type temp;
    int n = getSize();

    for (int i = 1; i < n; i++) {
      for (int j = 0; j < (n-i); j++) {
        if (elements[j+1] < elements[j]) {
          temp = elements[j];
          elements[j] = elements[j+1];
          elements[j+1] = temp;
        }
      }
    }
  }
};

#endif  // LAB03_14_03_PRJ_INC_TABLICA_H_
