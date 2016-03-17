#include "Tablica.h"

Tablica::Tablica(int x) { elements = new int[x]; current_size = x; index = 0; }

Tablica::~Tablica() { delete [] elements; }

void Tablica::prepare (unsigned int size) { desired_size = size; }

void Tablica::run() {
  while(index < desired_size) {
    if(isFull())
      increaseSize();

    elements[index++] = 123;
  }
}

bool Tablica::isFull() { return ((index >= (current_size)) ? true : false); }

unsigned int Tablica::getSize() { return current_size; }

void Tablica::increaseSize() {
  unsigned int new_size = current_size * 2;
  try {
    int *new_elements = new int[new_size];
    for(unsigned int i=0; i < current_size; i++)
      new_elements[i] = elements[i];

    delete [] elements;
    current_size = new_size;
    elements = new_elements;
  }
  // jezeli nie uda sie przypisac pamieci
  catch (std::bad_alloc& ex) {
    std::cerr << ex.what() << std::endl;
  }

}

 