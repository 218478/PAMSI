// Copyright 2016 Kamil Kuczaj
#include "Lista.h"

#include <string>

Lista::Lista() { head = new Node;  /* memory allocation */ }

Lista::~Lista() {
  Node *conductor1 = head;  // two conductors to avoid memory
  Node *conductor2 = head;  // issues when deleting memory
  // null checking is not needed
  for(int i = 0; i < size(); i++) {
    delete conductor1;  // usuwanie pamieci
    conductor1 = conductor2->getNext();
    conductor2 = conductor1;
  }
}

void Lista::add(std::string item, int n) {
  if (n < size()) {
    Node *inserted = new Node;
    inserted->setElem(item);
    Node *conductor = head;
    if (conductor != 0) {
      // repeating this operation n-times
      for(int i = 0; i < n; i++)
        conductor = conductor->getNext();
      
      inserted->setNext(conductor->getNext());
      conductor->setNext(inserted);
    }
    else
      throw("List is empty");
  }
  else
    throw("Index out of bounds");
}

void Lista::remove(int n) {
  if (n < size()) {
    Node *conductor = head;
    if (conductor != 0) {
      // repeating this operation (n-1)-times
      for(int i = 0; i < n-1; i++)
        conductor = conductor->getNext();
      Node *after_cond = conductor->getNext();  // point to the next element
                                                // which is to be deleted
      conductor->setNext(after_cond->getNext());
      delete after_cond;
    }
    else
      throw("List is empty");
  }
  else
    throw("Index out of bounds");
}

bool Lista::isEmpty() { return (head == 0) ? true : false; }

std::string Lista::get(int n) {
  std::string temp;
  if (n < size()) {
    Node *conductor = head;
    if (conductor != 0) {
      // repeating this operation n-times
      for(int i = 0; i < n; i++)
        conductor = conductor->getNext();
      temp = conductor->getElem();
    }
    else
      throw("List is empty");
  }
  else
    throw("Index out of bounds");
    
  return temp;
}

int Lista::size() {
  Node *conductor = head;
  int temp_size = 0;
  if (conductor != 0) {
    do {
      conductor = conductor->getNext();
      temp_size++;
    } while(conductor->getNext() != 0);
  }
  
  return temp_size;
}

void Lista::print() {
  Node *conductor = head;
  if (conductor != 0) {
    do {
      std::cout << conductor->getElem();
      conductor = conductor->getNext();
    } while(conductor->getNext() != 0);
  }
}

int Lista::search(std::string searched_word) {
  Node *conductor = head;
  int searched_index = 0;
  if (size() == 0) {
     while (conductor->getNext() != 0) {
        if(conductor->getElem() == searched_word)
          return searched_index;
        else
          conductor = conductor->getNext();
        
        if(searched_index < size())
          searched_index++;
        else
          return -2;  // we didn't find anything
    }
  }
  else
    return -1;  // list is empty
}
