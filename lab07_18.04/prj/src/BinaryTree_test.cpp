// Copyright 2016 Kamil Kuczaj
#include "BinaryTree_test.h"

#include <cstdlib>  // dealing with pseudo random numbers

void BinaryTree_test::prepare(int size) {
  std::srand(time(0));
  int temp;
  int random_index = static_cast<int>(rand()) % size;
  for (int i = 0; i < size; i++) {
    temp = static_cast<int>(rand())%size-size/2;
    tree.put(temp);
    
    if (i == random_index)
      random_element = temp;
  }
}

void BinaryTree_test::run() {
	if (tree.search(random_element))
		flag = true;
	else
		flag = false;
}
