// Copyright 2016 Kamil Kuczaj
#include "HashTable.h"

#include <string>
#include <list>       // bo moja lista nie jest jeszcze gotowa
#include <algorithm>  // bo moja lista nie jest jeszcze gotowa

HashTable::HashTable(int no_of_elements) {
  hash_table_size = no_of_elements/100;
  hash_table = new std::list<my_element>[hash_table_size]; }

HashTable::~HashTable() { delete [] hash_table; }

int hashFunction(std::string key) {
  const char *str = key.c_str();
  int hash = 5381;
  int c;

  while (c = *str++)
    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

  return hash;
}

int HashTable::operator[] (std::string key) const {
  // http://stackoverflow.com/questions/589985/vectors-structs-and-stdfind
  std::list<my_element>::iterator findIter
      = std::find_if(hash_table->begin(), hash_table->end(), find_key(key));
}

void HashTable::put(std::string key, int value) {
}

