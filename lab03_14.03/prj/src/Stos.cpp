// Copyright 2016 Kamil Kuczaj
#include "Stos.h"

Stos::~Stos() {
  while (top != 0)
    pop();
}

void Stos::push(int item) {
  Node* temp = new Node;
  temp->element = item;
  temp->next = top;
  top = temp;
}

int Stos::pop() {
  Node *conductor = top;
  int temp = conductor->element;
  top = conductor->next;
  delete conductor;

  return temp;
}

bool Stos::empty() { return (top == 0) ? true : false; }

int Stos::size() {
  Node *conductor = top;
  int temp_size = 0;
  while (conductor != 0) {
    conductor = conductor->next;
    temp_size++;
  }

  return temp_size;
}

void Stos::print() {
  Node *conductor = top;
  while (conductor != 0) {
    std::cout << conductor->element << std::endl;
    conductor = conductor->next;  // jump to the next element
  }
}
