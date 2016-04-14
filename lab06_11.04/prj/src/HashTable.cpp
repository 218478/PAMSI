// Copyright 2016 Kamil Kuczaj
#include "HashTable.h"

#include <string>
#include <list>       // bo moja lista nie jest jeszcze gotowa
#include <algorithm>  // bo moja lista nie jest jeszcze gotowa

HashTable::HashTable(int no_of_elements) {
  hash_table_size = no_of_elements/100;
  hash_table = new std::list<my_element>[hash_table_size]; }

HashTable::~HashTable() { delete [] hash_table; }

int HashTable::hashFunction(const std::string& key) const {
  const char *str = key.c_str();
  int hash = 5381;
  int c;

  while ( (c = *(str++)) )
    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

  return hash;
}

int HashTable::operator[] (std::string key) const {
  int list_no = hashFunction(key);

  // http://stackoverflow.com/questions/589985/vectors-structs-and-stdfind
  std::list<my_element>::iterator find_iter =
      std::find_if(hash_table[list_no].begin(),
                   hash_table[list_no].end(), find_key(key));

  return find_iter->number;
}

void HashTable::put(std::string key, int value) {
}

