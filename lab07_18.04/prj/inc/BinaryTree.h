// Copyright 2016 Kamil Kuczaj
#ifndef LAB07_18_04_PRJ_INC_BINARYTREE_H_
#define LAB07_18_04_PRJ_INC_BINARYTREE_H_

#include "IBinaryTree.h"
#include "Tablica.h"

/*! \brief Implementacja drzewa binarnego.
 */
template <class Type>
class BinaryTree : IBinaryTree<Type> {
 public:
  virtual void put(Type element) {}

  virtual Type operator[] (Type element) const {}
};


#endif  // LAB07_18_04_PRJ_INC_BINARYTREE_H_
