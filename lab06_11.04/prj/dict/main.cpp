// Copyright 2016 Kamil Kuczaj
//
// This program was used to generate n-word dictionary of shuffled words
// I meant to create a valuable dictionary for testing for the university
// projects, however I noticed such huge files take quite a bit of space.
// That's why the project was dicontinued.
//
// GPLv3 License
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

// random phone number generator:
int myrandom () { return std::rand()%1000000000;}

int main(int argc, char *argv[]) {
  std::srand((unsigned)time(0));

  if (argc > 3) {
    std::ifstream input_file(argv[1]);
    std::ofstream output_file(argv[2]);
    int desired_size = atoi(argv[3]);

    if (!input_file.is_open())
      std::cerr << "Couldnt read source dict (" << argv[1] << ")." << std::endl;

    std::istream_iterator<std::string> start(input_file), end;
    std::vector<std::string> words(start, end);

    int dict_size = static_cast<int>(words.end() - words.begin());
    int no_of_iterations = (desired_size+dict_size)/dict_size;

    for (int i = 0; i < no_of_iterations; i++) {
      std::random_shuffle(words.begin(), words.end());
      for (std::vector<std::string>::iterator it = words.begin();
           it != words.end(); it++)
        output_file << *it << "\t" << myrandom() << std::endl;
    }

    std::cout << "\n\tSuccess generating random words list of "
              << desired_size << " length.\n" << std::endl;

    // ensuring no errors occur
    input_file.close();
    output_file.close();
  } else {
    std::cerr << "Please run the program like this:" << std::endl
              << "./program <source_dict_filename> <shuffled_dict_name> "
              << "<no_of_words_in_shuffled_dict>" <<  std::endl << std::endl;
  }
}
