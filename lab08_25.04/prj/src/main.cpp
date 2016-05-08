// Copyright 2016 Kamil Kuczaj
#include "Sedzia.h"

#include <iostream>

/*! \mainpage Opis programu
 *
 * \author Kamil Kuczaj <218478@student.pwr.edu.pl>
 *
 * \section intro_sec Wstep
 *
 * Program zostal zbudowany modulowo. W folderze inc/ znajduja sie pliki naglowkowe.
 * Folder src/ zawiera pliki zrodlowe. W glownym folderze zbudowany zostal Makefile.
 * Pliki obiektowe sa budowane w folderze obj/ a nastepnie linkowane do glownego
 * folderu (prj/). Testowano przy wykorzystaniu kompilatora g++ w wersji 4.8.4 na
 * systemie Linux Ubuntu 14.04.04 opartego o jadro 4.2.0-30-generic.
 *
 * \section Licencja
 *
 * Program udostepniam na licencji GPLv3.
 *
 * \section install_sec Instalacja
 *
 * Aby zbudowac i jednoczesnie odpalic program:
 * $ make
 *
 * Aby pozbyc sie plikow z koncowka *~ lub zaczynajacych sie na #*:
 * $ make order
 *
 * Aby pozbyc sie programu wykonywalnego oraz plikow obiektowych:
 * $ make clean
 *
 * Aby wyswietlic pomoc do pliku Makefile:
 * $ make help
 */

int main(int argc, char **argv) {
  Sedzia referee;
  int trials_count = 1;

  // dziesiec, tysiac, sto tysiecy, milion, milard
  // int data_sizes[5]= {10, 1000, 100000, 1000000, 1000000000};

  // running the array
  for (int i = 0; i < 1; i++) {
    for (int j = 0; j < trials_count; j++)
      referee.setOffGraphDFS(3);
  }
}
