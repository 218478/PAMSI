// Copyright 2016 Kamil Kuczaj
#ifndef LAB08_25_04_PRJ_INC_GRAPH_H_
#define LAB08_25_04_PRJ_INC_GRAPH_H_

#include "IGraph.h"

#include <list>

template <class Type>
class Graph : public IGraph<Type> {
 private:

 public:
  virtual void addVertex(Type x) {
  }

  virtual void addEdge(Type x, Type y, int weight = 1) {
  }

  virtual void removeVertex(Type x) {
  }

  virtual void removeEdge(Type x, Type y) {
  }

  virtual std::list<Type> getNeighbours(Type x) {
  }
};


#endif  // LAB08_25_04_PRJ_INC_GRAPH_H_
