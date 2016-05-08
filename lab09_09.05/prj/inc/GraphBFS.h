// Copyright 2016 Kamil Kuczaj
#ifndef LAB08_25_04_PRJ_INC_GRAPHBFS_H_
#define LAB08_25_04_PRJ_INC_GRAPHBFS_H_

#include "IRunnable.h"
#include "Graph.h"
#include "Kolejka.h"

#include <list>  // to play with a different list
#include <algorithm>
#include <cstdlib>  // to deal with pseudo randomness generation

class GraphBFS : IRunnable {
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
	 std::list<int> lista;

	

public:
		virtual void run() {
		Kolejka<int> kolejka;
		kolejka.push(0);  // start
		int temp, temp2;
		static int iter = 0;
		while (!kolejka.empty()) {
			temp = kolejka.pop();
			for (int i = 0; i < graph[temp].size(); i++) {
				temp2 = graph[temp].get(i);
				auto it = std::find(lista.begin(), lista.end(), temp2);
				if (it == lista.end()) {
					std::cout << iter++ << std::endl;
					lista.push_back(temp2);
					kolejka.push(temp2);
				}
			}
		}
		std::cout << "BFS complete." << std::endl;
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
		for (int i = 0; i < how_many; i++) {
			for (int j = 0; j < 2; j++) {
				temp1 = static_cast<int>(rand()) % how_many;
				graph.addEdge(i, temp1);
			}
		}
	}
};

#endif  // LAB08_25_04_PRJ_INC_GRAPHBFS_H_