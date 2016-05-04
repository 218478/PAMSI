// Copyright 2016 Kamil Kuczaj
#ifndef LAB08_25_04_PRJ_INC_GRAPH_H_
#define LAB08_25_04_PRJ_INC_GRAPH_H_

#include "IGraph.h"

#include <list>
#include <vector>
#include <algorithm>
#include <iostream>

/*! \brief Graf oparty o liste sasiedztwa.
 *
 * \details Lista sasiedztwa zostala wybrana jako sposob implementacji
 *              grafu, gdyz algorytmy przeszukania grafu BFS oraz DFS sa na
 *              niej szybsze.
 */
template <class Type>
class Graph : public IGraph<Type> {
private:
  struct GraphNode {
    Type key;
    std::list<Type> *v;
    GraphNode(Type x) : key(x), v(nullptr) {}
  };

  /*! \brief Pole, ktore bedzie reprezentowac graf..
   *
   * \details Uzylem elementow biblioteki STL, gdyz sa lepsze od moich. Tzn.
   *              nie musze skupiac sie na poprawianiu starych struktur, tylko
   *              moge skupic sie na implementacji grafu.
   */
   std::vector<GraphNode> graph;

 public:
  virtual void addVertex(Type x) {
    typename std::vector<GraphNode>::iterator it;  // WATCH OUT, ITS STRANGE
    it = find(graph.begin(), graph.end(), GraphNode(x));
    if (it != graph.end())
      std::cout << "Found" << std::endl;
    else
      std::cout << "Did not found" << std::endl;
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
