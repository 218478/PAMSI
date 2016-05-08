// Copyright 2016 Kamil Kuczaj
#ifndef LAB08_25_04_PRJ_INC_IGRAPH_H_
#define LAB08_25_04_PRJ_INC_IGRAPH_H_

#include "Lista.h"

struct ListNode {
    int key;  // opposing vertex
    int w;  // weight
    ListNode(int y, int weight) : key(y), w(weight) {}
  };

class IGraph {
 public:
  virtual void addVertex(int x) = 0;
  virtual void addEdge(int x, int y, int weight = 1) = 0;
  virtual void removeVertex(int x) = 0;
  virtual void removeEdge(int x, int y) = 0;
  virtual Lista<int> getNeighbours(int x) = 0;
};

#endif  // LAB08_25_04_PRJ_INC_IGRAPH_H_
