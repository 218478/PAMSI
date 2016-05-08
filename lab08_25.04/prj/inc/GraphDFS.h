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

	public:
		virtual void run() {
			graph.print();
			stos.push(0);  // start
			int temp1, temp2;
			static int i = 0;
			while (!stos.empty() && i++ != 1000) {
				temp1 = stos.pop();
				std::cout << std::endl;
				stos.print();
				std::cout << std::endl;
				if (lista.search(temp1) >= 0) {
					lista.add(temp1,1,lista.size() - 1);
					temp2 = graph[lista.size() - 1].min();
					stos.push(temp2);
				}
			}
			lista.print();
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
			for (int i = 0; i < how_many; i++) {
				for (int j = 0; j < 2; j++) {
					temp1 = static_cast<int>(rand()) % how_many;
					graph.addEdge(i, temp1);
				}
			}
		}
	};

#endif  // LAB08_25_04_PRJ_INC_GRAPHDFS_H_