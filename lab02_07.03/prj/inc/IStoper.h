// Copyright 2016 Kamil Kuczaj
#ifndef LAB02_07_03_PRJ_INC_ISTOPER_H_
#define LAB02_07_03_PRJ_INC_ISTOPER_H_

#include <string>  // to deal with file_name as an argument in dumpToFile() func

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
 protected:
  /*! \brief Ma symulowac moment startu stopera.
   *
   * \details Metoda czysto wirtualna.
   */
  virtual void start() = 0;

  /* ! \brief Ma symulowac moment zatrzymania stopera.
   *
   * \details Metoda czysto wirtualna.
   */
  virtual void stop() = 0;

  /*! \brief Ma symulowac rezultat pokazania wyniku pomiaru czasu na stoperze.
   *
   * \details Metoda czysto wirtualna.
   */
  virtual double getElapsedTime() = 0;

  /*! \brief Ma symulowac moment zapisu zmierzonego czasu na kartke papieru.
   *
   * \details Metoda czysto wirtualna.
   *
   * \param file_name Nazwa pliku. Obiekt klasy string.
   */
  virtual void dumpToFile(std::string file_name) = 0;
};

#endif  // LAB02_07_03_PRJ_INC_ISTOPER_H_
