// Copyright 2016 Kamil Kuczaj
#include "Tablica.h"


bool Tablica::isFull() { return ((index >= (current_size)) ?true:false); }


void Tablica::increaseSize() {
    int new_size = current_size * 2;
    try {
      int *new_elements = new int[new_size];
      for (int i=0; i < current_size; i++)
        new_elements[i] = elements[i];

      delete [] elements;
      current_size = new_size;
      elements = new_elements;
    }
    // if you fail to allocate memory
    catch (std::bad_alloc& ex) {
      std::cerr << ex.what() << std::endl;
    }
  }

// x is 10 by default
Tablica::Tablica(int x) {
  elements = new int[x]; current_size = x; index = 0;
}

Tablica::~Tablica() { delete [] elements; }

int Tablica::getSize() { return current_size; }

int Tablica::getDesiredSize() const { return desired_size; }

void Tablica::setDesiredSize(int t) { desired_size = t; }

int Tablica::operator[] (int i) const {
    if (i < current_size)
      return elements[i];
    else
      throw("Index out of bounds");
  }

int& Tablica::operator[] (int i) {
    if (i < current_size) {
      index++;
      return elements[i]; }
    else
      throw("Index out of bounds");
  }

void Tablica::bubbleSort() {
  int temp;
  int n = getSize();

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < (n-i); j++) {
      if (elements[j+1] < elements[j]) {
        temp = elements[j];
        elements[j] = elements[j+1];
        elements[j+1] = temp;
      }
    }
  }
}
