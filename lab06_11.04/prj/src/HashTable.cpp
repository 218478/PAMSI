// Copyright 2016 Kamil Kuczaj
#include "HashTable.h"

#include <string>

HashTable::HashTable() { hash_table = new Lista[array_size]; }

HashTable::~HashTable() { delete [] hash_table; }

int HashTable::operator[] (std::string key) const {
  
}

void HashTable::put(std::string key, int value) {
}

