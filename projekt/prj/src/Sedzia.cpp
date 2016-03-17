#include "Sedzia.h"

bool Sedzia::setOff(unsigned int how_many) {

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
