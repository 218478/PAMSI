// Copyright 2016 Kamil Kuczaj
#ifndef LAB08_25_04_PRJ_INC_GRAPHDFS_H_
#define LAB08_25_04_PRJ_INC_GRAPHDFS_H_

#include "IRunnable.h"
#include "Graph.h"

#include <cstdlib>  // to create random connection between vertices
#include <stack>  // to play with a different type of stack
#include <list>    // to play with a different type of list
#include <algorithm>  // find() function and min() function

class GraphDFS : IRunnable {
private:
	/*! \brief Testowany graf.
	 *
	 * \details W celu dalszych informacji na temat tego pola prosze
	 *              odwolac sie do klasy Graph.
	 */
	Graph graph;

public:
	GraphDFS(int how_many) : graph(how_many) {}


	virtual void run() {
		std::list<int> lista;
		std::stack<int> stos;
		graph.print();
		stos.push(0);  // start
		lista.push_back(0);  // start
		static int iter = 0;
		int temp, temp2;
		while (!stos.empty() && iter < 1000) {
			temp = stos.top();
			stos.pop();
			for (int i = 0; i < graph[temp].size(); i++) {
				temp2 = graph[temp].get(i);
				auto it = std::find(lista.begin(), lista.end(), temp2);
				if (it == lista.end()) {
					std::cout << "Lista ";
					for (auto& e: lista)
						std::cout << e << " ";

					std::cout << std::endl << "stos ";
					std::stack<int> stos_temp = stos;
					for (auto e = stos_temp.top(); !stos_temp.empty(); stos_temp.pop(), e = stos_temp.top()) 
						std::cout << e << " ";

					std::cout << std::endl << std::endl;
					lista.push_back(temp2);
					stos.push(temp2);
				}
			}
			std::cout << "Lista ";
			for (auto& e: lista)
				std::cout << e << " ";

			std::cout << std::endl << "stos ";
			std::stack<int> stos_temp = stos;
			for (auto e = stos_temp.top(); !stos_temp.empty(); stos_temp.pop(), e = stos_temp.top()) 
				std::cout << e << " ";

			std::cout << std::endl << std::endl;
			std::cout << "Rozmiar listy: " << lista.size() << std::endl
			<< "Rozmiar kolejki: " << stos.size() << std::endl;
		}
		std::cout << "DFS complete." << std::endl;
}

virtual void prepare(int how_many) {
// everything is done within graph's constructor
}
};

#endif  // LAB08_25_04_PRJ_INC_GRAPHDFS_H_