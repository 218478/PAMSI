// Copyright 2016 Kamil Kuczaj
#include "Sedzia.h"
#include "Stoper.h"
#include "BinaryTree_test.h"

#include <unistd.h>  // to make Linux wait because searching is too fast


#include <sstream>   // to convert int to string
#include <string>    // to deal with strings
#include <iostream>  // to display messages


void Sedzia::setOffBinaryTree(int& how_many, int& trials_count) {
  Stoper timer;
  BinaryTree_test tree;

  std::ostringstream ss;
  ss << "BinaryTree_" << how_many;

  tree.prepare(how_many);

  for (int i = 0; i < trials_count; i++) {
    timer.start();
    tree.run();
    timer.stop();
    if (tree.found())
      timer.dumpToFile(ss.str());    
  }
  // tree.deleteOneLastTime();
}
