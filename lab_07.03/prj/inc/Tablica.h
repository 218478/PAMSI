#ifndef TABLICA_H
#define TABLICA_H

#include "IRunnable.h"

#include <new> // dla sprawdzenia poprawnosci alokacji pamieci
#include <iostream> // dla wyswietlenia bledu

/*! \file Tablica.h
 *
 * \brief Implementacja interfesju IRunnable.
 *
 * \author Kamil Kuczaj
 */

/*! \brief Klasa tablica, w ktorej odbywa sie zapis dynamiczny elementow typu int.
 *
 * \details Implementuje metody interfejsu IRunnable. Zajmuje sie dynamiczna
 *          alokacja pamieci.
 */
class Tablica: IRunnable  {
 private:
  /*! \brief Wskaznik do poczatku tablicy dynamicznej.
   *
   * \details Wskazuje na adres w pamieci sterty. Pole prywatne.
   */
  int *elements;

  /*! \brief Okresla aktualny rozmiar stosu.
   *
   * \details Pole prywatne typu unsigned int, gdyz rozmiar nigdy nie
   *          powinien byc ujemny.
   */
  unsigned int current_size;

  /*! \brief Okresla pozadany rozmiar stosu.
   *
   * \details Pole prywatne typu unsigned int, gdyz rozmiar nigdy nie
   *          powinien byc ujemny. Zadawane w funkcji prepare().
   */
  unsigned int desired_size;

  /*! \brief Okresla aktualny indeks.
   *
   * \details Pole prywatne typu unsigned int, gdyz indeks nigdy nie
   *          powinien byc ujemny. Przechowuje indeks, pierwszej wolnej
   *          komorki pamieci, do ktorego mozliwy bedzie zapis.
   */
  unsigned int index;
  
  /*! \brief Pozwala prosto okreslic, czy nalezy przydzielic pamiec.
   *
   * \details Metoda prywatna. Sluzy do okreslania czy nalezy wywolac
   *          metode increaseSize().
   * 
   * \return true Pamiec pelna. Nalezy zwiekszyc rozmiar.
   *
   * \return false Jest jeszcze wolne miejsce.
   */
  bool isFull();

  /*! \brief Zwieksza rozmiar przydzielonej pamieci na stercie.
   *
   * \details Metoda prywatna. Kopiuje elementy starej pamieci do
   *          komorki z nowo-przydzielona pamiecia. Usuwa stara
   *          pamiec.
   */
  void increaseSize();

 public:

  /*! \brief Konstruktor parametryczny.
   *
   * \details Umozliwia okreslenie poczatkowego rozmiaru tablicy. W przypadku
   *          braku okreslenia tego rozmiaru przyjmuje domyslna wartosc rowna 10.
   *
   * \param x Okresla poczatkowa wielkosc przydzielonej pamieci. Domyslna wartosc
   *          w przypadku braku podania to 10.
   */
  Tablica(int x=10);

  /*! \brief Destruktor.
   *
   * \details Usuwa pamiec przypisana komorce, na ktora wskazuje pole *elements.
   */
  ~Tablica();

  /*! \brief Implementacja funkcji prepare() interfesju IRunnable.
   *
   * \details Zapisuje pozadany rozmiar do pola desired_size.
   *
   * \param size Parametr typu unsigned int, gdyz rozmiar nie powinien nigdy byc
   *             ujemny. Jego wartosc zapisywana jest do pola desired_size.
   */
  virtual void prepare (unsigned int size);

  /*! \brief Implementacja funkcji run() interfesju IRunnable.
   *
   * \details Uruchamia "bieg", w ktorym nastepuje zapis elementow do poszczegolnych
   *          elementow tablicy dynamicznej. Tam odbywa sie alokacja pamieci oraz
   *          instrukcje warunkowe.
   */
  virtual void run();

  /*! \brief Zwraca aktualny rozmiar tablicy dynamicznej.
   *
   * \details Zwraca wartosc pola current_size.
   *
   * \return Zwraca wartosc typu unsigned int, gdyz takiego typu jest zmienna
   *         current_size.
   */
  unsigned int getSize();
};

#endif
