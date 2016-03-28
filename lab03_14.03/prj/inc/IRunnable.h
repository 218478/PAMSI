// Copyright 2016 Kamil Kuczaj
#ifndef LAB03_14_03_PRJ_INC_IRUNNABLE_H_
#define LAB03_14_03_PRJ_INC_IRUNNABLE_H_

/*! \file IRunnable.h
 *
 * \brief Naglowek zawierajacy interfejs dla biegacza.
 * \author Kamil Kuczaj
 */


/*! \brief Interfejs dla biegacza.
 *
 * \details Klasa abstrakcyjna z metodami czysto wirtualnymi.
 */
class IRunnable {
 protected:
  /*! \brief Przygotowuje pojemnik przed wykonaniem czynnosci.
   *
   * \details Funkcja, ktora ma wykonac wszystkie dodatkowe czynnosci,
   *          ktorych czasu nie bedziemy mierzyc. Polega ona na
   *          wczytaniu konkretnej ilosci elementow.
   *
   * \param[in] size Ilosc elementow.
   */
  virtual void prepare(int size) = 0;

  /*! \brief Odpalenie badanej czynnosci.
   *
   * \details Funkcja, ktorej cialem maja byc instrukcje, ktorych czas
   *          chcemy zmierzyc.
   */
  virtual void run() = 0;
};

#endif  // LAB03_14_03_PRJ_INC_IRUNNABLE_H_
