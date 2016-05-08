// Copyright 2016 Kamil Kuczaj
#ifndef LAB03_14_03_PRJ_INC_STOPER_H_
#define LAB03_14_03_PRJ_INC_STOPER_H_

#include "IStoper.h"

#include <sys/time.h>  // to deal with time operations
#include <fstream>     // to deal with file streams
#include <iostream>    // to deal with error stream output
#include <string>      // to deal with getting file name saved to a variable

/*! \file Stoper.h
 *
 * \brief Implementacja interfejsu IStoper w klasie Stoper.
 *
 * \author Kamil Kuczaj
 */


/*! \brief Implementacja klasy Stoper.
 *
 * \details W klasie Stoper zostaly zaimplemetowane metody pozwalajace na pomiar
 *          czasu. Pomiar czasu odbywa sie dzieki bibliotece <sys/time.h>
 *          a zapis do pliku korzysta z biblioteki <fstream>.
 */


class Stoper: IStoper {
 private:
  /*! \brief Moment startu stopera.
   *
   * \details Element przechowujacy informacje o czasie systemowym w momencie
   *          uruchomienia stopera. Element timeval. Nazwa zgodna
   *          konwencja podrecznika "Google C++ Style Guide".
   */
  timeval *start_time;

  /*! \brief Moment zatrzymania stopera.
   *
   * \details Element przechowujacy informacje o czasie systemowym w momencie
   *          zatrzymania stopera. Element typu timeval. Nazwa zgodna
   *          konwencja podrecznika "Google C++ Style Guide".
   */
  timeval *stop_time;

 public:
 /*! \brief Konstruktor bezparametryczny.
  *
  * \details Alokuje pamiec dla pol, poniewaz sa wskaznikami.
  */
  Stoper();

 /*! \brief Destruktor.
  *
  * \details Zwalniam pamiec po polach.
  */
  ~Stoper();

  /*! \brief Implementacja funkcji start() z interfejsu IStoper.
   *
   * \details Zapisuje moment uruchomienia stopera. Korzysta z metody
   *          gettimeofday().
   */
  virtual void start();

  /*! \brief Implementacja funkcji stop() z interfejsu IStoper.
   *
   * \details Zapisuje moment zatrzymania stopera. Korzysta z metody
   *          gettimeofday().
   */
  virtual void stop();

  /*! \brief Implementacja funkcji getElapse() z interfejsu IStoper.
   *
   * \details Oblicza czas pomiedzy czasem zapisanym w zmiennych start_time
   *          i stop_time.
   *
   * \return Zwraca zmierzony czas - roznica pomiedzy polem start_time
   *         a polem stop_time. Zwraca wynik w mikrosekundach.
   */
  virtual double getElapsedTime();

  /*! \brief Implementacja funkcji dumpToFile() z interfejsu IStoper.
   *
   * \details Zapisuje zmierzony czas do pliku o nazwie "${file_name}.csv".
   *          Plik otwierany w trybie dopisywania (append) oraz wyjsciowym
   *          (out). Plik .csv to tzw. Comma-Separated Values - latwo je
   *          potem zaimportowac do arkusza kalkulacyjnego oraz sa zgodne
   *          z ogolno przyjetym standardem.
   *
   * \param file_name Nazwa pliku, do ktorego beda zapisane dane. Nazwa nie
   *                  nie powinna zawierac rozszerzenia. Rozszerzenie jest
   *                  dodawane w funkcji.
   */
  virtual void dumpToFile(std::string file_name);
};

#endif  // LAB03_14_03_PRJ_INC_STOPER_H_
