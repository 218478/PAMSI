#ifndef LISTA_H
#define LISTA_H

#include "IRunnable.h"

typedef unsigned int uint;

template <class Type> class Lista: IRunnable {
 public:
  Type add(Type item, uint index);
  Type remove(uint index);
  bool isEmpty();
  Type get(uint index);
  uint size();
};


#endif
