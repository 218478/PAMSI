#include "Stoper.h"



void Stoper::start() {
  _start = clock();
}

void Stoper::stop() {
  _stop = clock();
}

double Stoper::getElapsedTime() {
  return static_cast<double>(_stop-_start)/CLOCKS_PER_SEC;
}

void Stoper::dumpToFile() {
  
}
