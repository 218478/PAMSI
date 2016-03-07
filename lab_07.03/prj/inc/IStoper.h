#ifndef ISTOPER_H
#define ISTOPER_H

#include <ctime>   // to deal with time operations
#include <fstream> // to deal with file streams

class IStoper {
 public:
  virtual void start()=0;

  virtual void stop()=0;

  virtual double getElapsedTime()=0;

  virtual void dumpToFile()=0;

};

#endif
