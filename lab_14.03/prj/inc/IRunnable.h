#ifndef IRUNNABLE_H
#define IRUNNABLE_H

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
  virtual void prepare (unsigned int size)=0;

  virtual void run()=0;

};

#endif
