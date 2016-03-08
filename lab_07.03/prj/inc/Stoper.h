#ifndef STOPER_H
#define STOPER_H

#include "IStoper.h"

#include <ctime>   // to deal with time operations
#include <fstream> // to deal with file streams

class Stoper: IStoper {
private:
  clock_t _start, _stop;

public:
  virtual void start();

  virtual void stop();

  virtual double getElapsedTime();

  virtual void dumpToFile();


};

#endif
