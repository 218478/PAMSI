// Copyright 2016 Kamil Kuczaj

#include "HashTable_test.h"
#include <fstream>
#include <string>
#include <iostream>

void HashTable_test::prepare(int size) {
  std::ifstream input("./dict//phonebook_ex.txt", std::ios::in);
  if (!input.is_open()) {
    std::cerr << "Error reading from the phonebook" << std::endl;
  } else {
    std::string temp1, temp2;
    for (int i = 0; i < size; i++) {
      if (input.eof()) {
        input.close();
        input.clear();  // start reading from the beginning
        input.open("./dict//phonebook_ex.txt", std::ios::in);
      }

      input >> temp1 >> temp2;
      hash_table.put(temp1, std::stoi(temp2));
    }
  }
}

void HashTable_test::run() {
  std::string searched_word = "calclough";  // I chose the word randomly
  hash_table[searched_word];
}
