// Copyright 2016 Kamil Kuczaj
#include "Lista_test.h"

#include <fstream>   // to deal with file streams
#include <cstdlib>   // to generate random numbers
#include <iostream>  // to display messages in the console
#include <string>    // to deal with string words

void Lista_test::run() {
    // std::string random_word = getRandomWordFromTheDict();
    int result = list.search(random_element);
    switch (result) {
      case -2:
        std::cout << "! ERROR: couldn't find a \"" << random_element
                  << "\" word in a list" << std::endl;
        break;

      case -1:
        std::cout << "List is empty!!!" << std::endl;
        break;

      default:
        std::cout << "Found: " << random_element << " at index: "
                  << result << std::endl;
        break;
    }
}

void Lista_test::prepare(int desired_size) {
    // std::fstream dictionary;
    // dictionary.open("109582_English_Words.txt", std::fstream::in);
    // try {
    //   dictionary.exceptions(dictionary.failbit);
    // }
    // catch(const std::ios_base::failure & ex) {
    //   std::cerr << "Error! Couldn't find or open a file"
    //             << ex.what() << std::endl;
    // }

    // // read input only if the list is empty and file stream is open
    // if (dictionary.is_open() && list.isEmpty()) {
    //   // http://stackoverflow.com
    //   // /questions/21647/reading-from-text-file-until-eof-repeats-last-line
    //   // user Wilhelmtell '08
    //   std::string word;
    //   for (int i = 0; i < desired_size; i++) {
    //     dictionary >> word;
    //     if (dictionary.eof()) break;
    //     try {
    //       list.add(word, i); }
    //     catch (const char* message) {
    //       std::cout << message << std::endl; }
    //   }
    // }
    // dictionary.close();
  srand(time(0));
  int random_index = static_cast<int>(rand()) % desired_size;
  for (int i = 0; i < desired_size; i++) {
    list.push_back(static_cast<int>(rand()));
    if (i == random_index)
      random_element = list.get(i);
  }
}

std::string Lista_test::getRandomWordFromTheDict() {
  std::fstream dictionary;
  std::string word;

  dictionary.open("109582_English_Words.txt", std::fstream::in);

  try {
    dictionary.exceptions(dictionary.failbit);
  }
  catch(const std::ios_base::failure & ex) {
    std::cerr << "Error! Couldn't find or open a file" << ex.what()
              << std::endl;
  }

  // generating random number in 0 to 109582-1
  srand(time(NULL));
  int random_number = rand()%(109582-1);

  // stackoverflow.com
  // /questions/21647/reading-from-text-file-until-eof-repeats-last-line
  // user Wilhelmtell '08
  if (dictionary.is_open()) {
    for (int i=0; i < random_number; i++) {
      dictionary >> word;
      if (dictionary.eof()) break;
    }
  }

  dictionary.close();
  return word;
}
