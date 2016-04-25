// Copyright 2016 Kamil Kuczaj
#ifndef LAB08_25_04_PRJ_INC_IGRAPH_H_
#define LAB08_25_04_PRJ_INC_IGRAPH_H_

#include <list>

template <class Type>
class IGraph {
 public:
  virtual void addVertex(Type x) = 0;
  virtual void addEdge(Type x, Type y, int weight = 1) = 0;
  virtual void removeVertex(Type x) = 0;
  virtual void removeEdge(Type x, Type y) = 0;
  virtual std::list<Type> getNeighbours(Type x) = 0;
};

#endif  // LAB08_25_04_PRJ_INC_IGRAPH_H_
