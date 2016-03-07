#ifndef ISTOPER_H
#define ISTOPER_H

#include "IStoper.h"

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
