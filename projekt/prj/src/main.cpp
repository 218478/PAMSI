#include "Sedzia.h"
#include "Lista.h"

#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

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
 * systemie Linux Ubuntu 14.04.04 opartego o jądro 4.2.0-30-generic.
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
  // information for the user
  cout << "!!! INFO: Program starts indexing at 0, not at 1 !!!" << endl << endl;

  // Poprzednie zadanie
  //  
  // //dziesiec, tysiac, sto tysiecy, milion, milard
  // unsigned int data_sizes [5]= {10,1000,100000,1000000,1000000000};
  // int trial_count = 50; // ile razy nalezy zapisac dane

  // Sedzia referee;
  // for(int j = 0; j < 5; j++) {
  //   for(int i = 0; i < trial_count; i++)
  //     referee.setOff(data_sizes[j]);
  // }

  Lista<string> list;
  // // it works and should display: 5 3 4 2 1 6
  // list.add(1,0);
  // list.add(2,0);
  // list.add(3,0);
  // list.add(4,1);
  // list.add(5,0);
  // list.add(6,5);
  // cout << "Found first '4' at index: " << list.run(4) << endl;
  list.prepare(10);

  cout << "Rozmiar listy: " << list.size() << endl;
  cout << "Zawartosc listy:" << endl;
  list.print();

  cout << "Found 'ab' at index: " << list.run("ab") << endl;

  cout << "Trying to remove index no: " << list.run("ab") << endl;
  list.remove(list.run("ab"));

  cout << "Rozmiar listy: " << list.size() << endl;
  cout << "Zawartosc listy:" << endl;
  list.print();

  cout << "Found 'abaci' at index: " << list.run("abaci") << endl;
  cout << "Didn't found 'ab', because of error no: " << list.run("ab") << endl;

}
