#ifndef BRANCH_BOUND_EXTENDED_LIST_TEST_H_
#define BRANCH_BOUND_EXTENDED_LIST_TEST_H_

#include "Graph.h"
#include "IRunnable.h"

#include <iostream>


class BranchBoundExtendedListTest : IRunnable {
private:
	Graph graph;

public:
	BranchBoundExtendedListTest(int how_many) : graph(how_many) {}

	virtual void prepare(int how_many) {
		// do nothing because prepare was done in a constructor
	}
	virtual void run() {
		
	}
};

#endif  // BRANCH_BOUND_EXTENDED_LIST_TEST_H_