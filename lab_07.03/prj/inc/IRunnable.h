#ifndef IRUNNABLE_H
#define IRUNNABLE_H

class IRunnable {

  virtual void prepare (unsigned int size)=0;

  virtual void run()=0;

};

#endif
