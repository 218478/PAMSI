#include <set>
#include <iostream>
#include <cstdlib>

#include <string>
#include <sstream>
#include <fstream>
#include <sys/time.h>

class Stoper {
 private:
  timeval *start_time;
  timeval *stop_time;

 public:
  Stoper();
  ~Stoper();
   void start();
   void stop();
   double getElapsedTime();
   void dumpToFile(std::string file_name);
};
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



void prepare (std::set<int>& tree, int& how_many, int& searched) {
	std::cout << "Preparing " << how_many<<"-sized tree..." << std::endl;
	srand(time(0));
	int temp;
	int random_index = static_cast<int>(rand());
	for (int i = 0; i < how_many; i++) {
		temp = static_cast<int>(rand());
		tree.insert(temp);

		if (i == random_index)
			searched = temp;
	}
}

void run (std::set<int>& tree,int& how_many, int& searched) {
	std::cout << "Running " << how_many<<"-sized tree..." << std::endl;
	tree.find(searched);
}

int main() {
	std::set<int> tree;
	int searched = 0;
	std::ostringstream ss;
	Stoper timer;

	// dziesiec, tysiac, sto tysiecy, milion, milard
	int data_sizes[5]= {10, 1000, 100000, 1000000, 100000000};

	for (int i = 0; i < 5; i++) {
		tree.clear();
		prepare(tree, data_sizes[i], searched);
		
		for (int j = 0; j < 50; j++) {
			ss << "RBTree_" << data_sizes[i];
			timer.start();
			run(tree, data_sizes[i], searched);
			timer.stop();
			timer.dumpToFile(ss.str());
			ss.str("");
			ss.clear();
		}
	}
	
}