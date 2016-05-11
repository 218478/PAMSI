// Copyright 2016 Kamil Kuczaj
#ifndef LAB03_14_03_PRJ_INC_ITABLICA_H_
#define LAB03_14_03_PRJ_INC_ITABLICA_H_

/*! \file ITablica.h
 *
 * \author Kamil Kuczaj
 */

/*! \brief Interfejs tablicy.
 *
 * \details Wymuszony poprzez ISP (programowanie obiektowe SOLID).
 */
template <class Type>
class ITablica {
 protected:
  /*! \brief Sprawdza czy tablica jest pelna.
   *
   * \details Sprawdza czy sa jeszcze wolne komorki pamieci przydzielone
   *          tablicy.
   *
   * \retval true  Tablica pelna. Nalezy zaalokowac nowa pamiec.
   * \retval false Jest jeszcze miejsce.
   */
  virtual bool isFull() = 0;

  /*! \brief Zwieksza rozmiar tablicy
   *
   * \details Alokuje pamiec dla nowej tablicy dynamicznej oraz kopiuje
   *          elementy starej tablicy do nowej. Nastepnie usuwa pamiec
   *          dla starej tablicy.
   */
  virtual void increaseSize() = 0;\

  /*! \brief Zwraca ilosc zapisanych elementow.
   *
   * \details Zwraca ilosc elementow, ktore sa w tablicy. Nie uwzglednia pustych
   *          komorek. Pamietaj, ze indeksujemy od zera, wiec ostatni element
   *          ma indeks (getSize() - 1)
   *
   * \return  Ilosc zapisanych elementow.
   */
  virtual int size() = 0;

  /*! \brief Zwraca maksymalny, pozadany rozmiar tablicy.
   *
   * \details Zwraca ilosc elementow, ktore chcemy zapisac do tablicy.
   *          Nie reprezentuje ilosci zaalokowanej obecnie pamieci dla
   *          komorek. Jedynie idealny stan. Wymagany do testow.
   *          Pamietaj, ze indeksujemy od zera, wiec maksymalnie mozna
   *          zapisac do tablicy (getDesiredSize() - 1) elementow.
   *
   * \return  Maksymalna, satysfakcjonujaca ilosc elementow.
   */
  virtual int capacity() const = 0;

  /*! \brief Ustawia pole desired_size na wartosc, jaka potrzebujemy.
   *
   * \details Ustawia pole. Jest potrzebne gdyz w mechanizmach kontroli
   *          alokacji pamieci i zwiekszania rozmiaru tablicy zwracamy
   *          uwage na to, czy trzeba zwiekszyc rozmiar, czy nasza tablica
   *          jest juz wieksza.
   */
  virtual void setDesiredSize(int t) = 0;

  /*! \brief Akcesor to i-tego elementu tablicy.
   *
   * \details Umozliwia dostep do i-tego elementu. Nie mozemy ta metoda
   *          zmieniac wartosci tego elementu, lecz mozemy go odczytac.
   *
   * \return i-ty element
   */
  virtual Type operator[] (int i) const = 0;

  /*! \brief Modyfikator do i-tego elementu tablicy.
   *
   * \details Umozliwia dostep do i-tego elementu. Mozemy ta metoda
   *          jedynie zmieniac wartosc i-tego elementu, gdyz odwolujemy sie
   *          do niego poprzez referencje.
   *
   * \return Referencja do i-tego elementu
   */
  virtual Type& operator[] (int i) = 0;
};

#endif  // LAB03_14_03_PRJ_INC_ITABLICA_H_
