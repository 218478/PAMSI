// Copyright 2016 Kamil Kuczaj
#include "Sedzia.h"
#include "Stoper.h"
#include "Tablica_test.h"
#include "Lista_test.h"
#include "Stos_test.h"
#include "Kolejka_test.h"
#include "HashTable_test.h"

#include <unistd.h>  // to make Linux wait because searching is too fast

#include <sstream>   // to convert int to string
#include <string>    // to deal with strings
#include <iostream>  // to display messages


void Sedzia::setOffTable(int how_many) {
  Stoper timer;
  Tablica_test tablica_testowa;

  std::ostringstream ss;
  ss << "Tablica_" << how_many;

  tablica_testowa.prepare(how_many);
  timer.start();
  tablica_testowa.run();
  timer.stop();
  timer.dumpToFile(ss.str());
}


void Sedzia::setOffList(int how_many, int trials_count) {
  Lista_test lista_testowa;
  Stoper timer;

  std::ostringstream ss;
  ss << "Lista_" << how_many;
  timer.start();
  lista_testowa.prepare(how_many);
  timer.stop();
  std::cout << "Preparation of " << how_many << "-size list took: "
            << timer.getElapsedTime() << " microseconds" << std::endl;

  for (int i = 0; i < trials_count; i++) {
    timer.start();
    lista_testowa.run();
    timer.stop();
    std::cout << "Search took: " << timer.getElapsedTime()
              << " microseconds. Saving to file." << std::endl;
    timer.dumpToFile(ss.str());
    sleep(1);  // sleep for a second to get a new random seed from the clock
  }
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

void Sedzia::setOffHashTable(int how_many) {
  Stoper timer;
  HashTable_test tablica_testowa(how_many);

  std::ostringstream ss;
  ss << "TablicaHashowa_" << how_many;

  tablica_testowa.prepare(how_many);
  timer.start();
  tablica_testowa.run();
  timer.stop();
  timer.dumpToFile(ss.str());
}
