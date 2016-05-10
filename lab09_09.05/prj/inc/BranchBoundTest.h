#ifndef BRANCH_BOUND_TEST_H_
#define BRANCH_BOUND_TEST_H_

#include "Graph.h"
#include "IRunnable.h"

#include <iostream>


class BranchBoundTest : public IRunnable{
private:
	Graph graph;
	int start, stop;

public:
	BranchBoundTest(int how_many, int x, int y) :
	graph(how_many), start(x), stop(y) {}

	virtual void prepare(int how_many) {
		// do nothing because prepare was done in a constructor
	}
	virtual void run() {
		graph.branchBound(start, stop);
		
	}
};

#endif  // BRANCH_BOUND_TEST_H_