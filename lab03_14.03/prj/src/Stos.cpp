// Copyright 2016 Kamil Kuczaj
#include "Stos.h"

#include <string>

Stos::Stos(): stack() {}

Stos::~Stos() {
  while (!stack.isEmpty())  // while stack is not empty
    pop();
}

void Stos::push(std::string item) {
  stack.add(item, 0);
}

std::string Stos::pop() {
  return stack.remove(0);
}

bool Stos::empty() { return stack.isEmpty(); }

int Stos::size() {
  return stack.size();
}

void Stos::print() {
  stack.print();
}
