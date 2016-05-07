// Copyright 2016 Kamil Kuczaj
#ifndef LAB08_25_04_PRJ_INC_GRAPHBFS_H_
#define LAB08_25_04_PRJ_INC_GRAPHBFS_H_

#include "IRunnable.h"
#include "Graph.h"
#include "Kolejka.h"

class GraphBFS : IRunnable {
private:
	/*! \brief Testowany graf.
	 *
	 * \details W celu dalszych informacji na temat tego pola prosze
	 *              odwolac sie do klasy Graph.
	 */
	Graph graph;
	Kolejka<int> kolejka;
};

#endif  // LAB08_25_04_PRJ_INC_GRAPHBFS_H_