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
	GraphBFS(int how_many) : graph(how_many) {}

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
	// generation is done within graph's constructor
}
};

#endif  // LAB08_25_04_PRJ_INC_GRAPHBFS_H_