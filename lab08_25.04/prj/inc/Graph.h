// Copyright 2016 Kamil Kuczaj
#ifndef LAB08_25_04_PRJ_INC_GRAPH_H_
#define LAB08_25_04_PRJ_INC_GRAPH_H_

#include "IGraph.h"
#include "Lista.h"

#include <vector>
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
  // Graph(int how_many) { graph.reserve(how_many); }

  virtual void addVertex(int x) {
    if (graph.size() <= x) {
      if (graph.size() == x) {
        //std::cout << "Did not found. Adding." << std::endl;
        graph.push_back(Lista<int>(x));  // adding only vertex, no weight, no edge
      }
      else
        std::cerr << "Index too large." << std::endl;
    }
    else
      std::cerr << "Duplicate. Not adding." << std::endl;
  }

  virtual void addEdge(int x, int y, int weight = 1) {
    if (graph.size() > x && graph.size() > y) {
      std::cout << "Found vertex. Adding" << std::endl;
      ListNode temp(y, weight);  // couldn't do it nicer because g++ complains
      if (graph[x].search(y) == -2)
        graph[x].add(y,weight,graph[x].size());
      else
        std::cerr << "Connection already exists" << std::endl;

      if (graph[y].search(x) == -2)
        graph[y].add(x,weight,graph[y].size());
      else
        std::cerr << "Connection already exists" << std::endl;
    }
    else
      std::cerr << "Did not found vertex no " << x << std::endl;
  }

  virtual void removeVertex(int x) {
    if (x < graph.size()) {
      graph.erase(graph.begin() + x); 
      // RAII should be OK - we call list's destructor here
      for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph[i].size(); j++) {
          if (j == x) graph[i].remove(x);
        }
      }
    }
    else
      std::cerr << "No such vertex no " << x << std::endl;
  }

  virtual void removeEdge(int x, int y) {
    if (x < graph.size() && y < graph.size()) {
      if (graph[x].search(y) == y) {
        graph[x].remove(y);
        graph[y].remove(x);
      }
      else
        std::cerr << "Vertex " << x << " does not border with vertex "
                      << y << std::endl;
    }
    else
      std::cerr << "No such vertex no " << x << std::endl;
  }

  virtual Lista<int> getNeighbours(int x) {
    if (graph.size() <= x) {
      return graph[x];
    }
    else {
      std::cerr << "Vertex " << x << " doesn't exist" << std::endl;
      return Lista<int>(-1);
    }
  }

/*! \brief For debug.
*/
  void print() {
    for (int i = 0; i < graph.size(); i++) {
      std::cout << "wierzcholek: " << i << "\t";
      for (int j = 0; j < graph[i].size(); j++)
        std::cout << graph[i].get(j) <<"(" << graph[i].getWeight(j) << ") ";
      std::cout <<  std::endl;  
    }
  }

  /*! \brief Returns the number of vertices
   *
   * \details Return the size of vector.
   */
  int size() { return graph.size(); }

  /*! \brief Zwraca sasiadujace wierczholki pierwszego wierzcholka grafu.
   */
  Lista<int> front() {
    return graph[0];
  }

  /*! \brief Zwraca sasiadujace wierczholki ostatniego elementu grafu.
   */
  Lista<int> back() {
    return graph[size()-1];
  }

  /*! \brief Zwraca sasiadujace wierzcholki n-tego wierzcholka grafu.
   */
  Lista<int> operator[] (int n) {
    return graph[n];
  }
};


#endif  // LAB08_25_04_PRJ_INC_GRAPH_H_
