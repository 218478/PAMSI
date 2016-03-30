// Copyright 2016 Kamil Kuczaj
#include "Kolejka.h"

#include <string>

void Kolejka::push(std::string element) {
  queue.add(element, 0);
}

std::string Kolejka::pop() {
  return queue.remove(queue.size()-1);  // because we index at 0 not at 1
}

bool Kolejka::empty() { return queue.isEmpty(); }

int Kolejka::size() { return queue.size(); }

void Kolejka::print() { queue.print(); }
