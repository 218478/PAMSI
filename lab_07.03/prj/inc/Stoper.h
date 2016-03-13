#ifndef STOPER_H
#define STOPER_H

#include "IStoper.h"

#include <ctime>    // to deal with time operations
#include <fstream>  // to deal with file streams
#include <iostream> // to deal with error stream output

/*! \file Stoper.h
 *
 * \brief Implementacja interfejsu IStoper w klasie Stoper.
 *
 * \author Kamil Kuczaj
 */


/*! \brief Implementacja klasy Stoper.
 *
 * \details W klasie Stoper zostaly zaimplemetowane metody pozwalajace na pomiar
 *          czasu. Pomiar czasu odbywa sie dzieki bibliotece <ctime> a zapis do
 *          pliku korzysta z biblioteki <fstream>.
 */


class Stoper: IStoper {
private:
  /*! \brief Moment startu stopera.
   *
   * \details Element przechowujacy informacje o czasie systemowym w momencie
   *          uruchomienia stopera. Element typu clock_t.
   */
  clock_t _start;

  /*! \brief Moment zatrzymania stopera.
   *
   * \details Element przechowujacy informacje o czasie systemowym w momencie
   *          zatrzymania stopera. Element typu clock_t.
   */
  clock_t _stop;

  /*! \brief Strumien zapisu do pliku.
   *
   * \details Pole ulatwiajace zapis do pliku.
   */
  std::fstream my_file;

public:

  /*! \brief Implementacja funkcji start() z interfejsu IStoper.
   *
   * \details Zapisuje moment uruchomienia stopera.
   */
  virtual void start();

  /*! \brief Implementacja funkcji stop() z interfejsu IStoper.
   *
   * \details Zapisuje moment zatrzymania stopera.
   */
  virtual void stop();

  /*! \brief Implementacja funkcji getElapse() z interfejsu IStoper.
   *
   * \details Oblicza czas pomiedzy czasem zapisanym w zmiennych _start i _stop.
   *
   * \return Zwraca zmierzony czas - roznica pomiedzy polem _start a polem _stop.
   */
  virtual double getElapsedTime();

  /*! \brief Implementacja funkcji dumpToFile() z interfejsu IStoper.
   *
   * \details Zapisuje zmierzony czas do pliku o nazwie "tmp_czasy.txt".
   */
  virtual void dumpToFile();

};

#endif
