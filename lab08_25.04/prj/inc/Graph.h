// Copyright 2016 Kamil Kuczaj
#ifndef LAB08_25_04_PRJ_INC_GRAPH_H_
#define LAB08_25_04_PRJ_INC_GRAPH_H_

#include "IGraph.h"
#include "Lista.h"

#include <vector>
#include <algorithm>
#include <iostream>

/*! \brief Graf oparty o liste sasiedztwa.
 *
 * \details Lista sasiedztwa zostala wybrana jako sposob implementacji
 *          grafu, gdyz algorytmy przeszukania grafu BFS oraz DFS sa na
 *          niej szybsze. Dodatkowo, dodaje wierzcholki juz posortowane.
 *          Dzieki temu, pojemnik jest bardziej czytelny.
 */
class Graph : public IGraph {
private:


  /*! \brief Pole, ktore bedzie reprezentowac graf..
   *
   * \details Uzylem elementow biblioteki STL, gdyz sa lepsze od moich. Tzn.
   *              nie musze skupiac sie na poprawianiu starych struktur, tylko
   *              moge skupic sie na implementacji grafu.
   */
   std::vector< Lista<int> > graph;

 public:
  virtual void addVertex(int x) {
    if (graph.size() <= x) {
      if (graph.size() == x) {
        std::cout << "Did not found. Adding." << std::endl;
        graph.push_back(Lista<int>(x));  // adding only vertex, no weight, no edge
      }
      else
        std::cerr << "Index too large." << std::endl;
    }
    else
      std::cerr << "Duplicate. Not adding." << std::endl;
  }

//   virtual void addEdge(int x, int y, int weight = 1) {
//     // typename std::vector<GraphNode>::iterator it;  // WATCH OUT, ITS STRANGE
//     // it = find(graph.begin(), graph.end(), GraphNode(x));
//     // if (it != graph.end())
//     // {
//     //   std::cout << "Found vertex. Adding" << std::endl;
//     //   ListNode temp(y, weight);  // couldn't do it nicer because g++ complains
//     //   it.v.push_back(temp);
//     // }
//     // else
//     // {
//     //   std::cerr << "Did not found vertex no " << x << std::endl;
//     // }
//   }

//   virtual void removeVertex(int x) {
//     // typename std::vector<GraphNode>::iterator it;  // WATCH OUT, ITS STRANGE
//     // it = find(graph.begin(), graph.end(), GraphNode(x));
//     // if (it != graph.end())
//     //   graph.erase(graph.begin() + x); 
//     //   // RAII should be OK - we call list's destructor here
//     // else
//     //   std::cerr << "No such vertex no " << x << std::endl;
//   }

//   virtual void removeEdge(int x, int y) {
//     // typename std::vector<GraphNode>::iterator it1;  // WATCH OUT, ITS STRANGE
//     // it1 = find(graph.begin(), graph.end(), GraphNode(x));
//     // if (it1 != graph.end()) {
//     //   typename std::list<ListNode>::iterator it2;
//     //   it2 = find(graph[x].v.begin(), graph[x].v.end(), y);
//     //   if (it2 != graph[x].v.end())
//     //     graph[x].v.erase(graph[x].v.begin() + y);
//     //   else
//     //     std::cerr << "Vertex " << x << " does not border with vertex "
//     //                   << y << std::endl;
//     // }
//     // else
//     //   std::cerr << "No such vertex no " << x << std::endl;
//   }

//   virtual std::list<ListNode> getNeighbours(int x) {
//     // typename std::vector<GraphNode>::iterator it1;  // WATCH OUT, ITS STRANGE
//     // it1 = find(graph.begin(), graph.end(), GraphNode(x));
//     // if (it1 != graph.end()) {
//     //   return graph[x].v;
//     // }
//     // else
//     //   std::cerr << "Vertex " << x << " doesn't exist" << std::endl;
//   }
};


#endif  // LAB08_25_04_PRJ_INC_GRAPH_H_
