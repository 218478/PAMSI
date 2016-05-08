// Copyright 2016 Kamil Kuczaj
#ifndef LAB08_25_04_PRJ_INC_GRAPHDFS_H_
#define LAB08_25_04_PRJ_INC_GRAPHDFS_H_

#include "IRunnable.h"
#include "Graph.h"
#include "Stos.h"
#include "Lista.h"

#include <cstdlib>  // to create random connection between vertices
#include <algorithm>  // find() function and min() function

class GraphDFS : IRunnable {
private:
	/*! \brief Testowany graf.
	 *
	 * \details W celu dalszych informacji na temat tego pola prosze
	 *              odwolac sie do klasy Graph.
	 */
	 Graph graph;

	/*! \brief Przechowuje liste wierzcholkow.
	 *
	 * \details Przechowuje liste wierzcholkow badanego grafu.
	 */
	 Lista<int> lista;

	 /*! \brief Przechowuje tymczasowe odwiedzone wierzcholki.
	  *
	  * \details Warunek DFSu.
	  */
	  Stos<int> stos;

	enum VertexState { White, Gray, Black };

	int graph_size;
public:
 
	void DFS() {
      		int *state = new int[graph_size];
      		for (int i = 0; i < graph_size; i++)
	            state[i] = White;
	      runDFS(0, state);
	      delete [] state;
	}
 
	void runDFS(int u, int state[]) {
      		state[u] = Gray;
      		for (int v = 0; v < graph_size; v++)
            	if (graph.isEdge(u, v) && state[v] == White)
             	runDFS(v, state);
      		state[u] = Black;
	}

	virtual void run() {
		// graph.print();
		// stos.push(0);  // start
		// lista.add(0,1,0);
		// int temp1 = 0;	int temp2 = 0;
		// static int i = 0;
		// while (!stos.empty() && i++ != 1000) {
		// 	std::cout << std::endl;
		// 	stos.print();
		// 	std::cout << std::endl;
		// 	temp1 = graph[temp1].min(lista);
		// 	temp2 = lista.search(temp2);
		// 	if (temp2 < 0) {
		// 		stos.push(temp1);  // if we havent visited the vertex
		// 		lista.add(temp1,1,lista.size()-1);
		// 	}
		// 	else
		// 		temp1 = stos.pop();
		// }
		// lista.print();
		DFS();
		std::cout << "DFS complete." << std::endl;
	}

	virtual void prepare(int how_many) {
		// creating how_many vertices and connecting them
		for (int i = 0; i < how_many; i++) {
			graph.addVertex(i);
			graph.addEdge(i,i-1);  // no weight
		}
		graph.addEdge(0,how_many-1);

		srand(time(0));
		int temp1;  // to shorten the code, to connect vertices randomly
		for (int i = 0; i < how_many/2; i++) {
			for (int j = 0; j < 1; j++) {
				temp1 = static_cast<int>(rand()) % how_many;
				graph.addEdge(i, temp1);
			}
		}
		graph_size = how_many;
	}
};

#endif  // LAB08_25_04_PRJ_INC_GRAPHDFS_H_