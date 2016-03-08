#ifndef IRUNNABLE_H
#define IRUNNABLE_H

class IRunnable {

  virtual bool prepare (unsigned int size)=0;

  virtual bool run()=0;

};

#endif
