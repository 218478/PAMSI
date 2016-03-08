#include "Sedzia.h"


bool Sedzia::setOff(unsigned int how_many) {

  Stoper timer;
  Tablica array;

  array.prepare(how_many);
  timer.start();
  array.run();
  timer.stop();

  std::cout << std::setw(15) << array.getSize() << " el."
	    << std::setw(20) << timer.getElapsedTime()/100.0 << " ms" << std::endl;

  return true;
}
