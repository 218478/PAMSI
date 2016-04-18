// Copyright 2016 Kamil Kuczaj
#include "BinaryTree_test.h"

#include <cstdlib>  // dealing with pseudo random numbers

void BinaryTree_test::prepare(int size) {
  std::srand(time(0));
  tree.put(static_cast<int>(rand()));
}

void BinaryTree_test::run() {}
