// Copyright 2016 Kamil Kuczaj
#ifndef LAB06_11_04_PRJ_INC_HASHTABLE_TEST_H_
#define LAB06_11_04_PRJ_INC_HASHTABLE_TEST_H_

#include "HashTable.h"
#include "IRunnable.h"

class HashTable_test : IRunnable {
 private:
  HashTable hash_table;
 public:
  virtual void prepare(int size);

  virtual void run();
};

#endif  // LAB06_11_04_PRJ_INC_HASHTABLE_TEST_H_
