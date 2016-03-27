// Copyright 2016 Kamil Kuczaj
#include "Sedzia.h"
#include "Stoper.h"
#include "Tablica.h"
#include "Lista.h"

#include <iostream>
#include <iomanip>
#include <sstream>   // to convert int to string
#include <string>    // to deal with strings
#include <cstdlib>   // to deal with drawing random word from the dictionary

bool Sedzia::setOffTable(int how_many) {
  Stoper timer;
  Tablica<int> array;

  std::ostringstream ss;
  ss << how_many;

  array.prepare(how_many);
  timer.start();
  array.run();
  timer.stop();

  return true;
}


bool Sedzia::setOffList(int how_many) {
  Lista list;
  Stoper timer;
  uint index_where_word_was_found;

  list.prepare(how_many);
  std::string random_word = getRandomWordFromTheDict(how_many);

  timer.start();
  index_where_word_was_found = list.run(random_word);
  timer.stop();

  std::cout << "Found: " << random_word << " at index: "
            << index_where_word_was_found << " in "
            << how_many << "-sized array" << " in time of: "
            << timer.getElapsedTime() << " miliseconds" << std::endl;

  return true;
}


std::string Sedzia::getRandomWordFromTheDict(int how_many) {
  std::ifstream dictionary;
  std::string word;

  dictionary.open("109582_English_Words.txt", std::fstream::in);

  try {
    dictionary.exceptions(dictionary.failbit);
  }
  catch(const std::ios_base::failure & ex) {
    std::cerr << "Error! Couldn't find or open a file" << ex.what()
              << std::endl;
  }

  // generating random number in 0 to how_many range
  srand(time(NULL));
  int random_number = rand()%how_many;

  if (dictionary.is_open()) {
    // http://stackoverflow.com/questions/21647/reading-from-text-file-until-eof-repeats-last-line
    // user Wilhelmtell '08
    for (int i=0; i < random_number; i++) {
      dictionary >> word;
      if (dictionary.eof()) break;
    }
  }

  dictionary.close();
  return word;
}

