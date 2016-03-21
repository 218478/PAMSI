#include "Stoper.h"



void Stoper::start() {
  start_time = clock();
}

void Stoper::stop() {
  stop_time = clock();
}

double Stoper::getElapsedTime() {
  return static_cast<double>(stop_time-start_time) / CLOCKS_PER_SEC*1000;
}

void Stoper::dumpToFile(std::string file_name) {
  file_name += ".csv";

  my_file.open(file_name.c_str(),std::fstream::app | std::fstream::out);
  try {  
    my_file.exceptions(my_file.failbit);
  }
  catch(const std::ios_base::failure& ex) {
    std::cerr << "Error! Couldn't find or open a file" << ex.what() << std::endl;
  }

  if(my_file.is_open()) {
    my_file << getElapsedTime() << ",";
  }
  my_file.close();
}
