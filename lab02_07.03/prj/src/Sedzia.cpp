// Copyright 2016 Kamil Kuczaj
#include "Sedzia.h"

#include <iostream>
#include <sstream>

bool Sedzia::setOffTable(int how_many) {
  Stoper timer;
  Tablica<int> array;

  std::ostringstream ss;
  ss << how_many;

  array.prepare(how_many);
  timer.start();
  array.run();
  timer.stop();
  timer.dumpToFile(ss.str());

  return true;
}



