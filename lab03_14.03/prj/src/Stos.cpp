// Copyright 2016 Kamil Kuczaj
#include "Stos.h"

Stos::~Stos() {
  while (!empty()) {
    pop();
  }
}

void Stos::push(int element) {

}


int Stos::pop() {
  
}

bool Stos::empty() { return (top == 0) ? true : false; }
