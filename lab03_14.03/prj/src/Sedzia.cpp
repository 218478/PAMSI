// Copyright 2016 Kamil Kuczaj
#include "Sedzia.h"
#include "Stoper.h"
#include "Lista_test.h"
#include "Stos_test.h"
#include "Kolejka_test.h"

#include "Lista.h"

#include <unistd.h>  // to make Linux wait because searching is too fast

#include <sstream>   // to convert int to string
#include <string>    // to deal with strings
#include <iostream>  // to display messages

void Sedzia::setOffList(int how_many, int trials_count) {
  // Lista_test lista_testowa;
  // Stoper timer;

  Lista<int>  liscik;
try{
  for (int i = 0; i < 10; i++)
    liscik.push_back(i);
  liscik.add(2,1);
  liscik.print();

  std::cout << "szukam trojeczki. Rezultat: " << liscik.search(3) << std::endl;

  std::cout << "\nRemoving..." << std::endl;
  liscik.remove(0);
  liscik.remove(1);
  liscik.print();

  std::cout << "szukam trojeczki. Rezultat: " << liscik.search(3) << std::endl;
}
catch (const char *msg) {
  std::cout << msg << std::endl;
}

  // std::ostringstream ss;
  // ss << "Lista_" << how_many;
  // timer.start();
  // lista_testowa.prepare(how_many);
  // timer.stop();

  // for (int i = 0; i < trials_count; i++) {
  //   timer.start();
  //   lista_testowa.run();
  //   timer.stop();
  //   timer.dumpToFile(ss.str());
  //   sleep(1);  // sleep for a second to get a new random seed from the clock
  // }
}

void Sedzia::setOffStack(int how_many) {
  Stos_test stos_testowy;
  Stoper timer;

  stos_testowy.prepare(how_many);
}

void Sedzia::setOffQueue(int how_many) {
  Kolejka_test kolejka_testowa;
  Stoper timer;

  kolejka_testowa.prepare(how_many);
}
