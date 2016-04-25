// Copyright 2016 Kamil Kuczaj
#include "Lista_test.h"

#include <fstream>   // to deal with file streams
#include <cstdlib>   // to generate random numbers
#include <iostream>  // to display messages in the console
#include <string>    // to deal with string words

void Lista_test::run() {
    std::string random_word = getRandomWordFromTheDict();
    try {
      int result = list.search(random_word);
      
      switch (result) {
        case -2:
          std::cout << "! ERROR: couldn't find a \"" << random_word
                    << "\" word in a list" << std::endl;
          break;

        case -1:
          std::cout << "List is empty!!!" << std::endl;
          break;

        default:
          std::cout << "Found: " << random_word << " at index: "
                    << result << std::endl;
          break;
      }
    }
    catch (const char *msg) {
      std::cout << msg << std::endl; }
}

void Lista_test::prepare(int desired_size) {
    std::fstream dictionary;
    dictionary.open("109582_English_Words.txt", std::fstream::in);
    try {
      dictionary.exceptions(dictionary.failbit);
    }
    catch(const std::ios_base::failure & ex) {
      std::cerr << "Error! Couldn't find or open a file"
                << ex.what() << std::endl;
    }

    try {
      // read input only if the list is empty and file stream is open
      if (dictionary.is_open()) {
        // http://stackoverflow.com
        // /questions/21647/reading-from-text-file-until-eof-repeats-last-line
        // user Wilhelmtell '08
        std::string word;
        for (int i = 0; i < desired_size; i++) {
          dictionary >> word;
          if (dictionary.eof()) break;
          std::cout << "Rozmiar listy: " << list.size() << std::endl;
          list.add(word, i);
        }
      }

      // for debug
      list.print();
      for (int i = 0 ; i < 10; i++)
        std::cout << "Element o indeksie nr " << i << " to : "
                  << list.get(i) << std:: endl;
      dictionary.close();
    }
    catch (const char* message) {
      std::cout << message << std::endl; }
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
