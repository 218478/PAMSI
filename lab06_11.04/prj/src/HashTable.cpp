// Copyright 2016 Kamil Kuczaj
#include "HashTable.h"

#include <string>
#include <list>       // bo moja lista nie jest jeszcze gotowa
#include <algorithm>  // bo moja lista nie jest jeszcze gotowa
#include <iostream>   // to print the contents of the hash table

void HashTable::increaseSize() {
  
}

HashTable::HashTable(int no_of_elements) {
  hash_table_size = no_of_elements/10;
  std::cout << "Size: " << hash_table_size << std::endl;
  hash_table = new std::list<my_element>[hash_table_size]; }

HashTable::~HashTable() { delete [] hash_table; }

unsigned int HashTable::hashFunction(const std::string& key) const {
  const char *str = key.c_str();

  int A = 54059;  // a prime
  int B = 76963;  // another prime
  //  int C = 86969;  // yet another prime

  unsigned h = 31;  // also prime
  while (*str) {
    h = (h * A) ^ (str[0] * B);
    str++;
  }
  return h % hash_table_size;  // because we are limited to the array size
}

int HashTable::operator[] (std::string key) const {
  int list_no = hashFunction(key);

  // http://stackoverflow.com/questions/589985/vectors-structs-and-stdfind
  std::list<my_element>::iterator find_iter =
      std::find_if(hash_table[list_no].begin(),
                   hash_table[list_no].end(), find_key(key));

  std::cout << "Found at bucket no: " << list_no << " at index: "
            << find_iter->number << std::endl;

  return find_iter->number;
}

void HashTable::put(std::string key, int value) {
  my_element temp;
  temp.key = key; temp.number = value;
  int index = hashFunction(key);
  hash_table[index].push_back(temp);
}

void HashTable::print() {
  std::list<my_element>::const_iterator j;
  for (int i = 0; i < hash_table_size; i++) {
    std::cout << "Bucket no " << i << ":" << std::endl;
    for (j = hash_table[i].begin(); j != hash_table[i].end(); j++) {
      my_element temp = *j;
      std::cout << temp.key << "\t" << temp.number << std::endl;
    }
  }
}
