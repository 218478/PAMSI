// Copyright 2016 Kamil Kuczaj
#include "Stoper.h"

#include <string>

Stoper::Stoper() {
  start_time = new timeval;
  stop_time = new timeval;
}

Stoper::~Stoper() {
  delete start_time;
  delete stop_time;
}

void Stoper::start() {
  gettimeofday(start_time, NULL);
}

void Stoper::stop() {
  gettimeofday(stop_time, NULL);
}

double Stoper::getElapsedTime() {
  double start, stop;
  start = start_time->tv_sec*1000000+start_time->tv_usec;
  stop = stop_time->tv_sec*1000000+stop_time->tv_usec;
  return stop-start;
}

void Stoper::dumpToFile(std::string file_name) {
  std::ofstream my_file;  // strumien plikow
  file_name += ".csv";

  my_file.open(file_name.c_str(), std::fstream::app | std::fstream::out);
  try {
    my_file.exceptions(my_file.failbit);
  }
  catch(const std::ios_base::failure& ex) {
    std::cerr << "Error! Couldn't find or open a file" << ex.what()
              << std::endl;
  }

  if (my_file.is_open()) {
    my_file << getElapsedTime() << std::endl;
  }
  my_file.close();
}
