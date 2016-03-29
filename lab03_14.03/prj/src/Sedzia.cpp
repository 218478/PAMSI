// Copyright 2016 Kamil Kuczaj
#include "Sedzia.h"
#include "Stoper.h"
#include "Tablica_test.h"
#include "Lista_test.h"
#include "Stos_test.h"
#include "Kolejka_test.h"

#include <sstream>   // to convert int to string
#include <string>    // to deal with strings

bool Sedzia::setOffTable(int how_many) {
  Stoper timer;
  Tablica_test tablica_testowa;

  std::ostringstream ss;
  ss << how_many;

  tablica_testowa.prepare(how_many);
  timer.start();
  tablica_testowa.run();
  timer.stop();
  timer.dumpToFile(ss.str());

  return true;
}


bool Sedzia::setOffList(int how_many) {
  Lista_test lista_testowa;
  Stoper timer;

  lista_testowa.prepare(how_many);
  timer.start();
  lista_testowa.run();
  timer.stop();
  return true;
}
