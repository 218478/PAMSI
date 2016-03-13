#ifndef ISTOPER_H
#define ISTOPER_H

/*! \file IStoper.h
 *
 * \brief Naglowek zawierajacy interfejs dla stopera.
 * \author Kamil Kuczaj
 */


/*! \brief Interfejs dla stopera.
 *
 * \details Klasa abstrakcyjna z metodami czysto wirtualnymi.
 */

class IStoper {
 public:
  virtual void start()=0;

  virtual void stop()=0;

  virtual double getElapsedTime()=0;

  virtual void dumpToFile()=0;

};

#endif
