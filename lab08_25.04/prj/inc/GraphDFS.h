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
	void DFS();
};

#endif  // LAB08_25_04_PRJ_INC_GRAPHDFS_H_