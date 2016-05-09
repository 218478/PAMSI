// Copyright 2016 Kamil Kuczaj
#ifndef LAB08_25_04_PRJ_INC_GRAPH_H_
#define LAB08_25_04_PRJ_INC_GRAPH_H_

#include "IGraph.h"
#include "Lista.h"

#include <vector>
#include <iostream>
#include <cstdlib>

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
  Graph(int how_many) {
    // creating how_many vertices and connecting them
    addVertex(0);
    for (int i = 1; i < how_many; i++) {
      addVertex(i);
      addEdge(i,i-1);  // weight = 1
    }
    addEdge(0,how_many-1);

    srand(time(0));
    int temp1;  // to shorten the code, to connect vertices randomly
    for (int i = 0; i < how_many/2; i++) {
      for (int j = 0; j < 1; j++) {
        temp1 = static_cast<int>(rand()) % how_many;
        addEdge(i, temp1);
      }
    }

    for (int i = 0; i < how_many; i++) {
      graph[i].remove(0);
    }
  }

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
      //std::cout << "Found vertex. Adding" << std::endl;
      ListNode temp(y, weight);  // couldn't do it nicer because g++ complains
      if (graph[x].search(y) == -2 )
        graph[x].add(y,weight,graph[x].size());
      // else
      //   std::cerr << "Connection already exists" << std::endl;

      if (graph[y].search(x) == -2 )
        graph[y].add(x,weight,graph[y].size());
      // else
      //   std::cerr << "Connection already exists" << std::endl;
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

  // cos jest tutaj zle, narazie dziala, ale trzeba to zmienic bo nie chce mi
  // usuwac poczatkowych krawedzi w liscie
  virtual void removeEdge(int x, int y) {
    if (x < graph.size() && y < graph.size()) {
      if (graph[x].search(y) > 0 || graph[y].search(x) > 0) {
        graph[x].remove(y);
        graph[y].remove(x);
      }
      else {
                std::cout << "search dla poz: "  << x << " od " << y
                      << " wyszedl: " << graph[x].search(y) << std:: endl;
        std::cerr << "Vertex " << x << " does not border with vertex "
                      << y << std::endl;
      }
    }
    else
      std::cerr << "No such vertex no " << x << std::endl;
  }

  virtual Lista<int> getNeighbours(int x) {
    if (graph.size() > x) {
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
  /*! \brief Sprawdza czy wierzcholki polaczone sa krawedzia.
  */
  bool isEdge(int u, int v) {
    if (graph.size() > u) {
      if (graph[u].search(v) > 0)
        return true;
    }
    else {
      std::cerr << "No vertex no: " << u << std::endl;
      return false;
    }
  }

  /*! \brief Algorytm branch & bound bez extended list.
   *
   * \details Algoyrtm domniemywa, ze graf jest skonczony oraz wszystkie
   *              wierzcholki sa w jakis sposob ze soba polaczone.
   */
  Lista<int> branchBound() {
    Lista<int> temp = getNeighbours(1);
    print();
    std::cout << std::endl;
    temp.print();

    
  }

  /*! \brief Algorytm branch & bound wykorzystujacy extended list.
     *
     * \details Algoyrtm domniemywa, ze graf jest skonczony oraz wszystkie
     *              wierzcholki sa w jakis sposob ze soba polaczone.
     */
  Lista<int> branchBoundExtendedList() {

  }
};


#endif  // LAB08_25_04_PRJ_INC_GRAPH_H_
