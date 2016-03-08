#include "Stoper.h"



void Stoper::start() {
  _start = clock();
}

void Stoper::stop() {
  _stop = clock();
}

double Stoper::getElapsedTime() {
  return static_cast<double>(_stop-_start) / CLOCKS_PER_SEC*1000;
}

void Stoper::dumpToFile() {
  my_file.open("tmp_czasy.txt",std::fstream::app | std::fstream::out);
  try {  
    my_file.exceptions(my_file.failbit);
  }
  catch(const std::ios_base::failure& ex) {
    std::cerr << "Error! Couldn't find a file" << ex.what() << std::endl;
  }

  if(my_file.is_open()) {
    my_file << getElapsedTime() << std::endl;
  }
  my_file.close();
}

Stoper::Stoper() {

}

Stoper::~Stoper() {

}
