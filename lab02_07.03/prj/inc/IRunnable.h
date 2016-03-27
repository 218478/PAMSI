// Copyright 2016 Kamil Kuczaj
#ifndef LAB02_07_03_PRJ_INC_IRUNNABLE_H_
#define LAB02_07_03_PRJ_INC_IRUNNABLE_H_

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
  /*! \brief Przygotowanie pojemnika przed pomiarem czasu.
   *
   * \details Metoda czysto wirtualna.
   */
  virtual void prepare(unsigned int size) = 0;

  /*! \brief Uruchomienie czynnosci, ktora bedziemy mierzyc stoperem.
   *
   * \details Metoda czysto wirtualna.
   */
  virtual void run() = 0;
};

#endif  // LAB02_07_03_PRJ_INC_IRUNNABLE_H_
