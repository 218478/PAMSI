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
  virtual void prepare(int size) = 0;

  virtual void run() = 0;
};

#endif  // LAB03_14_03_PRJ_INC_IRUNNABLE_H_
