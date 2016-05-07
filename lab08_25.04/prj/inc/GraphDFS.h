// Copyright 2016 Kamil Kuczaj
#ifndef LAB08_25_04_PRJ_INC_GRAPHDFS_H_
#define LAB08_25_04_PRJ_INC_GRAPHDFS_H_

#include "IRunnable.h"
#include "Graph.h"

class GraphDFS : IRunnable {
private:
	/*! \brief Testowany graf.
	 *
	 * \details W celu dalszych informacji na temat tego pola prosze
	 *              odwolac sie do klasy Graph.
	 */
	Graph graph;

public:
	// GraphDFS(int how_many) : graph(how_many) {}
	virtual void run() {}
	virtual void prepare(int how_many) {
		graph.addVertex(0);
		graph.addVertex(1);
		graph.print();
		graph.addEdge(0,1,100);
		//graph.removeVertex(1);
		graph.removeEdge(0,1);
		graph.print();
	// graph.removeEdge(1,2);
	}
};

#endif  // LAB08_25_04_PRJ_INC_GRAPHDFS_H_