#include "Sedzia.h"

bool Sedzia::setOff(unsigned int how_many) {

  Stoper timer;
  Tablica array;

  array.prepare(how_many);
  timer.start();
  array.run();
  timer.stop();
  timer.dumpToFile();

  std::cout << std::setw(15) << array.getSize() << " el."
	    << std::setw(20) << timer.getElapsedTime() << " ms" << std::endl;

  return true;
}
